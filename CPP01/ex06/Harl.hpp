/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:52:20 by tonted            #+#    #+#             */
/*   Updated: 2022/12/05 11:42:58 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>


class Harl{

private:

	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

	static std::string	_levels[4];

	// static void	(*_f_levels[4])(void);
	// void	(*_f_levels[4])(void);

public:
	Harl();
	~Harl();
	void complainSwitch( std::string level );
	void complain( std::string level );
};

// typedef	void (Harl::*HarlMemFn[])( void );
