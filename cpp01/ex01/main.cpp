/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:50:10 by hmoukit           #+#    #+#             */
/*   Updated: 2025/05/03 16:58:51 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int ac, char **av)
{
	Zombie *zombies;
	int N;

	if (ac != 3)
	{
		std::cout << "the number of arguments is not right!!" << std::endl;
		return (1);
	}
	N = atoi(av[1]);
	if (!N || N < 0)
	{
		std::cout << "the number of zombies is not right!!" << std::endl;
		return (1);
	}
	zombies = zombieHorde(N, av[2]);
	for (int i = 0; i < N; i++)
	{
		zombies[i].annonce();
	}
	delete[] zombies;
}
