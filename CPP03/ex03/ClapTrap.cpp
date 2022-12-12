#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void){};

ClapTrap::ClapTrap(std::string const & name) : _hitPoints(10), _energyPoints(10), _attackDamage(0), _name(name) {
	std::cout << "ClapTrap " + name + " has been constructed." << std::endl;
};

ClapTrap::ClapTrap(ClapTrap const & src){ *this = src; }; 

ClapTrap::~ClapTrap(void){
	std::cout << "ClapTrap " + this->_name + " has been destructed." << std::endl;
};

ClapTrap &	ClapTrap::operator=(ClapTrap const & rhs){
	
	if(this != &rhs){
		std::cout << "ClapTrap " + rhs._name + " has been copied." << std::endl;
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage; 
	};
	return (*this);
}

void	ClapTrap::attack(std::string const & target){
	if (this->_hitPoints && this->_energyPoints--)
		std::cout << "ClapTrap " + this->_name + " attacks " + target  + ", causing " << 
		this->_attackDamage <<  " points of damage!" << std::endl;
	else
		std::cout << "ClapTrap " + this->_name + " is dead." << std::endl;
};

void	ClapTrap::takeDamage(unsigned int amount){
	
	std::cout << "ClapTrap " + this->_name + " takes " << amount << " damages!" << std::endl;
	if (this->_hitPoints){

		if(this->_hitPoints > amount)
			this->_hitPoints -= amount;
		else{
			std::cout << "ClapTrap " + this->_name + " is dead." << std::endl;
			this->_hitPoints = 0;
		}
	}
};

std::string		ClapTrap::getName() const { return (_name); };
unsigned int	ClapTrap::getHitPoints() const { return (_hitPoints); };
unsigned int	ClapTrap::getEnergyPoints() const { return (_energyPoints); };
unsigned int	ClapTrap::getAttackeDamage() const { return (_attackDamage); };

void	ClapTrap::setName(std::string name) { _name = name; };
void	ClapTrap::setHitPoints(unsigned int amount) { _hitPoints = amount; };
void	ClapTrap::setEnergyPoints(unsigned int amount) { _energyPoints = amount; };
void	ClapTrap::setAttackeDamage(unsigned int amount) { _attackDamage = amount; };

void	ClapTrap::beRepaired(unsigned int amount){

	if (this->_hitPoints && this->_energyPoints--)
		this->_hitPoints += amount;
	else
		std::cout << "ClapTrap " + this->_name + " is dead." << std::endl;
};

std::ostream &	operator<<(std::ostream & o, ClapTrap const & i){
	o << "\nClaptrap [ " + i.getName() + " ]" << std::endl;
	o << "\t{life: " << i.getHitPoints() << " - Energy: " << i.getEnergyPoints() <<
	" - Damage: " << i.getAttackeDamage() << "}." << std::endl;

	return (o);
};
