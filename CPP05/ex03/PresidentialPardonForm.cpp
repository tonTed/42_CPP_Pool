/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 09:11:14 by tonted            #+#    #+#             */
/*   Updated: 2022/12/19 11:23:35 by tblanco          ###   ########.fr       */
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

void	PresidentialPardonForm::_execute(void) const {
	std::cout << this->getName() << " has been forgiven!" << std::endl;
};
