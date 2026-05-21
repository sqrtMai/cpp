#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>

class ScalarConverter
{
private:
	ScalarConverter();
public:
	static void convert(const std::string str);
};

int check_error(std::string str);
int check_valid_char(std::string str);
int find_digit(std::string str);


#endif
