
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
    TYPE_SPECIAL,
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