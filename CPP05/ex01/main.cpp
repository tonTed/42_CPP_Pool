/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:19:51 by tonted            #+#    #+#             */
/*   Updated: 2022/12/16 22:35:15 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <ostream>

int	main(){

	Bureaucrat* bur1 = new Bureaucrat(50, "Pierre");
	Bureaucrat* bur0 = new Bureaucrat(152, "Paul");

	std::cout << bur0->getName() << " : " << bur0->getGrade() << std::endl;
	std::cout << bur1->getName() << " : " << bur1->getGrade() << std::endl;

	bur1->incrementGrade(10);
	std::cout << bur1->getName() << " : " << bur1->getGrade() << std::endl;

	bur1->decrementGrade(90);
	std::cout << bur1->getName() << " : " << bur1->getGrade() << std::endl;

	std::cout << *bur1 << std::endl;
	std::cout << *bur0 << std::endl;

	Form*	form0 = new Form("form0", 130, 137);
	Form*	form1 = new Form("form1", 129, 137);
	Form*	form3 = new Form("form3", 129, 167);

	std::cout << *form0 << std::endl;
	form0->beSigned(*bur1);
	std::cout << *form0 << std::endl;

	std::cout << *form1 << std::endl;
	bur1->signForm(*form1);
	std::cout << *form1 << std::endl;


	delete bur1;
	delete bur0;
	delete form0;
	delete form1;
	delete form3;

	return 0;
}
