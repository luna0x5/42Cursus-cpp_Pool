/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:00:11 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/28 17:17:46 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

void increment(int& n)
{
    n++;
}

int main()
{
    // --- Example 1: int array ---
    const int numbers[] = {1, 2, 3, 4, 5};
    std::cout << "Original int array:" << std::endl;
    iter(numbers, 5, printElement<int>);

    std::cout << "\nAfter increment:" << std::endl;
    // iter(numbers, 5, increment);
    iter(numbers, 5, printElement<int>);

    // --- Example 2: string array ---
    std::string words[] = {"Hello", "World", "CPP07"};
    std::cout << "\nString array:" << std::endl;
    iter(words, 3, printElement<std::string>);

    // --- Example 3: const array ---
    const double decimals[] = {1.1, 2.2, 3.3};
    std::cout << "\nConst double array:" << std::endl;
    iter(decimals, 3, printElement<double>);

    return 0;
}
