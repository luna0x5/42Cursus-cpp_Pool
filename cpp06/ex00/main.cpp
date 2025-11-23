/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:35:43 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/23 17:40:22 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
	{
        std::cerr << "Usage: ./convert <literal>" << std::endl;
        return (1);
    }
    ScalarConverter::convert(av[1]);
    return (0);
}
