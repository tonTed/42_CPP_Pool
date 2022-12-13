/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:56:07 by tonted            #+#    #+#             */
/*   Updated: 2022/12/12 21:33:19 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#pragma once

class WrongAnimal {

public:
	WrongAnimal(void);
	WrongAnimal(WrongAnimal const & src);
	virtual ~WrongAnimal(void);

	WrongAnimal&	operator=(WrongAnimal const & src);

	void	makeSound(void) const;

	std::string const & getType(void) const;

protected:
	std::string	type;
};
