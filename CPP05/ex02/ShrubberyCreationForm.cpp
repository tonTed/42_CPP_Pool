/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 09:11:14 by tonted            #+#    #+#             */
/*   Updated: 2022/12/17 11:08:11 by tonted           ###   ########.fr       */
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

void	ShrubberyCreationForm::execute(Bureaucrat & executor) const {
	try {
		if (!this->getIsFormSign())
			throw (AForm::FormNotSignedException());
		// if (executor.getGrade() > this->getGradeExec()) {
		// 	std::string	ret = executor.getName() +  " couldn’t execute " + this->getName() +
		// 	" because his grade is " + std::to_string(executor.getGrade()) + " and " +
		// 	std::to_string(this->getGradeExec()) + " is necessary.";
		// 	throw (AForm::GradeTooLowException(ret));
		// }

		this->canExecute(executor);

		std::ofstream	outfile(this->getName() + "_shrubbery");
		std::ifstream	infile("ASCII_TREE");

		std::string	tmp;
		while(std::getline(infile, tmp))
			outfile << tmp << std::endl;

		outfile.close();
		infile.close();
	}
	catch (AForm::FormNotSignedException &e) { std::cout << e.what() << std::endl; }
	catch (AForm::GradeTooLowException &e) { std::cout << e.what() << std::endl; }
};
