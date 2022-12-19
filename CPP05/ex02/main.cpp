/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:19:51 by tonted            #+#    #+#             */
/*   Updated: 2022/12/17 11:24:51 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include <ostream>

int	main(){

	Bureaucrat* bur0 = new Bureaucrat(150, "Paul");
	Bureaucrat* bur1 = new Bureaucrat(50, "Pierre");
	Bureaucrat* bur2 = new Bureaucrat(1, "Jack");

	ShrubberyCreationForm*	form0 = new ShrubberyCreationForm("form0");
	RobotomyRequestForm*	form1 = new RobotomyRequestForm("form1");
	PresidentialPardonForm*	form2 = new PresidentialPardonForm("form2");

	bur0->signForm(*form0);
	form0->execute(*bur0);
	bur1->signForm(*form0);
	form0->execute(*bur0);
	form0->execute(*bur1);

	form1->beSigned(*bur1);
	form1->execute(*bur1);
	form1->execute(*bur2);
	form1->execute(*bur1);

	form2->execute(*bur2);
	form2->beSigned(*bur1);
	bur2->signForm(*form2);
	bur2->executeForm(*form2);

	bur0->executeForm(*form2);


	delete bur0;
	delete bur1;
	delete bur2;
	delete form0;
	delete form1;

	return 0;
}
