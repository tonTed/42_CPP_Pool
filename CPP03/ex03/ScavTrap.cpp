#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) {

	std::cout << "ScavTrap " + this->_name + " has been constructed." << std::endl;
};

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " + name + " has been constructed." << std::endl;
};

ScavTrap::~ScavTrap( void ) {

	std::cout << "ScavTrap " + this->_name + " has been destructed." << std::endl;
};

void	ScavTrap::attack(std::string target){
	if (this->_hitPoints && this->_energyPoints--)
		std::cout << "ScavTrap " + this->_name + " attacks " + target  + ", causing " << 
		this->_attackDamage <<  " points of damage!" << std::endl;
	else
		std::cout << "ScavTrap " + this->_name + " is dead." << std::endl;
};

void	ScavTrap::guardGate( void ) {

	std::cout << "ScavTrap " << this->_name << " came into Gatekeeper mode" << std::endl;
};

std::ostream &	operator<<(std::ostream & o, ScavTrap const & i){
	o << "\nScavTrap [ " + i.getName() + " ]" << std::endl;
	o << "\t{life: " << i.getHitPoints() << " - Energy: " << i.getEnergyPoints() <<
	" - Damage: " << i.getAttackeDamage() << "}." << std::endl;

	return (o);
};
