/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:00:20 by hmoukit           #+#    #+#             */
/*   Updated: 2025/12/01 12:32:01 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>
#include <cstdlib>
#include <ctime>

template <typename T>
class Array
{
private:
    T* _array;
    unsigned int _size;

public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    ~Array();

    Array& operator=(const Array& other);

    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;

    unsigned int size() const;
};

# include "Array.tpp"


//FOR TESTING
///////////////////////////////////////////////////////////////
class Awesome
{
private:
    int _n;
public:
    Awesome(void) : _n(42) {}
    Awesome(int n) : _n(n) {}
    int get() const { return _n; }
    void set(int n) { _n = n; }
};

std::ostream& operator<<(std::ostream& o, const Awesome& a);

template <typename T>
void printElem(const T& x)
{
    std::cout << x << " ";
}
///////////////////////////////////////////////////////////////

#endif
