/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 19:37:06 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/28 22:48:08 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

class Span
{
	private :
		unsigned int N;
		std::vector<int> numbers;
	public :
		Span();
		Span(unsigned int newN);
		Span(const Span &other);
		Span &operator=(const Span &rhs);
		
		void addNumber(int number);
		int shortestSpan();
		int longestSpan();

		void addRange(std::vector<int>::iterator beg, std::vector<int>::iterator end);
};

