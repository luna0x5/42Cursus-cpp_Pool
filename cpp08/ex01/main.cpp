/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 19:37:00 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/28 23:08:53 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	try
	{
		std::cout << "=== Basic Test ===" << std::endl;
		Span sp(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		// sp.addNumber(42);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Range Test ===" << std::endl;
	try
	{
		Span big(10000);
		std::vector<int> nums;
		for (int i = 0; i < 10000; ++i)
			nums.push_back(i * 2);

		big.addRange(nums.begin(), nums.end());

		std::cout << "Shortest span: " << big.shortestSpan() << std::endl;
		std::cout << "Longest span: " << big.longestSpan() << std::endl;

		// Try overfilling:
		nums.push_back(99999);
		big.addRange(nums.begin(), nums.end());
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}

