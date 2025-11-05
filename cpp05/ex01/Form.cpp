/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 23:49:27 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/04 23:12:05 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/* -------------------- Orthodox Canonical Form -------------------- */

Form::Form()
	: _name("DefaultForm"), _isSigned(false), _gradeToSign(150), _gradeToExec(150)
{
	std::cout << "Form::Default constructor called" << std::endl;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExec)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	std::cout << "Form::Parametric constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &src)
	: _name(src._name),
	  _isSigned(src._isSigned),
	  _gradeToSign(src._gradeToSign),
	  _gradeToExec(src._gradeToExec)
{
	std::cout << "Form::Copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &rhs)
{
	std::cout << "Form::Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		// Only _isSigned can change — the rest are const
		this->_isSigned = rhs._isSigned;
	}
	return (*this);
}

Form::~Form()
{
	std::cout << "Form::Destructor called" << std::endl;
}

/* -------------------- Getters -------------------- */

const std::string &Form::getName() const { return _name; }
bool Form::getIsSigned() const { return _isSigned; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExec() const { return _gradeToExec; }

/* -------------------- Core Function -------------------- */

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

/* -------------------- Exception Classes -------------------- */

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form: Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form: Grade too low!";
}

/* -------------------- Operator Overload -------------------- */

std::ostream &operator<<(std::ostream &out, const Form &f)
{
	out << f.getName()
		<< ", form signed: " << std::boolalpha << f.getIsSigned()
		<< ", grade to sign: " << f.getGradeToSign()
		<< ", grade to exec: " << f.getGradeToExec();
	return out;
}
