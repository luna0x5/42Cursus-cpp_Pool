/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 04:40:28 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/05 11:02:56 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

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

	std::cout << "\n----- INTERN TESTS -----" << std::endl;
	Intern intern;

	AForm* form1 = intern.makeForm("shrubbery creation", "Garden");
	AForm* form2 = intern.makeForm("robotomy request", "Marvin");
	AForm* form3 = intern.makeForm("presidential pardon", "Ford Prefect");
	AForm* form4 = intern.makeForm("unknown form", "Nobody"); // invalid

	std::cout << "\n----- Signing and Executing Intern Forms -----" << std::endl;
	if (form1)
	{
		alice.signForm(*form1);
		alice.executeForm(*form1);
		delete form1;
	}
	if (form2)
	{
		bob.signForm(*form2);
		bob.executeForm(*form2);
		delete form2;
	}
	if (form3)
	{
		alice.signForm(*form3);
		alice.executeForm(*form3);
		delete form3;
	}
	delete form4; // safe to delete NULL

	std::cout << "\n----- Summary: ex03 complete ✅ -----" << std::endl;
	return 0;
}

