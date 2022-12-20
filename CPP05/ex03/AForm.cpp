/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:49:47 by tonted            #+#    #+#             */
/*   Updated: 2022/12/19 11:33:04 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iterator>
#include <string>

AForm::AForm(std::string const name, int const gradeSign, int const gradeExec) :
	_name(name), _gradeSign(setGrade(gradeSign)), _gradeExec(setGrade(gradeExec)),
	isFormSign(false){};

AForm::AForm(AForm const & src) : _name(src._name), _gradeSign(src._gradeSign),
	_gradeExec(src._gradeExec), isFormSign(false){};

AForm::~AForm(void){};

AForm&	AForm::operator=(AForm const & src){
	
	(void) src;

	return *this;
};

std::string const &	AForm::getName(void)			const { return _name; };
int 		const &	AForm::getGradeSign(void)	const { return _gradeSign;};
int 		const &	AForm::getGradeExec(void) 	const { return _gradeExec;};
bool 		const &	AForm::getIsFormSign(void)	const { return isFormSign;};

void	AForm::beSigned(Bureaucrat & bur){
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
	catch (AForm::GradeTooLowException& e) { std::cout << e.what() << std::endl; }
};



void	AForm::checkGrade(int n){
	if (n < AForm::MAX_ECHELON){ throw AForm::GradeTooHighException(); }
	else if (n > AForm::MIN_ECHELON){ throw AForm::GradeTooLowException(); }
}

int	AForm::setGrade(int n){
	
	try {
		AForm::checkGrade(n);
		return n;
	} 
	catch (AForm::GradeTooHighException& e) { std::cout << e.what() << std::endl; }
	catch (AForm::GradeTooLowException& e) { std::cout << e.what() << std::endl; }
	return 0;
}

bool	AForm::canExecute(Bureaucrat const & executor) const {
	
	try {
		if (executor.getGrade() > this->getGradeExec()) {
			std::string	ret = executor.getName() +  " couldn’t execute " + this->getName() +
			" because his grade is " + std::to_string(executor.getGrade()) + " and " +
			std::to_string(this->getGradeExec()) + " is necessary.";
			
			throw (AForm::GradeTooLowException(ret));
		}
	}
	catch(AForm::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
};

bool	AForm::execute(Bureaucrat &executor) const {
	try {
		if (!getIsFormSign()){
			throw (AForm::FormNotSignedException());
		}
		if (executor.getGrade() > this->getGradeExec()){
			std::string	ret = executor.getName() +  " couldn’t execute " + this->getName() +
			" because his grade is " + std::to_string(executor.getGrade()) + " and " +
			std::to_string(this->getGradeExec()) + " is necessary.";
			throw(AForm::GradeTooLowException(ret)); 
		}
		_execute();
		return (true);
	}
	catch (AForm::FormNotSignedException &e) { std::cout << e.what() << std::endl; }
	catch (AForm::GradeTooLowException &e) { std::cout << e.what() << std::endl; }
	return (false);
}

const char*	AForm::FormNotSignedException::what() const throw(){
	
	return "AForm::FormNotSignedException";
}

const char*	AForm::GradeTooHighException::what() const throw(){
	
	return "Grade to high!";
}

AForm::GradeTooLowException::GradeTooLowException(void) : _msg("Form::GradeTooLowException") {};
AForm::GradeTooLowException::GradeTooLowException(std::string &msg) : _msg("Form::GradeTooLowException(" + msg + ")") {};

const char*	AForm::GradeTooLowException::what() const throw(){
	
	return this->_msg.c_str();
}

std::ostream&	operator<<(std::ostream& o, AForm const & i){

	o << "\nForm: " << i.getName() << std::endl;
	o << "\tGrade for sign form: " << i.getGradeSign() << std::endl;
	o << "\tGrade for exec form: " << i.getGradeExec() << std::endl;
	o << "\tIs form signed? " << i.getIsFormSign() << std::endl;

	return o;
};