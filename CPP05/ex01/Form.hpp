/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:54:55 by tonted            #+#    #+#             */
/*   Updated: 2022/12/16 22:32:47 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <algorithm>
#include <iostream>
#include <istream>
#include <string>
#include <sys/signal.h>

class Form {

public:
	Form(std::string const name, int const gradeSign, int const gradeExec);
	Form(Form const & src);
	~Form(void);

	Form&	operator=(Form const & src);

	std::string	const &	getName(void) const;
	int 		const &	getGradeSign(void) const;
	int 		const &	getGradeExec(void) const;
	bool 		const &	getIsFormSign(void) const;

	void	beSigned(Bureaucrat & bur);

	void	checkGrade(int n);
	int		setGrade(int n);

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

private:
	Form(void);

	std::string const	_name;
	int 		const	_gradeSign;
	int			const	_gradeExec;
	bool				isFormSign;

	static int const MAX_ECHELON = 1;
	static int const MIN_ECHELON = 150;

};

class GradeTooLowException : public std::exception {
		private:
			std::string _msg;
		
		public:
			GradeTooLowException(void) throw();
			~GradeTooLowException() throw();
			GradeTooLowException(std::string &msg) {
				_msg += msg;
			};

			const char* what() const throw();
};

std::ostream&	operator<<(std::ostream& o, Form const & i);