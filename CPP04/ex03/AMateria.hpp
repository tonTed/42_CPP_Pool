/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:46:08 by tblanco           #+#    #+#             */
/*   Updated: 2022/12/14 20:33:52 by tonted           ###   ########.fr       */
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
	virtual void use(ICharacter & target) = 0;

protected:
	AMateria(void);
	std::string	type;

};
