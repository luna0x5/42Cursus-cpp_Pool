/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:00:20 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/25 08:42:30 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>

// template <typename T>
// class Array
// {
// 	private:
// 		T* _array;
// 		unsigned int _size;

// 	public:
// 		Array() : _array(NULL), _size(0) {}
// 		Array(unsigned int n) : _array(new T[n]()), _size(n) {}
// 		Array(const Array& other) : _array(NULL), _size(0)
// 		{
// 			*this = other;
// 		}
// 		~Array()
// 		{
// 			delete[] _array;
// 		}
// 		Array& operator=(const Array& other)
// 		{
// 			if (this != &other)
// 			{
// 				delete[] _array;
// 				_size = other._size;
// 				if (_size > 0)
// 				{
// 					_array = new T[_size];
// 					for (unsigned int i = 0; i < _size; ++i)
// 						_array[i] = other._array[i];
// 				}
// 				else
// 					_array = NULL;
// 			}
// 			return *this;
// 		}
// 		T& operator[](unsigned int index)
// 		{
// 			if (index >= _size)
// 				throw std::out_of_range("Index out of bounds");
// 			return _array[index];
// 		}
// 		const T& operator[](unsigned int index) const
// 		{
// 			if (index >= _size)
// 				throw std::out_of_range("Index out of bounds");
// 			return _array[index];
// 		}
// 		unsigned int size() const
// 		{
// 			return _size;
// 		}
// };

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
