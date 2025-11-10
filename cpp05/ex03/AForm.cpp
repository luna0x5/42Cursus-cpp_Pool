/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 04:40:32 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/10 16:11:22 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("DeFaultForm"), isSigned(false), gradeToSign(150), gradeToExec(150)
{
	std::cout << "Form: Default constructor called" << std::endl;
}

AForm::AForm(const std::string &nme, int gradeToS, int gradeToE)
	: name(nme), isSigned(false), gradeToSign(gradeToS), gradeToExec(gradeToE)
{
	std::cout << "Form: Parametric constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExec < 1)
		throw (GradeTooHighException());
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw (GradeTooLowException());
}

AForm::AForm(const AForm &src)
	: name(src.name), isSigned(src.isSigned), gradeToSign(src.gradeToSign), gradeToExec(src.gradeToExec)
{
	std::cout << "Form: Copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &rhs)
{
	std::cout << "Form: Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		isSigned = rhs.isSigned;
	}
	return (*this);
}

AForm::~AForm()
{
	std::cout << "Form::Destructor called" << std::endl;
}

const std::string &AForm::getName() const
{
	return (name);
}

bool AForm::getIsSigned() const
{
	return (isSigned);
}

int AForm::getGradeToSign() const
{
	return (gradeToSign);
}

int AForm::getGradeToExec() const
{
	return (gradeToExec);
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > gradeToExec)
		throw GradeTooLowException();
	this->action();
}

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

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << f.getName()
		<< ", form signed: " << std::boolalpha << f.getIsSigned()
		<< ", grade to sign: " << f.getGradeToSign()
		<< ", grade to exec: " << f.getGradeToExec();
	return out;
}
