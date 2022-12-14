/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:18:05 by tblanco           #+#    #+#             */
/*   Updated: 2022/12/14 13:16:05 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"

int	main(void){

	ICharacter* me = new Character("me");

	me->equip(new Cure());
	me->equip(new Ice());
	me->use(0, *me);
	me->use(1, *me);

	delete me;

	return 0;
}
