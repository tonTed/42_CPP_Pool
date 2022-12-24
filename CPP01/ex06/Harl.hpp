/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:52:20 by tonted            #+#    #+#             */
/*   Updated: 2022/12/24 13:46:09 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>


class Harl{

public:
	Harl();
	~Harl();
	void complainSwitch( std::string level );
	void complain( std::string level );

private:

	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

	typedef void(Harl::*ptrf)(void);
	static std::string	_levels[4];
	static ptrf	fLevels[4];

};
