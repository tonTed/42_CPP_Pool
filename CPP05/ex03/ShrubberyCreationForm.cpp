/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 09:11:14 by tonted            #+#    #+#             */
/*   Updated: 2022/12/19 11:24:00 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("default",
	ShrubberyCreationForm::GRADE_FOR_SIGN, ShrubberyCreationForm::GRADE_FOR_EXEC){};

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) :
	AForm(src.getName(), ShrubberyCreationForm::GRADE_FOR_SIGN,
		ShrubberyCreationForm::GRADE_FOR_EXEC){};

ShrubberyCreationForm::ShrubberyCreationForm(std::string const name) : AForm(name,
	ShrubberyCreationForm::GRADE_FOR_SIGN, ShrubberyCreationForm::GRADE_FOR_EXEC){};

ShrubberyCreationForm::~ShrubberyCreationForm(void){};

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src){
	(void) src;

	return *this;
};

void	ShrubberyCreationForm::_execute(void) const {

	std::ofstream	outfile(this->getName() + "_shrubbery");
	std::ifstream	infile("ASCII_TREE");

	std::string	tmp;
	while(std::getline(infile, tmp))
		outfile << tmp << std::endl;

	outfile.close();
	infile.close();
};
