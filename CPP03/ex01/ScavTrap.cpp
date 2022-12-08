#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) {

	std::cout << "ScavTrap " + this->_name + " has been constructed." << std::endl;
};

ScavTrap::~ScavTrap( void ) {

	std::cout << "ScavTrap " + this->_name + " has been destructed." << std::endl;
};

// std::ostream &	operator<<(std::ostream & o, ScavTrap const & i){
// 	//o << i.;
// 	return (o);
// };
