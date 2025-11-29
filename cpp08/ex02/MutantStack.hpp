/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 23:10:54 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/29 11:35:09 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <stack>

template <typename T, class container = std::deque<T> >
class MutantStack : public std::stack<T, container>
{
	public :
		MutantStack(): std::stack<T, container>()
		{}
		MutantStack(const MutantStack& other) : std::stack<T, container>(other)
		{}
		MutantStack& operator=(const MutantStack& rhs)
		{
			if (this != &rhs)
			{
				std::stack<T, container>::operator=(rhs);
			}
			return (*this);
		}
		~MutantStack()
		{}
		
		typedef typename container::iterator iterator;
    	typedef typename container::const_iterator const_iterator;
		typedef typename container::reverse_iterator reverse_iterator;
    	typedef typename container::const_reverse_iterator const_reverse_iterator;

		iterator begin()
		{
			return (this->c.begin());
		}
		iterator end()
		{
			return (this->c.end());
		}
		const_iterator begin() const 
		{
			return (this->c.begin());
		}
		const_iterator end() const
		{
			return (this->c.end());
		}
		reverse_iterator rbegin()
		{
			return (this->c.rbegin());
		}
		reverse_iterator rend()
		{
			return (this->c.rend());
		}
		const_reverse_iterator rbegin() const
		{
			return (this->c.rbegin());
		}
		const_reverse_iterator rend() const
		{
			return (this->c.rend());
		}
};
