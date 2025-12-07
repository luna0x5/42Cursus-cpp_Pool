/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 03:27:40 by hmoukit           #+#    #+#             */
/*   Updated: 2025/12/07 03:32:23 by hmoukit          ###   ########.fr       */
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

// Vector sorting implementation
void PmergeMe::insertionSortVector(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::mergeVector(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);
    
    size_t i = 0, j = 0;
    int k = left;
    
    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }
    
    while (i < leftArr.size()) {
        arr[k++] = leftArr[i++];
    }
    
    while (j < rightArr.size()) {
        arr[k++] = rightArr[j++];
    }
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& arr, int left, int right) {
    if (right - left <= 10) {
        insertionSortVector(arr, left, right);
        return;
    }
    
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeInsertSortVector(arr, left, mid);
        mergeInsertSortVector(arr, mid + 1, right);
        
        mergeVector(arr, left, mid, right);
    }
}

void PmergeMe::sortVector() {
    if (_vectorData.size() <= 1)
        return;
    mergeInsertSortVector(_vectorData, 0, _vectorData.size() - 1);
}

// Deque sorting implementation
void PmergeMe::insertionSortDeque(std::deque<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::mergeDeque(std::deque<int>& arr, int left, int mid, int right) {
    std::deque<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    std::deque<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);
    
    size_t i = 0, j = 0;
    int k = left;
    
    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }
    
    while (i < leftArr.size()) {
        arr[k++] = leftArr[i++];
    }
    
    while (j < rightArr.size()) {
        arr[k++] = rightArr[j++];
    }
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr, int left, int right) {
    if (right - left <= 10) {
        insertionSortDeque(arr, left, right);
        return;
    }
    
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeInsertSortDeque(arr, left, mid);
        mergeInsertSortDeque(arr, mid + 1, right);
        
        mergeDeque(arr, left, mid, right);
    }
}

void PmergeMe::sortDeque() {
    if (_dequeData.size() <= 1)
        return;
    mergeInsertSortDeque(_dequeData, 0, _dequeData.size() - 1);
}

const std::vector<int>& PmergeMe::getVector() const {
    return _vectorData;
}

const std::deque<int>& PmergeMe::getDeque() const {
    return _dequeData;
}