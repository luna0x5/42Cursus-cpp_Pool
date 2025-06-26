/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:50:32 by hmoukit           #+#    #+#             */
/*   Updated: 2025/04/10 01:39:12 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <cstdlib>
# include <new>

class Zombie {
	private:
		std::string name;
	public:
		Zombie();
		~Zombie();
		void setName(std::string name);
		void annonce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif
