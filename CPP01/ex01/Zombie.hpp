/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 12:30:14 by tonted            #+#    #+#             */
/*   Updated: 2022/12/24 11:26:50 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie {

private:
	std::string	_name;

public:
	Zombie( std::string name="" );
	~Zombie();

	void	announce( void ) const;
	void	setName(std::string const name);
};

#endif