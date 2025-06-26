/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 23:05:28 by hmoukit           #+#    #+#             */
/*   Updated: 2025/05/03 16:18:20 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int ac, char **av)
{
	Zombie *Zombie;

	if (ac != 2)
	{
		std::cout << "the number of arguments is not right!!" << std::endl;
		return (1);
	}
	Zombie = newZombie(av[1]);
	Zombie->annonce();
	randomChump(av[1]);
	delete(Zombie);
}
