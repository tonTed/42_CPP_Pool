/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:21:44 by tblanco           #+#    #+#             */
/*   Updated: 2022/12/14 13:09:39 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {

public:
	Character(std::string const & name);
	Character(Character const & src);
	virtual ~Character(void);

	Character &	operator=(Character const & src);

	std::string const & getName() const;

	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	

protected:
	Character(void);
	AMateria*			inventory[4];

private:
	std::string	_name;

};
