/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 09:11:14 by tonted            #+#    #+#             */
/*   Updated: 2022/12/17 10:14:40 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("default",
	RobotomyRequestForm::GRADE_FOR_SIGN, RobotomyRequestForm::GRADE_FOR_EXEC){};

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) :
	AForm(src.getName(), RobotomyRequestForm::GRADE_FOR_SIGN,
		RobotomyRequestForm::GRADE_FOR_EXEC){};

RobotomyRequestForm::RobotomyRequestForm(std::string const name) : AForm(name,
	RobotomyRequestForm::GRADE_FOR_SIGN, RobotomyRequestForm::GRADE_FOR_EXEC){};

RobotomyRequestForm::~RobotomyRequestForm(void){};

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const & src){
	(void) src;

	return *this;
};

void	RobotomyRequestForm::_execute(void) const {

	if (std::time(NULL) % 2)
		std::cout << this->getName() << " has been robotomized!" << std::endl;
	else
		std::cout << "robotization for "<< this->getName() <<" failed!" << std::endl;
};
