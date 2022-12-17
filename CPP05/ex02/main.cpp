/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:19:51 by tonted            #+#    #+#             */
/*   Updated: 2022/12/17 10:15:09 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include <ostream>

int	main(){

	Bureaucrat* bur1 = new Bureaucrat(50, "Pierre");
	Bureaucrat* bur0 = new Bureaucrat(150, "Paul");

	std::cout << bur0->getName() << " : " << bur0->getGrade() << std::endl;
	std::cout << bur1->getName() << " : " << bur1->getGrade() << std::endl;

	bur1->incrementGrade(10);
	std::cout << bur1->getName() << " : " << bur1->getGrade() << std::endl;

	bur1->decrementGrade(90);
	std::cout << bur1->getName() << " : " << bur1->getGrade() << std::endl;

	std::cout << *bur1 << std::endl;
	std::cout << *bur0 << std::endl;

	ShrubberyCreationForm*	form0 = new ShrubberyCreationForm("form0");
	ShrubberyCreationForm*	form1 = new ShrubberyCreationForm("form1");
	ShrubberyCreationForm*	form3 = new ShrubberyCreationForm("form3");

	std::cout << *form0 << std::endl;
	form0->beSigned(*bur1);
	std::cout << *form0 << std::endl;

	std::cout << *form1 << std::endl;
	bur0->signForm(*form1);
	std::cout << *form1 << std::endl;

	std::cout << *form1 << std::endl;
	form0->execute(*bur1);
	std::cout << *form1 << std::endl;

	form3->execute(*bur1);


	delete bur1;
	delete bur0;
	delete form0;
	delete form1;
	delete form3;

	return 0;
}
