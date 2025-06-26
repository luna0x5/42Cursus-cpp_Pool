/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 13:45:33 by hmoukit           #+#    #+#             */
/*   Updated: 2025/05/03 18:20:35 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) :
	name(name), weapon(NULL)
{}

void HumanB::setWeapon(Weapon &newWeapon)
{
	weapon = &newWeapon;
}

void HumanB::attack()
{
	if (!weapon)
		std::cout <<name<<" has no Weapon" << std::endl;
	else
		std::cout<<name<<" attacks with their "<< weapon->getType()<<std::endl;
}
