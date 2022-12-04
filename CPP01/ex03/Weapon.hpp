/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:32:58 by tonted            #+#    #+#             */
/*   Updated: 2022/12/04 16:47:43 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Implémentez une classe Weapon (arme) qui possède :
• Un attribut privé type de type string.
• Une fonction membre getType() retournant une référence constante sur type.
• Une fonction membre setType() qui attribue à type la nouvelle valeur passée en
paramètre.
*/

#pragma once

#include <iostream>

class Weapon{

private:
	std::string _type;

public:
	Weapon(std::string type);
	~Weapon();

	std::string	const	&getType() const;
	void				setType(std::string const type);
};

