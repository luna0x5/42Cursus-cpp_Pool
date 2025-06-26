/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 05:51:56 by hmoukit           #+#    #+#             */
/*   Updated: 2025/05/06 05:58:29 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
		ClapTrap robot("CL4P-TP");
		robot.attack("Bandit");
		robot.takeDamage(5);
		robot.beRepaired(3);
		robot.takeDamage(8);
		robot.attack("Skag");
		robot.beRepaired(5);
		ClapTrap energyBot("EN3RGY-TP");
		for (int i = 0; i < 10; i++)
		{
			energyBot.attack("Target Dummy");
		}
		energyBot.attack("Target Dummy");
		energyBot.beRepaired(1);
		ClapTrap copyBot = robot;
		copyBot.takeDamage(1);  // This should show copyBot has 0 hit points already
		return (0);
}
