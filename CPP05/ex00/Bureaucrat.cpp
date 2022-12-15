/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:01:30 by tonted            #+#    #+#             */
/*   Updated: 2022/12/15 08:29:42 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void){};

Bureaucrat::Bureaucrat(int const _grade) : name("default") {
	
	if (_grade < Bureaucrat::MAX_ECHELON)
		std::cout << "MAX" << std::endl;
	else if (_grade > Bureaucrat::MIN_ECHELON)
		std::cout << "MIN" << std::endl;
	else
		this->grade = _grade;
};

Bureaucrat::Bureaucrat(Bureaucrat const & src){ *this = src; };

Bureaucrat::~Bureaucrat(void){};

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const & src){

	if (this != &src){
		this->grade = src.getGrade();
	}

	return *this;
};

std::string const &	Bureaucrat::getName(void) const { return name; };

int const & 		Bureaucrat::getGrade(void) const { return grade; };
