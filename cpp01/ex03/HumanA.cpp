/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 13:45:31 by hmoukit           #+#    #+#             */
/*   Updated: 2025/04/12 14:58:23 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) :
	name(name), weapon(weapon)
{}

void HumanA::attack()
{
	std::cout<<HumanA::name<<" attacks with their "<< HumanA::weapon.getType()<<std::endl;
}
