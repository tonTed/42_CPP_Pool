#include "FragTrap.hpp"

FragTrap::FragTrap( void ){};

FragTrap::FragTrap(FragTrap const & src){ *this = src; };

FragTrap::~FragTrap( void ){};

FragTrap &	FragTrap::operator=(FragTrap const & rhs){

	if(this != &rhs){
		
	};
	return (*this);
}

void	FragTrap::highFivesGuys(void) {

	std::string	input;

	std::cout << "gives me five 🖐️";
	std::cin >> input;
	std::cout << std::endl;
}
