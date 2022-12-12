/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:00:26 by tonted            #+#    #+#             */
/*   Updated: 2022/12/11 20:33:46 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

public:
	FragTrap(void);
	FragTrap(std::string const & name);
	FragTrap(FragTrap const & src);
	~FragTrap(void);

	FragTrap &	operator=(FragTrap const & rhs);

	void	highFivesGuys(void) const;

protected:
	static unsigned int const HIT_POINTS = 100;
	static unsigned int const ENERGY_POINTS = 100;
	static unsigned int const ATTACK_DAMAGE = 30;
};
