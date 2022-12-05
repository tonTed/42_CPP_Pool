/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:21:44 by tonted            #+#    #+#             */
/*   Updated: 2022/12/05 13:38:24 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char const *argv[]){
	
	if (argc != 4){
		std::cout << "The program needs 3 arguments (" << argc - 1 << " given)."
		<< std::endl;
		return (EXIT_FAILURE);
	}
	
	std::ifstream infile(argv[1]);

	if (infile.fail()){
		std::cout << argv[1] << ": can't open file." << std::endl;
		return (EXIT_FAILURE);
	}

	std::ofstream outfile(std::string(argv[1]) + ".replace", std::ofstream::out);
	if (outfile.fail()){
		std::cout << argv[1] << ": can't open file." << std::endl;
		return (EXIT_FAILURE);
	}
	
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string line;
	size_t		i;

	while (std::getline(infile, line))
	{
		while ((i = line.find(s1)) != std::string::npos)
		{
			line.erase(i, s1.length());
			line.insert(i, s2);
			i += s2.length();
		}
		if (infile.eof())
			outfile << line;
		else
			outfile << line << std::endl;
	}
	outfile.close();
	infile.close();
	return 0;
}
