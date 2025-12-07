/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 03:27:43 by hmoukit           #+#    #+#             */
/*   Updated: 2025/12/07 13:15:19 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <utility>

class PmergeMe {
private:
    std::vector<int> _vectorData;
    std::deque<int> _dequeData;
    
    // Helper to generate Jacobsthal numbers
    size_t jacobsthal(size_t n) const;
    std::vector<size_t> generateJacobsthalSequence(size_t size) const;
    
    // Vector implementation
    void fordJohnsonSortVector(std::vector<int>& arr);
    void binaryInsertVector(std::vector<int>& arr, int value, size_t end);
    
    // Deque implementation
    void fordJohnsonSortDeque(std::deque<int>& arr);
    void binaryInsertDeque(std::deque<int>& arr, int value, size_t end);
    
    bool isValidNumber(const std::string& str) const;

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    
    bool parseInput(int argc, char** argv);
    void sortVector();
    void sortDeque();
    
    const std::vector<int>& getVector() const;
    const std::deque<int>& getDeque() const;
};

#endif