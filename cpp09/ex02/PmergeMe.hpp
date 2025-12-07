/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 03:27:43 by hmoukit           #+#    #+#             */
/*   Updated: 2025/12/07 03:32:10 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
private:
    std::vector<int> _vectorData;
    std::deque<int> _dequeData;
    
    // Vector sorting functions
    void mergeInsertSortVector(std::vector<int>& arr, int left, int right);
    void insertionSortVector(std::vector<int>& arr, int left, int right);
    void mergeVector(std::vector<int>& arr, int left, int mid, int right);
    
    // Deque sorting functions
    void mergeInsertSortDeque(std::deque<int>& arr, int left, int right);
    void insertionSortDeque(std::deque<int>& arr, int left, int right);
    void mergeDeque(std::deque<int>& arr, int left, int mid, int right);
    
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