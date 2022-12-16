/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:19:51 by tonted            #+#    #+#             */
/*   Updated: 2022/12/15 10:46:37 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <ostream>

int	main(){

	Bureaucrat* bur1 = new Bureaucrat(50);
	Bureaucrat* bur0 = new Bureaucrat(152);

	std::cout << bur0->getName() << " : " << bur0->getGrade() << std::endl;
	std::cout << bur1->getName() << " : " << bur1->getGrade() << std::endl;

	bur1->incrementGrade(10);
	std::cout << bur1->getName() << " : " << bur1->getGrade() << std::endl;

	bur1->decrementGrade(90);
	std::cout << bur1->getName() << " : " << bur1->getGrade() << std::endl;

	std::cout << *bur1 << std::endl;

	delete bur1;
	delete bur0;

	return 0;
}
