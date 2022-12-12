#include "FragTrap.hpp"

FragTrap::FragTrap(void){
	std::cout << "FragTrap " + _name + " has been constructed." << std::endl;
};

FragTrap::FragTrap(FragTrap const & src){ *this = src; };

FragTrap::FragTrap(std::string const & name) : ClapTrap(name) {
	this->_hitPoints = FragTrap::HIT_POINTS;
	this->_energyPoints = FragTrap::ENERGY_POINTS;
	this->_attackDamage = FragTrap::ATTACK_DAMAGE;
	std::cout << "FragTrap " + name + " has been constructed." << std::endl;
};

FragTrap &	FragTrap::operator=(FragTrap const & rhs){
	
	if(this != &rhs){
		std::cout << "FragTrap " + rhs._name + " has been copied." << std::endl;
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage; 
	};
	return (*this);
}

FragTrap::~FragTrap( void ){

	std::cout << "FragTrap " + this->_name + " has been destructed." << std::endl;
};

void	FragTrap::highFivesGuys(void) const {

	std::string	input;

	std::cout << "gives me five 🖐️ :";
	std::getline(std::cin, input);
	if (!input.compare("🖐"))
		std::cout << "Yeah man 🤟" << std::endl;
	else
		std::cout << "😳" << std::endl;
}
