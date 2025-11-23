/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:37:07 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/23 17:37:08 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
    std::srand(std::time(NULL));
    int r = std::rand() % 3;

    switch (r)
	{
        case 0:
            std::cout << "Generated: A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated: B" << std::endl;
            return new B();
        default:
            std::cout << "Generated: C" << std::endl;
            return new C();
    }
}
