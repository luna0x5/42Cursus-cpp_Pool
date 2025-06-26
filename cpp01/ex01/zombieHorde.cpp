/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:50:30 by hmoukit           #+#    #+#             */
/*   Updated: 2025/05/03 16:15:42 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *listZombie;
	
	listZombie = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		listZombie[i].setName(name);
	}
	return (listZombie);
}
