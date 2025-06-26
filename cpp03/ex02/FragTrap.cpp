/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 06:45:35 by hmoukit           #+#    #+#             */
/*   Updated: 2025/05/06 07:13:32 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "FragTrap " << name << " is being named" << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs) 
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
    if (this != &rhs)
		ClapTrap::operator=(rhs);
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
    if (hitPoints == 0)
	{
        std::cout << "FragTrap " << Name << " is too damaged to high five anyone!" << std::endl;
        return ;
    }
    std::cout << "FragTrap " << Name << " enthusiastically requests high fives from everyone! Who's in?" << std::endl;
}
