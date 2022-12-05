/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:21:44 by tonted            #+#    #+#             */
/*   Updated: 2022/12/05 11:13:42 by tblanco          ###   ########.fr       */
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

	std::ofstream outfile("outfile", std::ofstream::out);
	if (outfile.fail()){
		std::cout << argv[1] << ": can't open file." << std::endl;
		return (EXIT_FAILURE);
	}
	outfile.clear();
	outfile.close();
	outfile.open("outfile", std::ofstream::app);
	
	std::string s1		= argv[2];
	size_t		len_s1	= s1.length();

	std::string s2 = argv[3];
	std::string line;
	size_t		i;

	while (std::getline(infile, line))
	{
		while ((i = line.find(s1)) != size_t(-1)
			&& (!line[i + len_s1] || ::isspace(line[i + len_s1]) || ::ispunct(line[i + len_s1])))
		{
			line.erase(i, s1.length());
			line.insert(i, s2);
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
