/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 04:40:46 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/10 16:17:39 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), target("default")
{
	std::cout << "RobotomyRequestForm::Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &targ)
	: AForm("RobotomyRequestForm", 72, 45), target(targ)
{
	std::cout << "RobotomyRequestForm::Parametric constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm(src), target(src.target)
{
	std::cout << "RobotomyRequestForm::Copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	std::cout << "RobotomyRequestForm::Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->target = rhs.target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm::Destructor called" << std::endl;
}

const std::string &RobotomyRequestForm::getTarget() const
{
	return target;
}

void RobotomyRequestForm::action() const
{
	std::cout << "Bzzzzzzzzz... Vrrrrrrrr... drilling noises..." << std::endl;

	std::srand(std::time(0));

	if (std::rand() % 2)
		std::cout << target << " has been robotomized successfully 🤖!" << std::endl;
	else
		std::cout << "Robotomy failed on " << target << " 💥" << std::endl;
}
