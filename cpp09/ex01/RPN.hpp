#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <ctype.h>

class RPN
{
private:
	int check_operator(char op);
	void do_op(std::stack <int> &s, char op);
public:
	RPN();
	RPN(const RPN &other);
	RPN& operator =(const RPN &other);
	~RPN();

	int execute(char **argv);
};

#endif
