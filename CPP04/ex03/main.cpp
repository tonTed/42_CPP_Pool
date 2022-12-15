/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:18:05 by tblanco           #+#    #+#             */
/*   Updated: 2022/12/14 21:40:53 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"

int	main(void){

	ICharacter* mee = new Character("mee");

	mee->equip(new Cure());
	mee->equip(new Ice());
	mee->use(0, *mee);
	mee->use(1, *mee);

	delete mee;


	MateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");

	AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);

		tmp = src->createMateria("cure");
		me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);


	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	delete bob;
	delete me;
	delete src;

	return 0;
}
