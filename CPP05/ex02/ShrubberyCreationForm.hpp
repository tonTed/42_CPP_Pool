/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 09:06:11 by tonted            #+#    #+#             */
/*   Updated: 2022/12/17 10:56:12 by tonted           ###   ########.fr       */
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

	void	execute(Bureaucrat & executor) const;

	ShrubberyCreationForm&	operator=(ShrubberyCreationForm const & src);

private:

	static int const	GRADE_FOR_SIGN = 145;
	static int const	GRADE_FOR_EXEC = 137;
};