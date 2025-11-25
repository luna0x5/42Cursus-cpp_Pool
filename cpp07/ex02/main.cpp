/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:00:24 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/25 08:43:06 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

// main.cpp
#include "Array.hpp"
#include <iostream>
#include <string>

std::ostream& operator<<(std::ostream& o, const Awesome& a)
{
    o << a.get();
    return o;
}

int main()
{
    try
    {
        std::cout << "=== Test 1: Empty Array ===" << std::endl;
        Array<int> empty;
        std::cout << "Size: " << empty.size() << std::endl;

        std::cout << "\n=== Test 2: Array of ints ===" << std::endl;
        Array<int> numbers(5);
        for (unsigned int i = 0; i < numbers.size(); ++i)
            numbers[i] = i * 10;

        for (unsigned int i = 0; i < numbers.size(); ++i)
            printElem(numbers[i]);
        std::cout << std::endl;

        std::cout << "\n=== Test 3: Deep copy ===" << std::endl;
        Array<int> copy = numbers;
        numbers[0] = 999;
        std::cout << "Original[0]: " << numbers[0] << " | Copy[0]: " << copy[0] << std::endl;

        std::cout << "\n=== Test 4: Strings ===" << std::endl;
        Array<std::string> words(3);
        words[0] = "Hello";
        words[1] = "42";
        words[2] = "Students";
        for (unsigned int i = 0; i < words.size(); ++i)
            printElem(words[i]);
        std::cout << std::endl;

        std::cout << "\n=== Test 5: Awesome class ===" << std::endl;
        Array<Awesome> awesomeArray(5);
        for (unsigned int i = 0; i < awesomeArray.size(); ++i)
            awesomeArray[i].set(i * 7);

        for (unsigned int i = 0; i < awesomeArray.size(); ++i)
            printElem(awesomeArray[i]);
        std::cout << std::endl;

        std::cout << "\n=== Test 6: Out of bounds ===" << std::endl;
        std::cout << awesomeArray[10] << std::endl; // should throw
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}


