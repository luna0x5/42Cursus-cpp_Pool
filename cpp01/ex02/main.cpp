/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 01:19:37 by hmoukit           #+#    #+#             */
/*   Updated: 2025/04/10 01:31:27 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	std::string brainString = "HI THIS IS BRAIN";
	std::string *stringPTR = &brainString;
	std::string &stringREF = brainString;
	
	std::cout << "The memory address of the string = " << &brainString << std::endl;
	std::cout << "The memory address held by stringPTR = " << &stringPTR << std::endl;
	std::cout << "The memory address held by stringREF = " << &stringREF << std::endl;
	
	std::cout << "The value of the string = " << brainString << std::endl;
	std::cout << "The value of the stringPTR = " << stringPTR << std::endl;
	std::cout << "The value of the stringREF = " << stringREF << std::endl;
}
