/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:49:47 by tonted            #+#    #+#             */
/*   Updated: 2022/12/16 22:30:06 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iterator>
#include <string>

Form::Form(std::string const name, int const gradeSign, int const gradeExec) :
	_name(name), _gradeSign(setGrade(gradeSign)), _gradeExec(setGrade(gradeExec)),
	isFormSign(false){};

Form::Form(Form const & src) : _name(src._name), _gradeSign(src._gradeSign),
	_gradeExec(src._gradeExec), isFormSign(false){};

Form::~Form(void){};

Form&	Form::operator=(Form const & src){
	
	(void) src;

	return *this;
};

std::string const &	Form::getName(void)			const { return _name; };
int 		const &	Form::getGradeSign(void)	const { return _gradeSign;};
int 		const &	Form::getGradeExec(void) 	const { return _gradeExec;};
bool 		const &	Form::getIsFormSign(void)	const { return isFormSign;};

void	Form::beSigned(Bureaucrat & bur){
	try {
		if (bur.getGrade() > getGradeSign()){
			std::string	ret = bur.getName() +  " couldn’t sign " + this->getName() +
			" because his grade is " + std::to_string(bur.getGrade()) + " and " +
			std::to_string(this->getGradeSign()) + " is necessary.";
			throw (GradeTooLowException(ret));
		}
		else
		{
			std::cout << bur.getName() << " signed " << this->getName() << std::endl;
			this->isFormSign = true;
		}
	}
	catch (Form::GradeTooLowException& e) { std::cout << e.what() << std::endl; }
};

void	Form::checkGrade(int n){
	if (n < Form::MAX_ECHELON){ throw Form::GradeTooHighException(); }
	else if (n > Form::MIN_ECHELON){ throw Form::GradeTooLowException(); }
}

int	Form::setGrade(int n){
	
	try {
		Form::checkGrade(n);
		return n;
	} 
	catch (Form::GradeTooHighException& e) { std::cout << e.what() << std::endl; }
	catch (Form::GradeTooLowException& e) { std::cout << e.what() << std::endl; }
	return 0;
}

const char*	Form::GradeTooHighException::what() const throw(){
	
	return "Grade to high!";
}

Form::GradeTooLowException::GradeTooLowException(void) : _msg("Form::GradeTooLowException") {};
Form::GradeTooLowException::GradeTooLowException(std::string &msg) : _msg("Form::GradeTooLowException(" + msg + ")") {};

const char*	Form::GradeTooLowException::what() const throw(){
	
	return this->_msg.c_str();
}

std::ostream&	operator<<(std::ostream& o, Form const & i){

	o << "\nForm: " << i.getName() << std::endl;
	o << "\tGrade for sign form: " << i.getGradeSign() << std::endl;
	o << "\tGrade for exec form: " << i.getGradeExec() << std::endl;
	o << "\tIs form signed? " << i.getIsFormSign() << std::endl;

	return o;
};