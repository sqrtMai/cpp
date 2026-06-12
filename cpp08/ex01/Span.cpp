#include "Span.hpp"

Span::Span(unsigned int N) : max(N), current(0)
{
	//v.reserve(N);
}

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
	return *this;
}

Span::~Span()
{
}


void Span::addNumber(int nb)
{
	if (current < max)
	{
		this->v.push_back(nb);
		current++;
	}
	else
		throw std::exception();

}

int Span::shortestSpan()
{
	if (this->v.size() < 2)
		throw std::exception();
	else
	{
		sort(this->v.begin(), this->v.end());
		int shortest = __INT_MAX__;
		for (size_t i = 0; i < this->v.size() - 1; i++)
		{
			if (abs(this->v[i + 1] - this->v[i]) < shortest)
				shortest = abs(this->v[i + 1] - this->v[i]);
		}
		return shortest;
	}
}

int Span::longestSpan()
{
	if (this->v.size() < 2)
		throw std::exception();
	else
	{
		sort(this->v.begin(), this->v.end());
		return abs(this->v.back() - this->v.front());
	}
}
