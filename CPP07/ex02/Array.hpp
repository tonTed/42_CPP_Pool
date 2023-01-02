/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:35:59 by tblanco           #+#    #+#             */
/*   Updated: 2023/01/02 15:45:01 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
class Array {

public:
	Array(void){};
	Array(unsigned int n);
	Array(Array const & src);
	~Array(void);
	
};