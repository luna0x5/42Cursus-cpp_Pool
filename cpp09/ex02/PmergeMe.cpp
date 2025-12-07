/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 03:27:40 by hmoukit           #+#    #+#             */
/*   Updated: 2025/12/07 13:14:48 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <algorithm>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vectorData(other._vectorData), _dequeData(other._dequeData) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vectorData = other._vectorData;
        _dequeData = other._dequeData;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isValidNumber(const std::string& str) const {
    if (str.empty())
        return false;
    
    for (size_t i = 0; i < str.length(); i++) {
        if (!isdigit(str[i]))
            return false;
    }
    
    long num = atol(str.c_str());
    if (num < 0 || num > 2147483647)
        return false;
    
    return true;
}

bool PmergeMe::parseInput(int argc, char** argv) {
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        
        if (!isValidNumber(arg)) {
            std::cerr << "Error" << std::endl;
            return false;
        }
        
        int num = atoi(arg.c_str());
        _vectorData.push_back(num);
        _dequeData.push_back(num);
    }
    
    return true;
}

// Generate Jacobsthal number: J(n) = J(n-1) + 2*J(n-2), with J(0)=0, J(1)=1
size_t PmergeMe::jacobsthal(size_t n) const {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    size_t prev2 = 0;
    size_t prev1 = 1;
    size_t result = 0;
    
    for (size_t i = 2; i <= n; i++) {
        result = prev1 + 2 * prev2;
        prev2 = prev1;
        prev1 = result;
    }
    
    return result;
}

// Generate insertion order based on Jacobsthal sequence
std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t size) const {
    std::vector<size_t> insertionOrder;
    
    if (size == 0)
        return insertionOrder;
    
    // Start with b1 (index 0), which is always inserted first
    insertionOrder.push_back(0);
    
    if (size == 1)
        return insertionOrder;
    
    // Generate Jacobsthal numbers and fill gaps backwards
    size_t jacobIndex = 3;
    size_t lastJacob = 1; // We already inserted b1
    
    while (lastJacob < size) {
        size_t currentJacob = jacobsthal(jacobIndex);
        
        if (currentJacob >= size)
            currentJacob = size - 1;
        
        // Insert from currentJacob down to lastJacob + 1
        for (size_t i = currentJacob; i > lastJacob; i--) {
            insertionOrder.push_back(i);
        }
        
        lastJacob = currentJacob;
        jacobIndex++;
        
        if (currentJacob >= size - 1)
            break;
    }
    
    return insertionOrder;
}

// Binary insertion for vector
void PmergeMe::binaryInsertVector(std::vector<int>& arr, int value, size_t end) {
    size_t left = 0;
    size_t right = end;
    
    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (arr[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    
    arr.insert(arr.begin() + left, value);
}

// Ford-Johnson sort for vector
void PmergeMe::fordJohnsonSortVector(std::vector<int>& arr) {
    size_t n = arr.size();
    
    if (n <= 1)
        return;
    
    // Step 1: Create pairs and sort them
    std::vector<std::pair<int, int> > pairs;
    bool hasStraggler = (n % 2 == 1);
    int straggler = hasStraggler ? arr[n - 1] : 0;
    
    for (size_t i = 0; i + 1 < n; i += 2) {
        int first = arr[i];
        int second = arr[i + 1];
        if (first > second)
            pairs.push_back(std::make_pair(first, second));
        else
            pairs.push_back(std::make_pair(second, first));
    }
    
    // Step 2: Recursively sort pairs by their larger element
    // Using simple sort for the pairs (you could recursively call ford-johnson here)
    for (size_t i = 0; i < pairs.size(); i++) {
        for (size_t j = i + 1; j < pairs.size(); j++) {
            if (pairs[i].first > pairs[j].first)
                std::swap(pairs[i], pairs[j]);
        }
    }
    
    // Step 3: Build main chain with larger elements
    std::vector<int> mainChain;
    std::vector<int> pend;
    
    for (size_t i = 0; i < pairs.size(); i++) {
        mainChain.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }
    
    // Insert first pend element (we know b1 < a1)
    if (!pend.empty()) {
        mainChain.insert(mainChain.begin(), pend[0]);
    }
    
    // Generate Jacobsthal insertion order for remaining pend elements
    if (pend.size() > 1) {
        std::vector<size_t> insertionOrder = generateJacobsthalSequence(pend.size() - 1);
        
        for (size_t i = 0; i < insertionOrder.size(); i++) {
            size_t pendIndex = insertionOrder[i] + 1; // +1 because we already inserted pend[0]
            if (pendIndex < pend.size()) {
                // Find position where pend[pendIndex] should be inserted
                // We know it's <= corresponding mainChain element
                size_t searchEnd = pendIndex + i + 1;
                if (searchEnd > mainChain.size())
                    searchEnd = mainChain.size();
                
                binaryInsertVector(mainChain, pend[pendIndex], searchEnd);
            }
        }
    }
    
    // Handle straggler if exists
    if (hasStraggler) {
        binaryInsertVector(mainChain, straggler, mainChain.size());
    }
    
    arr = mainChain;
}

void PmergeMe::sortVector() {
    fordJohnsonSortVector(_vectorData);
}

// Binary insertion for deque
void PmergeMe::binaryInsertDeque(std::deque<int>& arr, int value, size_t end) {
    size_t left = 0;
    size_t right = end;
    
    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (arr[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    
    arr.insert(arr.begin() + left, value);
}

// Ford-Johnson sort for deque
void PmergeMe::fordJohnsonSortDeque(std::deque<int>& arr) {
    size_t n = arr.size();
    
    if (n <= 1)
        return;
    
    // Step 1: Create pairs and sort them
    std::vector<std::pair<int, int> > pairs;
    bool hasStraggler = (n % 2 == 1);
    int straggler = hasStraggler ? arr[n - 1] : 0;
    
    for (size_t i = 0; i + 1 < n; i += 2) {
        int first = arr[i];
        int second = arr[i + 1];
        if (first > second)
            pairs.push_back(std::make_pair(first, second));
        else
            pairs.push_back(std::make_pair(second, first));
    }
    
    // Step 2: Recursively sort pairs by their larger element
    for (size_t i = 0; i < pairs.size(); i++) {
        for (size_t j = i + 1; j < pairs.size(); j++) {
            if (pairs[i].first > pairs[j].first)
                std::swap(pairs[i], pairs[j]);
        }
    }
    
    // Step 3: Build main chain with larger elements
    std::deque<int> mainChain;
    std::vector<int> pend;
    
    for (size_t i = 0; i < pairs.size(); i++) {
        mainChain.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }
    
    // Insert first pend element
    if (!pend.empty()) {
        mainChain.push_front(pend[0]);
    }
    
    // Generate Jacobsthal insertion order
    if (pend.size() > 1) {
        std::vector<size_t> insertionOrder = generateJacobsthalSequence(pend.size() - 1);
        
        for (size_t i = 0; i < insertionOrder.size(); i++) {
            size_t pendIndex = insertionOrder[i] + 1;
            if (pendIndex < pend.size()) {
                size_t searchEnd = pendIndex + i + 1;
                if (searchEnd > mainChain.size())
                    searchEnd = mainChain.size();
                
                binaryInsertDeque(mainChain, pend[pendIndex], searchEnd);
            }
        }
    }
    
    // Handle straggler
    if (hasStraggler) {
        binaryInsertDeque(mainChain, straggler, mainChain.size());
    }
    
    arr = mainChain;
}

void PmergeMe::sortDeque() {
    fordJohnsonSortDeque(_dequeData);
}

const std::vector<int>& PmergeMe::getVector() const {
    return _vectorData;
}

const std::deque<int>& PmergeMe::getDeque() const {
    return _dequeData;
}