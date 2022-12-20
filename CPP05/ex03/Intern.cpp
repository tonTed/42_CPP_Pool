/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:48:23 by tonted            #+#    #+#             */
/*   Updated: 2022/12/19 19:47:53 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <algorithm>
#include <cstddef>
#include <sys/_types/_size_t.h>

Intern::Intern(void){};

Intern::Intern(Intern const & src){ (void)src; };

Intern::~Intern(void){};


Intern &	Intern::operator=(Intern const & src){
	(void)src;
	return *this;
};


AForm*	Intern::makeForm(std::string formName, std::string target){

	AForm*	ret;
	
	int	formIndex = -1;
	for (size_t i = 0; i < Intern::forms->length(); i++) {
		if (formName == Intern::forms[i]){
			formIndex = int(i);
			break;
		}
	};

	switch (formIndex) {
		case 0:
			ret = new ShrubberyCreationForm(target);
			break;
		case 1:
			ret = new RobotomyRequestForm(target);
			break;
		case 2:
			ret = new PresidentialPardonForm(target);
			break;
		default:
			std::cout << formName << " do not exists!" << std::endl;
			return NULL;
	}

	std::cout << "Intern creates " << formName << std::endl;

	return ret;
};


std::string const Intern::forms[3] = {"shrubbery request", "robotomy request", "presidential request"};
