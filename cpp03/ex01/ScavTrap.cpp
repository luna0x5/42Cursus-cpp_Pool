/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 06:00:54 by hmoukit           #+#    #+#             */
/*   Updated: 2025/05/06 07:13:57 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << name << " is being named" << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) 
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    if (this != &rhs)
		ClapTrap::operator=(rhs);
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (energyPoints == 0)
	{
        std::cout << "ScavTrap " << Name << " is too drained to attack!" << std::endl;
        return;
    }
    if (hitPoints == 0)
	{
        std::cout << "ScavTrap " << Name << " is too damaged to attack!" << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ScavTrap " << Name << " launches a devastating attack on " << target << ", inflicting " << attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << Name << " is now in Gate keeper mode!" << std::endl;
}
