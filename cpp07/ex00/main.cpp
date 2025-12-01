/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:19:23 by hmoukit           #+#    #+#             */
/*   Updated: 2025/12/01 12:46:26 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void )
{
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    // std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    // std::cout << "min( a, b ) = " << min( a, b ) << std::endl;
    std::cout << "min( a, b ) = " << min<int>( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    // std::cout << "max( a, b ) = " << max<int>( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	
	// std::cout << "max(2, 3.5 ) = " << ::max( 2, 3.5) << std::endl; // will generate an error
	std::cout << "max(2, 3.5 ) = " << max<double>( 2, 3.5) << std::endl; // will not generate an error --> implicit casting
    return (0);
}
