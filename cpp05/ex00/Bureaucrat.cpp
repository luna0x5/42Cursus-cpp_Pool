/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 10:54:21 by hmoukit           #+#    #+#             */
/*   Updated: 2025/08/23 12:39:57 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


Bureaucrat::Bureaucrat(void)
{
	std::cout << "Bureaucrat::Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string nameInit, int gradeInit)
{
	grade = gradeInit;
		// if grade < 1 => GRADETOOHIGHEXCEPTION
		// if grade > 150 => GRADETOOLOWEXCEPTION
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	std::cout << "Bureaucrat::Copy constructor called" << std::endl;
    *this = src;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	std::cout << "Bureaucrat::copy assignment operator is called" << std::endl;
	if (this != &rhs)
	{
		// this->name = name;
		*this->grade = grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat::Destructor is called" << std::endl;
}

std::string Bureaucrat::getName(void)
{
	return (name);
}

int Bureaucrat::getGrade(void)
{
	return (grade);
}

void Bureaucrat::incrementGrade(void)
{
	grade--;
	// if grade < 1 => GRADETOOHIGHEXCEPTION
}

void Bureaucrat::decrementGrade(void)
{
	grade++;
	// if grade > 150 => GRADETOOLOWEXCEPTION
}
