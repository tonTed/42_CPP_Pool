//
// Created by Teddy BLANCO on 2023-04-23.
//

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **av, int ac) {	Log::logFunction(__FUNCTION__);

	try {
		_fillListInput(av, ac);
		Log::logContainer(_listInput, "Before<List> ");
		Log::logContainer(_dequeInput, "Before<Deque>");
	}
	catch (std::exception & e) {
		std::cout << RED << "Error: " << RESET << e.what() << std::endl;
		return;
	}
}

PmergeMe::PmergeMe() {	Log::logFunction(__FUNCTION__);

}

PmergeMe::~PmergeMe() {	Log::logFunction(__FUNCTION__);

}

PmergeMe::PmergeMe(const PmergeMe &rhs) {	Log::logFunction(__FUNCTION__);
	*this = rhs;
}

PmergeMe & PmergeMe::operator=(const PmergeMe &rhs) {	Log::logFunction(__FUNCTION__);
	if (this != &rhs)
	{

	}
	return *this;
}

void	PmergeMe::_fillListInput(char **av, int ac) {	Log::logFunction(__FUNCTION__);

	(void)_listInput;
	(void)_dequeInput;

	av++;
	while (--ac)
	{
		try {
			int a = std::stoi(*av);

			if (a < 0)
				throw std::out_of_range("Number out of range: " + std::to_string(a));
			_listInput.push_back(static_cast<unsigned int>(a));
			_dequeInput.push_back(static_cast<unsigned int>(a));
		}
		catch (std::exception & e) {
			throw std::runtime_error(e.what());
		}
		av++;
	}
}
