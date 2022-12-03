/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 20:46:19 by tonted            #+#    #+#             */
/*   Updated: 2022/12/02 19:22:44 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"

class Contact {

private:
	std::string	_first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;

public:
	Contact();
	~Contact();

	void	set_first_name(std::string first_name);
	void	set_last_name(std::string last_name);
	void	set_nickname(std::string nickname);
	void	set_phone_number(std::string phone_number);
	void	set_darkest_secret(std::string darkest_secret);
};

