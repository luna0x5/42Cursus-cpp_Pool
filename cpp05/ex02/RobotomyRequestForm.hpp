/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 04:40:44 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/05 04:44:51 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>   // for rand()
# include <ctime>     // for seeding randomness

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;

	public:
		/* ---------- Orthodox Canonical Form ---------- */
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
		~RobotomyRequestForm();

		/* ---------- Override ---------- */
		void action() const;

		/* ---------- Getter ---------- */
		const std::string &getTarget() const;
};

#endif
