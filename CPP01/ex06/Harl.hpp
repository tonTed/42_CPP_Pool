/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:52:20 by tonted            #+#    #+#             */
/*   Updated: 2022/12/05 10:43:37 by tonted           ###   ########.fr       */
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
	void complain( std::string level );
};

// typedef	void (Harl::*HarlMemFn[])( void );
