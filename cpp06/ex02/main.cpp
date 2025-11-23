/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:37:22 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/23 17:37:23 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
    Base* basePtr = generate();

    std::cout << "\n--- Identification ---" << std::endl;

    std::cout << "Using pointer: ";
    identify(basePtr);

    std::cout << "Using reference: ";
    identify(*basePtr);

    delete basePtr;
    return 0;
}
