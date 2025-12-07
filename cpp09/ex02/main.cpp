/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 03:27:35 by hmoukit           #+#    #+#             */
/*   Updated: 2025/12/07 16:29:13 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

void displaySequence(const std::vector<int>& data, const std::string& label)
{
    std::cout << label;
    size_t displayCount = data.size() > 5 ? 5 : data.size();
    for (size_t i = 0; i < displayCount; i++)
    {
        std::cout << data[i];
        if (i < displayCount - 1)
            std::cout << " ";
    }
    if (data.size() > 5)
        std::cout << " [...]";
    std::cout << std::endl;
}

double getTime(clock_t start, clock_t end)
{
    return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    PmergeMe sorter;
    if (!sorter.parseInput(argc, argv))
        return 1;
    std::vector<int> unsorted = sorter.getVector();
    displaySequence(unsorted, "Before: ");
    // Sort with vector
    clock_t startVector = clock();
    sorter.sortVector();
    clock_t endVector = clock();
    // Sort with deque
    clock_t startDeque = clock();
    sorter.sortDeque();
    clock_t endDeque = clock();
    displaySequence(sorter.getVector(), "After:  ");
    double timeVector = getTime(startVector, endVector);
    double timeDeque = getTime(startDeque, endDeque);
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << unsorted.size() 
              << " elements with std::vector : " << timeVector << " us" << std::endl;
    std::cout << "Time to process a range of " << unsorted.size() 
              << " elements with std::deque  : " << timeDeque << " us" << std::endl;
    return 0;
}