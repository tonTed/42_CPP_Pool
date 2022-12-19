/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:54:55 by tonted            #+#    #+#             */
/*   Updated: 2022/12/19 11:23:02 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <algorithm>
#include <iostream>
#include <istream>
#include <string>
#include <sys/signal.h>

class AForm {

public:
	AForm(std::string const name, int const gradeSign, int const gradeExec);
	AForm(AForm const & src);
	virtual ~AForm(void);

	AForm&	operator=(AForm const & src);

	std::string	const &	getName(void) const;
	int 		const &	getGradeSign(void) const;
	int 		const &	getGradeExec(void) const;
	bool 		const &	getIsFormSign(void) const;

	void	beSigned(Bureaucrat & bur);

	bool	execute(Bureaucrat & bur) const;

	class FormNotSignedException : public std::exception {
		public:
			const char* what() const throw();
	};

	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		private:
			std::string _msg;
		
		public:
			GradeTooLowException(void);
			~GradeTooLowException(void) throw() {};
			GradeTooLowException(std::string &msg);

			const char* what() const throw();
	};

	
protected:
	AForm(void);
	
	virtual void	_execute(void) const = 0;
	bool			canExecute(Bureaucrat const & executor) const;
	void			checkGrade(int n);
	int				setGrade(int n);

private:

	std::string const	_name;
	int 		const	_gradeSign;
	int			const	_gradeExec;
	bool				isFormSign;

	static int const MAX_ECHELON = 1;
	static int const MIN_ECHELON = 150;

};

std::ostream&	operator<<(std::ostream& o, AForm const & i);
