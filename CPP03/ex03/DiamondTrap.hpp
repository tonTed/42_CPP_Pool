/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:33:00 by tblanco           #+#    #+#             */
/*   Updated: 2022/12/09 13:07:05 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {

public:
	DiamondTrap( std::string name );
	DiamondTrap(DiamondTrap const & src);
	~DiamondTrap( void );

private:
	DiamondTrap( void );
	std::string	_name;

private:
	
};

std::ostream &	operator<<(std::ostream & o, DiamondTrap const & i);