/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:05:31 by tonted            #+#    #+#             */
/*   Updated: 2022/12/12 22:18:52 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {

public:
	Dog(void);
	Dog(Dog const & src);
	~Dog(void);

	Dog&	operator=(Dog const & src);

	void	makeSound(void) const;

private:
	Brain	*_brain;

};
