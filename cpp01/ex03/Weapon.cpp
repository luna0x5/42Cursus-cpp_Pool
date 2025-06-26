/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 13:45:35 by hmoukit           #+#    #+#             */
/*   Updated: 2025/05/03 18:17:22 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &newType)
{
	setType(newType);
}

std::string Weapon::getType()
{
	return (Weapon::type);
}

void Weapon::setType(std::string type)
{
	Weapon::type = type;
}
