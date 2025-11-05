/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 04:40:35 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/05 04:42:18 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExec;

	public:
		/* ---------- Orthodox Canonical Form ---------- */
		AForm();
		AForm(const std::string &name, int gradeToSign, int gradeToExec);
		AForm(const AForm &src);
		AForm &operator=(const AForm &rhs);
		virtual ~AForm();

		/* ---------- Getters ---------- */
		const std::string &getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExec() const;

		/* ---------- Core Logic ---------- */
		void beSigned(const Bureaucrat &b);
		void execute(Bureaucrat const &executor) const; // checks + calls action()

		/* ---------- Pure Virtual Function ---------- */
		virtual void action() const = 0; // implemented by subclasses

		/* ---------- Exception Classes ---------- */
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		class FormNotSignedException : public std::exception {
			public:
				const char* what() const throw();
		};
};

/* ---------- Operator Overload ---------- */
std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif