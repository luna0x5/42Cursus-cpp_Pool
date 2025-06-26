/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 23:05:47 by hmoukit           #+#    #+#             */
/*   Updated: 2025/05/03 15:19:05 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>
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

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif