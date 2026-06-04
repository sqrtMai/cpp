#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
class Span
{
private:
	std::vector<int> v;
	unsigned int max;
	unsigned int current;

public:
	Span(unsigned int N);
	Span(const Span &other);
	Span& operator=(const Span &other);
	~Span();

	int shortestSpan();
	int longestSpan();
	void addNumber(int nb);
};

Span::Span(const Span &other)
{
	*this = other;
}

Span& Span::operator=(const Span &other)
{
	if (this == &other)
		return *this;
	this->v = other.v;
	this->max = other.max;
	this->current = other.current;
}

#endif
