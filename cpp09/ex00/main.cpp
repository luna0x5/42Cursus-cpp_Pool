/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 03:27:19 by hmoukit           #+#    #+#             */
/*   Updated: 2025/12/07 11:38:46 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char** argv)
{
    if (argc != 2)
	{
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    
    BitcoinExchange exchange;
    
	// this a check for the db file
    if (!exchange.loadDatabase("data.csv"))
	{
        return 1;
    }
    // this is to check if the file could be open -> yes : open it
    exchange.processInputFile(argv[1]);
    
    return 0;
}