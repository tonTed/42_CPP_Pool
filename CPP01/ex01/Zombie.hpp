/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 12:30:14 by tonted            #+#    #+#             */
/*   Updated: 2022/12/04 14:44:07 by tonted           ###   ########.fr       */
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