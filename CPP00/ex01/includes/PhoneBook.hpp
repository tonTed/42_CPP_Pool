/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 20:25:07 by tonted            #+#    #+#             */
/*   Updated: 2022/12/02 23:09:07 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>

#define	ADD "ADD"
#define	SEARCH "SEARCH"
#define	EXIT "EXIT"

class PhoneBook {

private:
	Contact	_contacts[8];
	int		_i;
	
	void		_work(void);
	std::string	_get_input_not_empty(std::string const prefix) const;

public:
	PhoneBook(void);
	~PhoneBook(void);
	
	void	add_contact(void);
};

#endif
