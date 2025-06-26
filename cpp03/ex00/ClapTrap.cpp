/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 05:24:49 by hmoukit           #+#    #+#             */
/*   Updated: 2025/05/06 05:55:20 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Name("someName"), hitPoints(10), energyPoints(10), attackDamaged(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : Name(name), hitPoints(10), energyPoints(10), attackDamaged(0)
{
	std::cout << name << " is being named" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) : Name(src.Name), hitPoints(src.hitPoints), energyPoints(src.hitPoints), attackDamaged(src.attackDamaged)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		Name = rhs.Name;
		hitPoints = rhs.hitPoints;
		energyPoints = rhs.energyPoints;
		attackDamaged = rhs.attackDamaged;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (!energyPoints)
	{
		std::cout << Name << " has no energy points left to attack!" << std::endl;
		return ;
	}
	if (!hitPoints)
	{
		std::cout << Name << " has no hit points left to attack!" << std::endl;
		return ;
	}
	energyPoints--;
	std::cout << Name << " attacked " << target << " causing " << attackDamaged << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!energyPoints)
	{
		std::cout << Name << " is already out of energy points!" << std::endl;
		return ;
	}
	if (!hitPoints)
	{
		std::cout << Name << " is already out of hit points!" << std::endl;
		return ;
	}
	if (amount >= hitPoints)
		hitPoints = 0;
	else
		hitPoints -= amount;
	std::cout << Name << " takes " << amount << " points of damage! remaining hit points: " << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!energyPoints)
	{
		std::cout << Name << " has no energy points left to repair!" << std::endl;
		return ;
	}
	if (!hitPoints)
	{
		std::cout << Name << " has no hit points left to repair!" << std::endl;
		return ;
	}
	energyPoints--;
	hitPoints += amount;
	std::cout << Name << " repairs itself for " << amount << " hit points! Current hit points: " << hitPoints << std::endl;
}
