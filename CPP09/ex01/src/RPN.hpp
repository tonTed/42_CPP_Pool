//
// Created by Teddy BLANCO on 2023-04-22.
//

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <sstream>

#include "../Log.hpp"

class RPN {

public:
	RPN();
	RPN(RPN const & src);
	~RPN();

	RPN & operator=(RPN const & rhs);

	void	_engine();

	std::stack<char>	_stack;

};


#endif //RPN_HPP
