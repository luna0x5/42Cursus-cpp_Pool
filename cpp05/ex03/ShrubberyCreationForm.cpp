/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 04:40:49 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/05 04:44:18 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

/* -------------------- Orthodox Canonical Form -------------------- */

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
	std::cout << "ShrubberyCreationForm::Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm::Parametric constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm(src), _target(src._target)
{
	std::cout << "ShrubberyCreationForm::Copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	std::cout << "ShrubberyCreationForm::Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm::Destructor called" << std::endl;
}

/* -------------------- Getter -------------------- */

const std::string &ShrubberyCreationForm::getTarget() const
{
	return _target;
}

/* -------------------- Override: action() -------------------- */

void ShrubberyCreationForm::action() const
{
	std::ofstream outfile((_target + "_shrubbery").c_str());
	if (!outfile)
	{
		std::cerr << "Error: could not create file " << _target + "_shrubbery" << std::endl;
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
	std::cout << "Shrubbery created in " << _target + "_shrubbery" << std::endl;
}
