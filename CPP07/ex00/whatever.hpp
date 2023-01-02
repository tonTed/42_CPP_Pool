/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:31:25 by tblanco           #+#    #+#             */
/*   Updated: 2023/01/02 13:48:45 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void	swap(T &a, T &b){
	T	tmp;
	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T const &	min(T const &a, T const &b){return a < b ? a : b;}

template <typename T>
T const &	max(T const &a, T const &b){return a > b ? a : b;}
