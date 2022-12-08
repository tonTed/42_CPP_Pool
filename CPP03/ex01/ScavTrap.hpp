#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:
	ScavTrap( void );
	~ScavTrap( void );

private:
	
};

std::ostream &	operator<<(std::ostream & o, ScavTrap const & i);