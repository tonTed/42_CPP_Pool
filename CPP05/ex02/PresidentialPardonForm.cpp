/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 09:11:14 by tonted            #+#    #+#             */
/*   Updated: 2022/12/17 11:14:54 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <string>

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("default",
	PresidentialPardonForm::GRADE_FOR_SIGN, PresidentialPardonForm::GRADE_FOR_EXEC){};

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) :
	AForm(src.getName(), PresidentialPardonForm::GRADE_FOR_SIGN,
		PresidentialPardonForm::GRADE_FOR_EXEC){};

PresidentialPardonForm::PresidentialPardonForm(std::string const name) : AForm(name,
	PresidentialPardonForm::GRADE_FOR_SIGN, PresidentialPardonForm::GRADE_FOR_EXEC){};

PresidentialPardonForm::~PresidentialPardonForm(void){};

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const & src){
	(void) src;

	return *this;
};

void	PresidentialPardonForm::execute(Bureaucrat & executor) const {
	try {
		if (!this->getIsFormSign())
			throw (AForm::FormNotSignedException());
		// if (executor.getGrade() > this->getGradeExec()) {
		// 	std::string	ret = executor.getName() +  " couldn’t execute " + this->getName() +
		// 	" because his grade is " + std::to_string(executor.getGrade()) + " and " +
		// 	std::to_string(this->getGradeExec()) + " is necessary.";
		// 	throw (AForm::GradeTooLowException(ret));
		// }

		this->canExecute(executor);

		std::cout << this->getName() << " has been forgiven!" << std::endl;
	}
	catch (AForm::FormNotSignedException &e) { std::cout << e.what() << std::endl; }
	catch (AForm::GradeTooLowException &e) { std::cout << e.what() << std::endl; }
};
