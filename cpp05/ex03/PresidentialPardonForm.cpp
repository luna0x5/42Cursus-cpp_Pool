/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 04:40:39 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/05 04:46:16 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* -------------------- Orthodox Canonical Form -------------------- */

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), _target("default")
{
	std::cout << "PresidentialPardonForm::Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm::Parametric constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
	: AForm(src), _target(src._target)
{
	std::cout << "PresidentialPardonForm::Copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	std::cout << "PresidentialPardonForm::Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm::Destructor called" << std::endl;
}

/* -------------------- Getter -------------------- */

const std::string &PresidentialPardonForm::getTarget() const
{
	return _target;
}

/* -------------------- Override: action() -------------------- */

void PresidentialPardonForm::action() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
