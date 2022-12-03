/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 20:25:07 by tonted            #+#    #+#             */
/*   Updated: 2022/12/03 10:18:14 by tonted           ###   ########.fr       */
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
	
	void		_work(void);
	std::string	_get_input_not_empty(std::string const prefix) const;

	void		_print_header(void) const;
	void		_print_phone_book(void) const;
	void		_print_line(size_t i) const;
	void		_print_cell(std::string s) const;

public:
	PhoneBook(void);
	~PhoneBook(void);
	
	void	add_contact(void);
};

#endif
