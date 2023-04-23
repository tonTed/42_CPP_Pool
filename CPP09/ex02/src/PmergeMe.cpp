//
// Created by Teddy BLANCO on 2023-04-23.
//

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **av, int ac) {	Log::logFunction(__FUNCTION__);

	float	listTime;
	float	dequeTime;

	try {
		_fillListInput(av, ac);
		Log::logContainer(_listInput, "Before<List> ");
		Log::logContainer(_dequeInput, "Before<Deque>");

		listTime = _mergeInsertSort(_listInput);
		dequeTime = _mergeInsertSort(_dequeInput);
		Log::logContainer(_listInput, "After<List> ");
		Log::logContainer(_dequeInput, "After<Deque>");

		std::cout << GREEN << "Time to process a range of " << _listInput.size() << " elements with std::list  : " << RESET << std::fixed << listTime << " ms." << std::endl;
		std::cout << GREEN << "Time to process a range of " << _dequeInput.size() << " elements with std::deque : " << RESET << std::fixed << dequeTime << " ms." << std::endl;
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

double	PmergeMe::_currentTime() {	Log::logToConsole(__FUNCTION__);
	struct timeval currentTime;
	gettimeofday(&currentTime, nullptr);
	return static_cast<double>(currentTime.tv_sec) + (static_cast<double>(currentTime.tv_usec) / 1000000.0);
}

template<typename T>
double PmergeMe::_mergeInsertSort(T &container) {	Log::logFunction(__FUNCTION__);
	(void)container;

	double startTime = _currentTime();

	double endTime = _currentTime();

	return endTime - startTime;
}
