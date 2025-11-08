/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 04:54:58 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/08 12:52:51 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern::Default constructor called" << std::endl;
}

Intern::Intern(const Intern &src)
{
	(void)src;
	std::cout << "Intern::Copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	std::cout << "Intern::Copy assignment operator called" << std::endl;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern::Destructor called" << std::endl;
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target)
{
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* forms[3] = {
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target)
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << forms[i]->getName() << std::endl;

			// delete other unused forms to avoid memory leaks
			for (int j = 0; j < 3; j++)
				if (j != i)
					delete forms[j];

			return forms[i];
		}
	}

	std::cout << "Intern: unknown form name!" << std::endl;

	// clean up
	for (int i = 0; i < 3; i++)
		delete forms[i];

	return NULL;
}
