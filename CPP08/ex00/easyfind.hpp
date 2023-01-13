/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:31:25 by tblanco           #+#    #+#             */
/*   Updated: 2023/01/13 01:00:17 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>

template <typename T>
void	easyfind(T a, int b){

	typename T::iterator it = std::find(a.begin(), a.end(), b);
	if (a.end() == it)
		throw std::runtime_error("value not found.");
	else
		std::cout << "Element found." << std::endl;;
}


