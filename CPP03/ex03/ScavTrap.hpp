#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

public:
	~ScavTrap( void );
	ScavTrap(std::string name);

	void	attack(std::string target);
	void	guardGate( void );

protected:
	ScavTrap( void );
	
};

std::ostream &	operator<<(std::ostream & o, ScavTrap const & i);