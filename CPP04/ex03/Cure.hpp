/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:54:26 by tblanco           #+#    #+#             */
/*   Updated: 2022/12/14 13:09:31 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {

public:
	Cure(void);
	Cure(Cure const & src);
	~Cure(void);

	Cure & operator=(Cure const & src);

	AMateria*	clone() const;
	void		use(ICharacter& target);

private:

};