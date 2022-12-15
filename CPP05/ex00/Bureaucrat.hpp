/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:52:34 by tonted            #+#    #+#             */
/*   Updated: 2022/12/15 09:01:48 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>

class Bureaucrat {

public:
	Bureaucrat(int const grade);
	Bureaucrat(Bureaucrat const & src);
	~Bureaucrat(void);

	Bureaucrat&	operator=(Bureaucrat const & src);

	std::string const &	getName(void) const;
	int const & 		getGrade(void) const;

	std::string	const	name;
	int					grade;
	
	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
	};

private:
	Bureaucrat(void);
	static int const MAX_ECHELON = 1;
	static int const MIN_ECHELON = 150;

};
