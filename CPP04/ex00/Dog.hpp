/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:05:31 by tonted            #+#    #+#             */
/*   Updated: 2022/12/12 21:26:08 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal {

public:
	Dog(void);
	Dog(Dog const & src);
	~Dog(void);

	Dog&	operator=(Dog const & src);

	void	makeSound(void) const;
};
