/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:19:51 by tonted            #+#    #+#             */
/*   Updated: 2022/12/19 19:50:24 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <ostream>

int	main(){

	Intern	intern;
	AForm*	form1;
	AForm*	form2;
	AForm*	form3;
	AForm*	form4;

	form1 = intern.makeForm("shrubbery request", "osef1");
	form2 = intern.makeForm("robotomy request", "osef2");
	form3 = intern.makeForm("presidential request", "osef3");
	form4 = intern.makeForm("osef request", "osef4");

	delete form1;
	delete form2;
	delete form3;
	delete form4;

	return 0;
}
