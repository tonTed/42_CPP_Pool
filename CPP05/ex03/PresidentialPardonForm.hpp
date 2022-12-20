/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 09:06:11 by tonted            #+#    #+#             */
/*   Updated: 2022/12/19 11:23:13 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm :  public AForm {

public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(PresidentialPardonForm const & src);
	PresidentialPardonForm(std::string const name);
	~PresidentialPardonForm(void);


	PresidentialPardonForm&	operator=(PresidentialPardonForm const & src);

private:
	void	_execute(void) const;

	static int const	GRADE_FOR_SIGN = 25;
	static int const	GRADE_FOR_EXEC = 5;
};
