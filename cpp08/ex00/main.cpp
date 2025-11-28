/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:20:37 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/28 19:35:44 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> numbers;
	for (int i = 0; i < 5; i++)
		numbers.push_back(i * 2);
	try
	{
		std::vector<int>::iterator it = easyfind(numbers, 3);
		std::cout << "found : " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::vector<int>::iterator it = easyfind(numbers, 6);
		std::cout << "found : " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
