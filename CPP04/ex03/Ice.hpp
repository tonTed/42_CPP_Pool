/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:14:09 by tblanco           #+#    #+#             */
/*   Updated: 2022/12/14 13:14:23 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {

public:
	Ice(void);
	Ice(Ice const & src);
	~Ice(void);

	Ice & operator=(Ice const & src);

	AMateria*	clone() const;
	void		use(ICharacter& target);

private:

};
