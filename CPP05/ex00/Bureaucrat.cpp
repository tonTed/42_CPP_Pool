/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:01:30 by tonted            #+#    #+#             */
/*   Updated: 2022/12/15 09:04:50 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void){};

Bureaucrat::Bureaucrat(int const _grade) : name("default") {
	
	try {
		if (_grade < Bureaucrat::MAX_ECHELON){

			throw Bureaucrat::GradeTooHighException();
		}
		else if (_grade > Bureaucrat::MIN_ECHELON){

			throw Bureaucrat::GradeTooLowException();
		}
		else {
			grade = _grade;
		}
	} 
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	}
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

const char*	Bureaucrat::GradeTooHighException::what() const throw(){
	
	return "Grade to high!";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw(){
	
	return "Grade to low!";
}
