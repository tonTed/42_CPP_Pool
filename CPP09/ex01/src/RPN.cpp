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
		std::string	input = _getInput();

		if (input == "quit") {
			break;
		}

		std::stringstream ss;
		ss << input;

		_doOp(ss);
	}
}

std::string	RPN::_getInput() {	Log::logFunction(__FUNCTION__);
	std::string	input;

	std::cout << YELLOW << "Enter a RPN (or 'quit'): " << RESET;
	std::getline(std::cin, input);
	return input;
}

void	RPN::_doOp(std::stringstream &ss) {	Log::logFunction(__FUNCTION__);

	std::stack<int>	stack;

	std::string token;

	while (ss >> token)
	{

		if (token.length() != 1)
		{
			std::cout << RED << "Error: " << RESET << "Invalid token: " << token << std::endl;
			return;
		}
		if (isdigit(token[0]))
		{
			Log::logToConsole("Push number: " + token + ".");
			stack.push(std::stoi(token));
		}
		else if (stack.size() < 2)
		{
			std::cout << RED << "Error: " << RESET << "Stack must be greater than 1." << std::endl;
			return;
		}
		else
		{
			int a = stack.top();
			stack.pop();
			int b = stack.top();
			stack.pop();
			Log::logToConsole("doOp: " + std::to_string(a) + " " + token + " " + std::to_string(b) + " .");
			switch (token[0])
			{
				case '+':
				{
					stack.push(b + a);
					break;
				}
				case '-':
				{
					stack.push(b - a);
					break;
				}
				case '*':
				{
					stack.push(b * a);
					break;
				}
				case '/':
				{
					if (a == 0)
					{
						std::cout << RED << "Error: " << RESET << "Divide by 0 not possible." << std::endl;
						return;
					}
					stack.push(b / a);
					break;
				}
				default:
				{
					std::cout << RED << "Error: " << RESET << "Invalid token: " << token[0] << std::endl;
					return;
				}
			}
		}
	}
	std::cout << std::to_string(stack.top()) << std::endl;
}
