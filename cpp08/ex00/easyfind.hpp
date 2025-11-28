/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:20:39 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/28 19:34:53 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>

template <typename T>
typename T::iterator easyfind(T &container, int find)
{
	typename T::iterator it = std::find(container.begin(), container.end(), find);
	if (it == container.end())
		throw (std::runtime_error("value not found"));
	return (it);
}
