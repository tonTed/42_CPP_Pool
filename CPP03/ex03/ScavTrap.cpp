#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {

	std::cout << "ScavTrap " + this->_name + " has been constructed." << std::endl;
};

ScavTrap::ScavTrap(std::string const & name) : ClapTrap(name) {
	this->_hitPoints = ScavTrap::HIT_POINTS;
	this->_energyPoints = ScavTrap::ENERGY_POINTS;
	this->_attackDamage = ScavTrap::ATTACK_DAMAGE;
	std::cout << "ScavTrap " + name + " has been constructed." << std::endl;
};

ScavTrap::~ScavTrap(void) {

	std::cout << "ScavTrap " + this->_name + " has been destructed." << std::endl;
};

void	ScavTrap::attack(std::string const & target){
	if (this->_hitPoints && this->_energyPoints--)
		std::cout << "ScavTrap " + this->_name + " attacks " + target  + ", causing " << 
		this->_attackDamage <<  " points of damage!" << std::endl;
	else
		std::cout << "ScavTrap " + this->_name + " is dead." << std::endl;
};

void	ScavTrap::guardGate(void) const {

	std::cout << "ScavTrap " << this->_name << " came into Gatekeeper mode" << std::endl;
};

std::ostream &	operator<<(std::ostream & o, ScavTrap const & i){
	o << "\nScavTrap [ " + i.getName() + " ]" << std::endl;
	o << "\t{life: " << i.getHitPoints() << " - Energy: " << i.getEnergyPoints() <<
	" - Damage: " << i.getAttackeDamage() << "}." << std::endl;

	return (o);
};
