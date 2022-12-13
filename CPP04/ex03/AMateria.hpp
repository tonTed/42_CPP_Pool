/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:46:08 by tblanco           #+#    #+#             */
/*   Updated: 2022/12/13 17:05:31 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ICharacter.hpp"

class AMateria {

public:
	AMateria(std::string const & type);
	AMateria(AMateria const & src);
	virtual ~AMateria(void);

	AMateria & operator=(AMateria const & src);

	std::string const & getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter & target);

protected:
	AMateria(void);
	std::string	type;

};
