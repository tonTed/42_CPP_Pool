#pragma once

#include <iostream>

class ClapTrap{

public:
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const & src);
	~ClapTrap( void );

	ClapTrap &	operator=(ClapTrap const & rhs);

	void	attack(std::string target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	std::string		getName() const;
	unsigned int	getHitPoints() const;
	unsigned int	getEnergyPoints() const;
	unsigned int	getAttackeDamage() const;

	void	setName(std::string name);
	void	setHitPoints(unsigned int amount);
	void	setEnergyPoints(unsigned int amount);
	void	setAttackeDamage(unsigned int amount);


private:
	ClapTrap( void );
	std::string 	_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;
	
};

std::ostream &	operator<<(std::ostream & o, ClapTrap const & i);
