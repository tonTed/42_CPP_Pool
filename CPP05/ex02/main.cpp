/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:19:51 by tonted            #+#    #+#             */
/*   Updated: 2022/12/19 11:26:38 by tblanco          ###   ########.fr       */
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

	ShrubberyCreationForm*	Shru = new ShrubberyCreationForm("Shru");
	RobotomyRequestForm*	Robo = new RobotomyRequestForm("Robo");
	PresidentialPardonForm*	Pres = new PresidentialPardonForm("Pres");

	paul->signForm(*Shru);
	Shru->execute(*paul);
	pierre->signForm(*Shru);
	Shru->execute(*paul);
	Shru->execute(*pierre);

	Robo->beSigned(*pierre);
	Robo->execute(*pierre);
	Robo->execute(*jack);
	Robo->execute(*pierre);

	Pres->execute(*jack);
	Pres->beSigned(*pierre);
	jack->signForm(*Pres);
	jack->executeForm(*Pres);

	paul->executeForm(*Pres);


	delete paul;
	delete pierre;
	delete jack;
	delete Shru;
	delete Robo;

	return 0;
}
