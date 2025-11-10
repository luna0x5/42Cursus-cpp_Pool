/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 04:27:14 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/10 16:35:03 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "----- Creating Bureaucrats -----" << std::endl;
	Bureaucrat alice("Alice", 2);
	Bureaucrat bob("Bob", 100);
	Bureaucrat charlie("Charlie", 150);

	std::cout << alice << std::endl;
	std::cout << bob << std::endl;
	std::cout << charlie << std::endl;

	std::cout << "\n----- Creating Valid Forms -----" << std::endl;
	try
	{
		Form tax("TaxForm", 50, 30);
		Form contract("ContractForm", 120, 100);
		std::cout << tax << std::endl;
		std::cout << contract << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n----- Creating Invalid Forms (should throw) -----" << std::endl;
	try
	{
		Form invalidHigh("ImpossibleFormHigh", 0, 50);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		Form invalidLow("ImpossibleFormLow", 151, 100);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n----- Signing Forms -----" << std::endl;
	Form paperwork("Paperwork", 100, 50);
	std::cout << paperwork << std::endl;

	bob.signForm(paperwork);      // should succeed
	std::cout << paperwork << std::endl;

	charlie.signForm(paperwork);  // too low, should fail
	std::cout << paperwork << std::endl;

	alice.signForm(paperwork);    // already signed, but still valid call
	std::cout << paperwork << std::endl;

	std::cout << "\n----- Test BeSigned Directly (exception) -----" << std::endl;
	Form secret("TopSecret", 1, 1);
	try
	{
		charlie.signForm(secret);  // should fail because grade too low
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\nAll tests done successfully" << std::endl;

	return 0;
}
