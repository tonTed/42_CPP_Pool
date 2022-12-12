/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:33:00 by tblanco           #+#    #+#             */
/*   Updated: 2022/12/11 20:48:59 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {

public:
	DiamondTrap(std::string const & name);
	DiamondTrap(DiamondTrap const & src);
	~DiamondTrap(void);

	DiamondTrap &	operator=(DiamondTrap const & rhs);

	void	whoAmI() const;

private:
	DiamondTrap(void);
	std::string	_name;
};

std::ostream &	operator<<(std::ostream & o, DiamondTrap const & i);