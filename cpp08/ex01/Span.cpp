/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 19:37:06 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/28 23:05:57 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(0)
{}

Span::Span(unsigned int newN) : N(newN)
{}

Span::Span(const Span &other) : N(other.N)
{}

Span &Span::operator=(const Span &rhs)
{
	if (this != &rhs)
		this->N = rhs.N;
	return (*this);
}

void Span::addNumber(int number)
{
	if (numbers.size() == N)
		throw (std::runtime_error("Span is full"));
	numbers.push_back(number);
}

int Span::shortestSpan()
{
	if (numbers.size() < 2)
		throw (std::runtime_error("there isn't any pairs in Span"));
	std::sort(numbers.begin(), numbers.end());
	int shortest = 2147483647;
	int current = 0;
	std::vector<int>::iterator it = numbers.begin();
	while (it != numbers.end() - 1)
	{
		std::vector<int>::iterator nextit = it + 1;
		current = *nextit - *it;
		if (current < shortest)
			shortest = current;
		it++;
	}
	return (shortest);	
}

int Span::longestSpan()
{
	if (numbers.size() < 2)
		throw (std::runtime_error("there isn't any pairs in Span"));
	std::vector<int>::iterator min = std::min_element(numbers.begin(), numbers.end());
	std::vector<int>::iterator max = std::max_element(numbers.begin(), numbers.end());
	return (*max - *min);
}

void Span::addRange(std::vector<int>::iterator beg, std::vector<int>::iterator end)
{
	unsigned int size = std::distance(beg, end);
	if (size > N - numbers.size())
		throw (std::runtime_error("Span is full"));
	for (std::vector<int>::iterator it = beg; it != end; it++)
		addNumber(*it);
}
