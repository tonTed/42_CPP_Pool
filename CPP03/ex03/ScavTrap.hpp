#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

public:
	~ScavTrap(void);
	ScavTrap(std::string const & name);

	void	attack(std::string const & target);
	void	guardGate(void)const ;

	ScavTrap &	operator=(ScavTrap const & rhs);

protected:
	ScavTrap(void);
	static unsigned int const HIT_POINTS = 100;
	static unsigned int const ENERGY_POINTS = 50;
	static unsigned int const ATTACK_DAMAGE = 20;
};

std::ostream &	operator<<(std::ostream & o, ScavTrap const & i);