#pragma once

#include <iostream>

class ClapTrap{

public:

	ClapTrap(std::string const & name);
	ClapTrap(ClapTrap const & src);
	~ClapTrap(void);

	ClapTrap &	operator=(ClapTrap const & rhs);

	void	attack(std::string const &target);
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

protected:
	ClapTrap(void);

	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;
	std::string 	_name;
	
private:

private:
	
};

std::ostream &	operator<<(std::ostream & o, ClapTrap const & i);