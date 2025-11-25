/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:00:06 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/25 08:29:49 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>
# include <iostream>

template <typename T>
void iter(T* array, const size_t length, void (*func)(T&))
{
    if (!array || !func)
        return;
    for (size_t i = 0; i < length; i++)
        func(array[i]);
}

template <typename T>
void iter(const T* array, const size_t length, void (*func)(const T&))
{
    if (!array || !func)
        return;
    for (size_t i = 0; i < length; i++)
        func(array[i]);
}

template <typename T>
void printElement(const T& element)
{
    std::cout << element << std::endl;
}

#endif
