/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 23:49:27 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/10 15:32:20 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("DeFaultForm"), isSigned(false), gradeToSign(150), gradeToExec(150)
{
	std::cout << "Form: Default constructor called" << std::endl;
}

Form::Form(const std::string &nme, int gradeToS, int gradeToE)
	: name(nme), isSigned(false), gradeToSign(gradeToS), gradeToExec(gradeToE)
{
	std::cout << "Form: Parametric constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExec < 1)
		throw (GradeTooHighException());
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw (GradeTooLowException());
}

Form::Form(const Form &src)
	: name(src.name), isSigned(src.isSigned), gradeToSign(src.gradeToSign), gradeToExec(src.gradeToExec)
{
	std::cout << "Form: Copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &rhs)
{
	std::cout << "Form: Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		isSigned = rhs.isSigned;
	}
	return (*this);
}

Form::~Form()
{
	std::cout << "Form::Destructor called" << std::endl;
}

const std::string &Form::getName() const
{
	return (name);
}

bool Form::getIsSigned() const 
{
	return (isSigned);
}
int Form::getGradeToSign() const
{
	return (gradeToSign);
}
int Form::getGradeToExec() const
{
	return (gradeToExec);

}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > gradeToSign)
		throw (GradeTooLowException());
	isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form: Grade too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form: Grade too low!");
}

std::ostream &operator<<(std::ostream &out, const Form &f)
{
	out << f.getName()
		<< ", form signed: " << std::boolalpha << f.getIsSigned()
		<< ", grade to sign: " << f.getGradeToSign()
		<< ", grade to exec: " << f.getGradeToExec();
	return out;
}
