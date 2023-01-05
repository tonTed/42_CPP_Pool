/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:33:00 by tblanco           #+#    #+#             */
/*   Updated: 2023/01/05 10:35:27 by tblanco          ###   ########.fr       */
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
	void	attack(const std::string &target);

private:
	DiamondTrap(void);
	std::string	_name;
};

std::ostream &	operator<<(std::ostream & o, DiamondTrap const & i);