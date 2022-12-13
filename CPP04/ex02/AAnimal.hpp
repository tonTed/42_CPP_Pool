/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:56:07 by tonted            #+#    #+#             */
/*   Updated: 2022/12/12 22:17:03 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#pragma once

class AAnimal {

public:
	AAnimal(void);
	AAnimal(AAnimal const & src);
	virtual ~AAnimal(void);

	AAnimal&	operator=(AAnimal const & src);

	virtual void	makeSound(void) const = 0;

	std::string const & getType(void) const;

protected:
	std::string	type;
};
