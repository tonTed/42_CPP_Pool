//
// Created by Teddy BLANCO on 2023-04-23.
//

#include <list>
#include <deque>
#include <string>
#include <limits>

#include "../Log.hpp"

#ifndef PMERGEME_HPP
#define PMERGEME_HPP


class PmergeMe {

public:
	PmergeMe(char **av, int ac);
	~PmergeMe();


private:
	PmergeMe & operator=(const PmergeMe & rhs);
	PmergeMe(const PmergeMe & rhs);
	PmergeMe();

	std::list<unsigned int>		_listInput;
	std::deque<unsigned int>	_dequeInput;

	void	_fillListInput(char **av, int ac);

};


#endif //PMERGEME_HPP
