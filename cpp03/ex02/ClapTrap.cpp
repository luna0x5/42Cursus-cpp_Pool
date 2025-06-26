/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 05:24:49 by hmoukit           #+#    #+#             */
/*   Updated: 2025/05/06 06:30:25 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Name("someName"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : Name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << name << " is being named" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) : Name(src.Name), hitPoints(src.hitPoints), energyPoints(src.hitPoints), attackDamage(src.attackDamage)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		Name = rhs.Name;
		hitPoints = rhs.hitPoints;
		energyPoints = rhs.energyPoints;
		attackDamage = rhs.attackDamage;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (!energyPoints)
	{
		std::cout << "ClapTrap " << Name << " has no energy points left to attack!" << std::endl;
		return ;
	}
	if (!hitPoints)
	{
		std::cout << "ClapTrap" << Name << " has no hit points left to attack!" << std::endl;
		return ;
	}
	energyPoints--;
	std::cout << "ClapTrap " << Name << " attacked " << target << " causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!energyPoints)
	{
		std::cout << "ClapTrap " << Name << " is already out of energy points!" << std::endl;
		return ;
	}
	if (!hitPoints)
	{
		std::cout << "ClapTrap " << Name << " is already out of hit points!" << std::endl;
		return ;
	}
	if (amount >= hitPoints)
		hitPoints = 0;
	else
		hitPoints -= amount;
	std::cout << "ClapTrap " << Name << " takes " << amount << " points of damage! remaining hit points: " << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!energyPoints)
	{
		std::cout << "ClapTrap " << Name << " has no energy points left to repair!" << std::endl;
		return ;
	}
	if (!hitPoints)
	{
		std::cout << "ClapTrap " << Name << " has no hit points left to repair!" << std::endl;
		return ;
	}
	energyPoints--;
	hitPoints += amount;
	std::cout << "ClapTrap " << Name << " repairs itself for " << amount << " hit points! Current hit points: " << hitPoints << std::endl;
}
