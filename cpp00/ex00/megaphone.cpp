/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:21:19 by hmoukit           #+#    #+#             */
/*   Updated: 2025/04/06 12:54:40 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char    *strupper(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        str[i] = toupper(str[i]);
        i++;
    }
    return (str);
}

int main(int ac, char **av)
{
    int i;

    i = 1;
    if (ac == i)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    while (av[i])
    {
        std::cout << strupper(av[i]) << " ";
        i++;
    }
    std::cout << std::endl;
}
