/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:01:30 by tonted            #+#    #+#             */
/*   Updated: 2022/12/15 20:32:34 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <string>

Bureaucrat::Bureaucrat(void){};

Bureaucrat::Bureaucrat(int const _grade) : name("default") {
	
	try {
		Bureaucrat::checkGrade(_grade);
		grade = _grade;
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

void	Bureaucrat::incrementGrade(int n){
	
	try {
		Bureaucrat::checkGrade(grade - n);
		grade -= n;
	} 
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	}
};

void	Bureaucrat::decrementGrade(int n){
	
	try {
		Bureaucrat::checkGrade(grade + n);
		grade += n;
	} 
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	}
};

void	Bureaucrat::checkGrade(int n){
	if (n < Bureaucrat::MAX_ECHELON){

		throw Bureaucrat::GradeTooHighException();
	}
	else if (n > Bureaucrat::MIN_ECHELON){

		throw Bureaucrat::GradeTooLowException();
	}
}

const char*	Bureaucrat::GradeTooHighException::what() const throw(){
	
	return "Grade to high!";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw(){
	
	return "Grade to low!";
}

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & i){
	
	o << i.getName() << ", bureaucrat grade "<< i.getGrade() << ".";

	return (o);
};
