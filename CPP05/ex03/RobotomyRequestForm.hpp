/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 09:06:11 by tonted            #+#    #+#             */
/*   Updated: 2022/12/17 10:07:13 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class RobotomyRequestForm :  public AForm {

public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(RobotomyRequestForm const & src);
	RobotomyRequestForm(std::string const name);
	~RobotomyRequestForm(void);


	RobotomyRequestForm&	operator=(RobotomyRequestForm const & src);

private:
	void	_execute(void) const ;
	
	static int const	GRADE_FOR_SIGN = 72;
	static int const	GRADE_FOR_EXEC = 45;
};
