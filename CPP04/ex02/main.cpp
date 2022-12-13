/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:19:03 by tonted            #+#    #+#             */
/*   Updated: 2022/12/12 22:18:59 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
	AAnimal*	animals[10];

	for (size_t i = 0; i < 10; i++){
		if (i % 2)
			animals[i] = new Cat();
		else 
			animals[i] = new Dog();
	}
	for (size_t i = 0; i < 10; i++){
		delete animals[i];
	}

	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	delete j;
	delete i;

	AAnimal*	nope = new AAnimal();
	
	return (0);
}
