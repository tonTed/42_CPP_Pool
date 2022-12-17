/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grade.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:21:01 by tonted            #+#    #+#             */
/*   Updated: 2022/12/15 21:46:25 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Grade.hpp"

const char*	Grade::GradeTooHighException::what() const throw(){
	
	return "Grade to high!";
}

const char*	Grade::GradeTooLowException::what() const throw(){
	
	return "Grade to low!";
}

void	Grade::checkGrade(int n){
	if (n < Grade::MAX_ECHELON){
		throw Grade::GradeTooHighException();
	}
	else if (n > Grade::MIN_ECHELON){
		throw Grade::GradeTooLowException();
	}
}

void	Grade::setGrade(int n, int *grade){
	
	try {
		Grade::checkGrade(n);
		*grade = n;
	} 
	catch (Grade::GradeTooHighException& e) { std::cout << e.what() << std::endl; }
	catch (Grade::GradeTooLowException& e) { std::cout << e.what() << std::endl; }
}