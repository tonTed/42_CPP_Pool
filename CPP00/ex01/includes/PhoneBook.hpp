/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 20:25:07 by tonted            #+#    #+#             */
/*   Updated: 2022/12/02 20:30:15 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>

#define	ADD "ADD"
#define	SEARCH "SEARCH"
#define	EXIT "EXIT"
#define	EXIT2 "EXIT"

class PhoneBook {

private:
	Contact	_contacts[8];
	int		_i;
	
	void	_work(void);

public:
	PhoneBook(void);
	~PhoneBook(void);
	void	add_contact(void);
};

#endif
