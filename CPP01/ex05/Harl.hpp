/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:52:20 by tonted            #+#    #+#             */
/*   Updated: 2022/12/24 13:21:50 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>


class Harl{

public:
	Harl();
	~Harl();
	void complain( std::string level );
	
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );


private:
	typedef void(Harl::*ptrf)(void);

	static std::string	_levels[4];
	static ptrf f_levels[4];

};
