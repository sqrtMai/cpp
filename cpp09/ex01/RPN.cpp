#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN& RPN::operator =(const RPN &other)
{
	if (this == &other)
		return *this;
	return *this;

}

RPN::~RPN()
{
}

int RPN::check_operator(char op)
{
	std::string opset = "+-/*";
	size_t pos = opset.find(op);

	if (pos == std::string::npos)
		return 0;
	else
		return 1;
}


void RPN::do_op(std::stack<double, std::list<double> > &s, char op)
{
	double b = s.top(); s.pop();
	double a = s.top(); s.pop();

	if (op == '/' && b == 0)
		throw std::runtime_error("Error: division by zero");
	if (op == '+')
		s.push(a + b);
	if (op == '-')
		s.push(a - b); //TODO DIVISION PAR ZERO
	if (op == '/')
		s.push(a / b);
	if (op == '*')
		s.push(a * b);
}


int RPN::execute(char **argv)
{
	std::stack<double, std::list<double> > s;
	std::string args(argv[1]);

	for (size_t i = 0; i < args.length(); i++)
	{
		if (i != args.length() - 1 && args[i] != ' ' && args[i + 1] != ' ')
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
		if (args[i] == ' ')
			continue;
		if (isdigit(args[i]))
			s.push(args[i] - '0');
		else
		{
			if (check_operator(args[i]) && s.size() >= 2)
			{
				try
				{
					do_op(s, args[i]);
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
					return 1;
				}


			}
			else
			{
				std::cerr << "Error" << std::endl;
				return 1;
			}
		}
	}
	if (s.size() == 1)
		std::cout << "Result: " << s.top() << std::endl;
	else
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	return 0;
}
