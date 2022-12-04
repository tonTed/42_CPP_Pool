/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:21:44 by tonted            #+#    #+#             */
/*   Updated: 2022/12/04 18:30:16 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char const *argv[]){
	
	if (argc != 4){
		std::cout << "The program needs 3 arguments (" << argc - 1 << " given)."
		<< std::endl;
	}
	
	(void) argv;
	return 0;
}
