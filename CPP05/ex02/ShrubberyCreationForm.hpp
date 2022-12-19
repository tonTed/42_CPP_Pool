/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 09:06:11 by tonted            #+#    #+#             */
/*   Updated: 2022/12/19 11:23:24 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class ShrubberyCreationForm :  public AForm {

public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(ShrubberyCreationForm const & src);
	ShrubberyCreationForm(std::string const name);
	~ShrubberyCreationForm(void);


	ShrubberyCreationForm&	operator=(ShrubberyCreationForm const & src);

private:

	void	_execute(void) const;
	
	static int const	GRADE_FOR_SIGN = 145;
	static int const	GRADE_FOR_EXEC = 137;
};
