#include "Span.hpp"
#include <stdlib.h>
#include <iostream>
#include <time.h>

void subjectExample(Span &sp)
{
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
}

int main(void)
{
	srand(time(NULL));

	Span a(100000);
	Span b(5);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "==== Span with a size max of 100 000 int ====" << std::endl;
	for (int i = 0; i < 100000; i++)
	{
		a.addNumber(i);
	}
	std::cout << "For number between 0 and 99999" << std::endl;

	std::cout << "The shortest span is: " << a.shortestSpan() << std::endl;
	std::cout << "The longest span is: " << a.longestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << "This is the example used in the subject:" << std::endl;
	subjectExample(b);
	std::cout << "The shortest span is: " << b.shortestSpan() << std::endl;
	std::cout << "The longest span is: " << b.longestSpan() << std::endl;
	std::cout << std::endl;


	std::cout << "If we try to had a new number that exceeds the size max of our Span:" << std::endl;
	try
	{
		a.addNumber(200000);
	}
	catch (std::exception &e)
	{
		std::cout << "The Span is full, it cannot accept any new number" << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
}
