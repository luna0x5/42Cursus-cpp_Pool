/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 23:05:45 by hmoukit           #+#    #+#             */
/*   Updated: 2025/05/03 15:18:45 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << "your Zombie: " << name << ", has been destroyed." << std::endl;
}

void Zombie::setName(std::string name)
{
	Zombie::name = name;
}

void Zombie::annonce()
{
	std::cout << name << ":  BraiiiiiiinnnzzzZ..."<< std::endl;
}
