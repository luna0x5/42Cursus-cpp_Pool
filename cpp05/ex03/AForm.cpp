/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 04:40:32 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/05 04:42:51 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

/* -------------------- Orthodox Canonical Form -------------------- */

AForm::AForm()
	: _name("DefaultForm"), _isSigned(false), _gradeToSign(150), _gradeToExec(150)
{
	std::cout << "AForm::Default constructor called" << std::endl;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExec)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	std::cout << "AForm::Parametric constructor called" << std::endl;
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &src)
	: _name(src._name),
	  _isSigned(src._isSigned),
	  _gradeToSign(src._gradeToSign),
	  _gradeToExec(src._gradeToExec)
{
	std::cout << "AForm::Copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &rhs)
{
	std::cout << "AForm::Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		// Only _isSigned can change — everything else is const
		this->_isSigned = rhs._isSigned;
	}
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm::Destructor called" << std::endl;
}

/* -------------------- Getters -------------------- */

const std::string &AForm::getName() const { return _name; }
bool AForm::getIsSigned() const { return _isSigned; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExec() const { return _gradeToExec; }

/* -------------------- Core Methods -------------------- */

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExec)
		throw GradeTooLowException();
	this->action(); // Call derived class’s behavior
}

/* -------------------- Exception Classes -------------------- */

const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm: Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm: Grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "AForm: The form is not signed!";
}

/* -------------------- Operator Overload -------------------- */

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << f.getName()
		<< ", form signed: " << std::boolalpha << f.getIsSigned()
		<< ", grade to sign: " << f.getGradeToSign()
		<< ", grade to exec: " << f.getGradeToExec();
	return out;
}
