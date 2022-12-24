/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 20:25:07 by tonted            #+#    #+#             */
/*   Updated: 2022/12/24 10:10:33 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip> 
# include <string>

#define	ADD "ADD"
#define	SEARCH "SEARCH"
#define	EXIT "EXIT"

class PhoneBook {

private:
	Contact	_contacts[8];
	int		_i;
	
	/* Helpers */
	std::string	_getInputNotEmpty(std::string const prefix) const;
	bool		_inputSearchValid(std::string input) const;

	/* */
	void		_work(void);

	/* actions */
	void		_addContact(void);
	void		_searchContact(void) const;

	/* outputs */
	void		_printHeader(void) const;
	void		_printPhoneBook(void) const;
	void		_printLine(size_t i) const;
	void		_printCell(std::string s) const;

public:
	PhoneBook(void);
	~PhoneBook(void);
};

#endif
