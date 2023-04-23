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
		std::stack<char>	_stack;

		std::string	input = _getInput();

		if (input == "quit") {
			break;
		}

		std::stringstream ss;
		ss << input;
		if (!_updateStack(_stack, ss))
			continue;
		if (_stack.size() < 3)
		{
			std::cout << RED << "Error: " << RESET << "Not enough operands" << std::endl;
			continue;
		}
	}
}

std::string	RPN::_getInput() {	Log::logFunction(__FUNCTION__);
	std::string	input;

	std::cout << YELLOW << "Enter a RPN (or 'quit'): " << RESET;
	std::getline(std::cin, input);
	return input;
}

bool	RPN::_updateStack(std::stack<char> &stack, std::stringstream &ss) {	Log::logFunction(__FUNCTION__);

	std::string token;

	while (ss >> token)
	{
		if (token.length() != 1 || (!isdigit(token[0]) && token[0] != '+' && token[0] != '-' && token[0] != '*' && token[0] != '/'))
		{
			std::cout << RED << "Error: " << RESET << "Invalid token: " << token << std::endl;
			return false;
		}
		stack.push(token[0]);
	}
	return true;
}
