/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 04:40:28 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/05 04:51:21 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "----- Creating Bureaucrats -----" << std::endl;
	Bureaucrat alice("Alice", 1);
	Bureaucrat bob("Bob", 50);
	Bureaucrat charlie("Charlie", 140);

	std::cout << alice << std::endl;
	std::cout << bob << std::endl;
	std::cout << charlie << std::endl;

	std::cout << "\n----- Creating Forms -----" << std::endl;
	ShrubberyCreationForm shrub("home");
	RobotomyRequestForm robo("Bender");
	PresidentialPardonForm pardon("Zaphod");

	std::cout << shrub << std::endl;
	std::cout << robo << std::endl;
	std::cout << pardon << std::endl;

	std::cout << "\n----- Signing Forms -----" << std::endl;
	charlie.signForm(shrub);  // too low, should fail
	bob.signForm(shrub);      // should succeed
	bob.signForm(robo);       // should succeed
	bob.signForm(pardon);     // too low, should fail
	alice.signForm(pardon);   // should succeed

	std::cout << "\n----- Executing Forms -----" << std::endl;

	std::cout << "\n🪴 Shrubbery Test:" << std::endl;
	bob.executeForm(shrub);       // should succeed (signed + grade OK)
	charlie.executeForm(shrub);   // fail (too low)

	std::cout << "\n🤖 Robotomy Test:" << std::endl;
	bob.executeForm(robo);        // should succeed randomly (50%)
	charlie.executeForm(robo);    // fail (too low)

	std::cout << "\n🏛️ Presidential Pardon Test:" << std::endl;
	bob.executeForm(pardon);      // fail (too low to exec)
	alice.executeForm(pardon);    // success

	std::cout << "\n----- Summary: all tests done successfully ✅ -----" << std::endl;
	return 0;
}
