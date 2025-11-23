/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:35:56 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/23 17:40:29 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCON_HPP
# define SCALARCON_HPP

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <cmath>
#include <iomanip>
#include <sstream> 

enum eLiteralType {
    TYPE_CHAR,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_INVALID
};

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &);
		ScalarConverter &operator=(const ScalarConverter &);
		~ScalarConverter();
	public:
		static void convert(std::string const &literal);
};

#endif