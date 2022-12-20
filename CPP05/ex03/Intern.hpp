/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:33:00 by tonted            #+#    #+#             */
/*   Updated: 2022/12/19 19:44:54 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

class Intern {

public:
	Intern(void);
	Intern(Intern const & src);
	~Intern(void);

	Intern &	operator=(Intern const & src);

	AForm*	makeForm(std::string formName, std::string target);

private:
	static std::string const		forms[3];
};
