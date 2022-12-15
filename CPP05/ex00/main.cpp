/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:19:51 by tonted            #+#    #+#             */
/*   Updated: 2022/12/15 09:58:11 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(){

	Bureaucrat* bur1 = new Bureaucrat(50);

	std::cout << bur1->getName() << " : " << bur1->getGrade() << std::endl;

	bur1->incrementGrade(10);
	std::cout << bur1->getName() << " : " << bur1->getGrade() << std::endl;

	bur1->decrementGrade(50);
	std::cout << bur1->getName() << " : " << bur1->getGrade() << std::endl;

	delete bur1;

	return 0;
}