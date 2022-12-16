/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:52:34 by tonted            #+#    #+#             */
/*   Updated: 2022/12/15 20:36:07 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <ostream>

class Bureaucrat {

public:
	Bureaucrat(int const grade);
	Bureaucrat(Bureaucrat const & src);
	~Bureaucrat(void);

	Bureaucrat&	operator=(Bureaucrat const & src);

	std::string const &	getName(void) const;
	int const & 		getGrade(void) const;

	void	incrementGrade(int n);
	void	decrementGrade(int n);

	void	checkGrade(int n);

	void	setGrade(int n);

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

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & i);
