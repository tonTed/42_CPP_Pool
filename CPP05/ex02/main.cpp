/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:19:51 by tonted            #+#    #+#             */
/*   Updated: 2022/12/19 19:43:45 by tonted           ###   ########.fr       */
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

	Bureaucrat* paul = new Bureaucrat(150, "Paul");
	Bureaucrat* pierre = new Bureaucrat(50, "Pierre");
	Bureaucrat* jack = new Bureaucrat(1, "Jack");

	// sign: 145 | execute: 137
	ShrubberyCreationForm*	Shru = new ShrubberyCreationForm("Shru");

	// sign: 72 | execute: 45
	RobotomyRequestForm*	Robo = new RobotomyRequestForm("Robo");

	// sign: 25 | execute: 5
	PresidentialPardonForm*	Pres = new PresidentialPardonForm("Pres");

	// Paul can't sign
	paul->signForm(*Shru);

	// form is not signed to be executed
	Shru->execute(*paul);

	// form signe by Pierre
	pierre->signForm(*Shru);

	// Paul can't execute
	Shru->execute(*paul);

	// Pierre execute
	Shru->execute(*pierre);

	// Pierre sign
	Robo->beSigned(*pierre);

	// Pierre can't execute
	Robo->execute(*pierre);

	// Jack Execute
	Robo->execute(*jack);

	// the form is not signed to be executed
	Pres->execute(*jack);

	// Pierre can't sign
	Pres->beSigned(*pierre);

	// Jack sign
	jack->signForm(*Pres);

	// Jack execute
	jack->executeForm(*Pres);

	// Paul can't execute
	paul->executeForm(*Pres);


	delete paul;
	delete pierre;
	delete jack;
	delete Shru;
	delete Robo;

	return 0;
}
