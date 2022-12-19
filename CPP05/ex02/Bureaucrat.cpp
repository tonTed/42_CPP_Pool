/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:01:30 by tonted            #+#    #+#             */
/*   Updated: 2022/12/17 11:24:25 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <string>

Bureaucrat::Bureaucrat(void){};

Bureaucrat::Bureaucrat(int const _grade, std::string _name) : name(_name) {

	setGrade(_grade);
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

void	Bureaucrat::incrementGrade(int n){ setGrade(grade - n); };

void	Bureaucrat::decrementGrade(int n){ setGrade(grade + n); };

void	Bureaucrat::signForm(AForm & form){ form.beSigned(*this); };

void	Bureaucrat::executeForm(AForm const & form) { 
	
	try{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(...){};
};

void	Bureaucrat::checkGrade(int n){
	if (n < Bureaucrat::MAX_ECHELON){ throw Bureaucrat::GradeTooHighException(); }
	else if (n > Bureaucrat::MIN_ECHELON){ throw Bureaucrat::GradeTooLowException(); }
}

void	Bureaucrat::setGrade(int n){
	
	try {
		Bureaucrat::checkGrade(n);
		grade = n;
	} 
	catch (Bureaucrat::GradeTooHighException& e) { std::cout << e.what() << std::endl; }
	catch (Bureaucrat::GradeTooLowException& e) { std::cout << e.what() << std::endl; }
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
