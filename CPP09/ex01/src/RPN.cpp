//
// Created by Teddy BLANCO on 2023-04-22.
//

#include "RPN.hpp"

RPN::RPN() {	Log::logFunction(__FUNCTION__);
	_engine();
}

RPN::RPN(RPN const & src) {	Log::logFunction(__FUNCTION__);
	*this = src;
}

RPN::~RPN() {	Log::logFunction(__FUNCTION__);
}

RPN & RPN::operator=(RPN const & rhs) {	Log::logFunction(__FUNCTION__);
	if (this != &rhs) {
		// do stuff
	}
	return *this;
}

void	RPN::_engine() {	Log::logFunction(__FUNCTION__);

	while (42)
	{
		std::string	input;

		std::stringstream ss;

		std::cout << YELLOW << "Enter a RPN (or 'quit'): " << RESET;
		std::getline(std::cin, input);
		if (input == "quit") {
			break;
		}
		ss << input;
		std::string token;
		while (ss >> token)
		{
			std::cout << token << std::endl;
		}
	}
}