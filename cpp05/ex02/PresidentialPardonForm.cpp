/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 04:40:39 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/10 16:16:17 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), target("default")
{
	std::cout << "PresidentialPardonForm::Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &targ)
	: AForm("PresidentialPardonForm", 25, 5), target(targ)
{
	std::cout << "PresidentialPardonForm::Parametric constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
	: AForm(src), target(src.target)
{
	std::cout << "PresidentialPardonForm::Copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	std::cout << "PresidentialPardonForm::Copy assignment operator called" << std::endl;
	if (this != &rhs)
		target = rhs.target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm::Destructor called" << std::endl;
}

const std::string &PresidentialPardonForm::getTarget() const
{
	return (target);
}

void PresidentialPardonForm::action() const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
