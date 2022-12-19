/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 09:06:11 by tonted            #+#    #+#             */
/*   Updated: 2022/12/17 11:12:47 by tonted           ###   ########.fr       */
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

	void	execute(Bureaucrat & executor) const;

	PresidentialPardonForm&	operator=(PresidentialPardonForm const & src);

private:

	static int const	GRADE_FOR_SIGN = 25;
	static int const	GRADE_FOR_EXEC = 5;
};
