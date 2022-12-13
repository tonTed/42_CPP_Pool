/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:56:07 by tonted            #+#    #+#             */
/*   Updated: 2022/12/12 21:25:44 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#pragma once

class Animal {

public:
	Animal(void);
	Animal(Animal const & src);
	virtual ~Animal(void);

	Animal&	operator=(Animal const & src);

	virtual void	makeSound(void) const;

	std::string const & getType(void) const;

protected:
	std::string	type;
};
