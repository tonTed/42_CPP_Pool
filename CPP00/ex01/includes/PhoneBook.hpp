/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 20:25:07 by tonted            #+#    #+#             */
/*   Updated: 2022/12/02 14:25:56 by tblanco          ###   ########.fr       */
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
	Contact	contacts[8];
	
	void	_work(void);

public:
	PhoneBook(void);
	~PhoneBook(void);
};

#endif
