#include "FragTrap.hpp"

FragTrap::FragTrap( void ){};

FragTrap::FragTrap(FragTrap const & src){ *this = src; };

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " + name + " has been constructed." << std::endl;
};

FragTrap::~FragTrap( void ){

	std::cout << "FragTrap " + this->_name + " has been destructed." << std::endl;
};

void	FragTrap::highFivesGuys(void) {

	std::string	input;

	std::cout << "gives me five 🖐️ :";
	std::getline(std::cin, input);
	if (!input.compare("🖐"))
		std::cout << "Yeah man 🤟" << std::endl;
	else
		std::cout << "😳" << std::endl;
}
