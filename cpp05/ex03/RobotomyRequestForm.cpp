/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 04:40:46 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/08 12:53:57 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << "RobotomyRequestForm::Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm::Parametric constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm(src), _target(src._target)
{
	std::cout << "RobotomyRequestForm::Copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	std::cout << "RobotomyRequestForm::Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm::Destructor called" << std::endl;
}

const std::string &RobotomyRequestForm::getTarget() const
{
	return _target;
}

void RobotomyRequestForm::action() const
{
	std::cout << "Bzzzzzzzzz... Vrrrrrrrr... drilling noises..." << std::endl;

	std::srand(std::time(0));

	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully 🤖!" << std::endl;
	else
		std::cout << "Robotomy failed on " << _target << " 💥" << std::endl;
}
