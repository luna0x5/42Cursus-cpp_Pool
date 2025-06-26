/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 06:00:59 by hmoukit           #+#    #+#             */
/*   Updated: 2025/05/06 06:41:10 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    std::cout << "===== TESTING CLAPTRAP =====" << std::endl;
    ClapTrap robot("CL4P-TP");
    robot.attack("Bandit");
    robot.takeDamage(5);
    robot.beRepaired(3);
    robot.takeDamage(8);
    robot.attack("Skag");
    robot.beRepaired(5);
    ClapTrap energyBot("EN3RGY-TP");
    for (int i = 0; i < 10; i++) {
        energyBot.attack("Target Dummy");
    }
    energyBot.attack("Target Dummy");
    energyBot.beRepaired(1);
    ClapTrap copyBot = robot;
    copyBot.takeDamage(1);  // This should show copyBot has 0 hit points already
	
    std::cout << "\n===== TESTING SCAVTRAP =====" << std::endl;
    ScavTrap scavvy("SC4V-TP");
    scavvy.attack("Super Badass");
    scavvy.takeDamage(30);
    scavvy.beRepaired(15);
    scavvy.guardGate();
    scavvy.takeDamage(85);
    scavvy.attack("Bandit");
    scavvy.guardGate();
    ScavTrap scavCopy = scavvy;
    scavCopy.takeDamage(5);  // This should show scavCopy has 0 hit points already
    std::cout << "\n===== CONSTRUCTION/DESTRUCTION CHAINING DEMONSTRATION =====" << std::endl;
    {
        std::cout << "\nCreating a ScavTrap to demonstrate construction chaining:" << std::endl;
        ScavTrap tempScav("TEMP-SC4V");
        std::cout << "ScavTrap with name TEMP-SC4V is about to be destroyed." << std::endl;
    }
    std::cout << "Notice how destruction happens in reverse order of construction!" << std::endl;
    return 0;
}
