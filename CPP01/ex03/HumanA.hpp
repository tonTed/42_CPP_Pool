/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:00:06 by tonted            #+#    #+#             */
/*   Updated: 2022/12/24 11:59:32 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Weapon.hpp"

class HumanA{

private:
	std::string	const	_name;
	Weapon const &		_weapon;

public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void	attack() const;
};

