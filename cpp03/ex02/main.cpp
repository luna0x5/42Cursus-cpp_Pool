/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 06:45:43 by hmoukit           #+#    #+#             */
/*   Updated: 2025/05/06 07:11:40 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
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
    std::cout << "\n===== TESTING CONSTRUCTION/DESTRUCTION CHAINING =====" << std::endl;
    {
        std::cout << "\nCreating a ScavTrap to demonstrate construction chaining:" << std::endl;
        ScavTrap tempScav("TEMP-SC4V");
        std::cout << "ScavTrap with name TEMP-SC4V is about to be destroyed." << std::endl;
    }
    std::cout << "Notice how destruction happens in reverse order of construction!\n" << std::endl;
    
    std::cout << "===== TESTING FRAGTRAP =====" << std::endl;
    FragTrap fraggy("FR4G-TP");
    fraggy.attack("Super Badass Psycho");
    fraggy.takeDamage(40);
    fraggy.beRepaired(25);
    fraggy.highFivesGuys();
    fraggy.takeDamage(85);
    fraggy.highFivesGuys();
    FragTrap fragCopy = fraggy;
    fragCopy.beRepaired(50);  // This should show fragCopy can be repaired since it has energy
    std::cout << "\n===== FRAGTRAP CONSTRUCTION/DESTRUCTION CHAINING DEMONSTRATION =====" << std::endl;
    {
        std::cout << "\nCreating a FragTrap to demonstrate construction chaining:" << std::endl;
        FragTrap tempFrag("TEMP-FR4G");
        std::cout << "FragTrap with name TEMP-FR4G is about to be destroyed." << std::endl;
    }
    std::cout << "Notice how destruction happens in reverse order of construction!" << std::endl;
    
    std::cout << "\n===== MULTIPLE TYPES DEMONSTRATION =====" << std::endl;
    {
        std::cout << "\nCreating one of each type to compare behaviors:" << std::endl;
        ClapTrap clap("C-DEMO");
        ScavTrap scav("S-DEMO");
        FragTrap frag("F-DEMO");
        
        std::cout << "\nComparing attacks:" << std::endl;
        clap.attack("Target");
        scav.attack("Target");
        frag.attack("Target");
        
        std::cout << "\nComparing special abilities:" << std::endl;
        scav.guardGate();
        frag.highFivesGuys();
        
        std::cout << "\nAll robots will now be destroyed in reverse order of creation." << std::endl;
    }
    return 0;
}