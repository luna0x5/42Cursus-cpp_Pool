/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 04:40:49 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/10 16:18:21 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), target("default")
{
	std::cout << "ShrubberyCreationForm::Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &targ)
	: AForm("ShrubberyCreationForm", 145, 137), target(targ)
{
	std::cout << "ShrubberyCreationForm::Parametric constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm(src), target(src.target)
{
	std::cout << "ShrubberyCreationForm::Copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	std::cout << "ShrubberyCreationForm::Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->target = rhs.target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm::Destructor called" << std::endl;
}

const std::string &ShrubberyCreationForm::getTarget() const
{
	return target;
}

void ShrubberyCreationForm::action() const
{
	std::ofstream outfile((target + "_shrubbery").c_str());
	if (!outfile)
	{
		std::cerr << "Error: could not create file " << target + "_shrubbery" << std::endl;
		return;
	}

	outfile <<
	"       _-_\n"
	"    /~~   ~~\\\n"
	" /~~         ~~\\\n"
	"{               }\n"
	" \\  _-     -_  /\n"
	"   ~  \\\\ //  ~\n"
	"_- -   | | _- _\n"
	"  _ -  | |   -_\n"
	"      // \\\\\n";

	outfile.close();
	std::cout << "Shrubbery created in " << target + "_shrubbery" << std::endl;
}
