#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

int check_error(std::string str)
{
	if (str == "")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "impossible" << std::endl;
		std::cout << "double: " << "impossible" << std::endl;
		return 1;
	}
	if (str == "nan" || str == "nanf")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "nanf" << std::endl;
		std::cout << "double: " << "nan" << std::endl;
		return 1;
	}
	if (str == "+inf" || str == "+inff")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "+inff" << std::endl;
		std::cout << "double: " << "+inf" << std::endl;
		return 1;
	}
	if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "-inff" << std::endl;
		std::cout << "double: " << "-inf" << std::endl;
		return 1;
	}
	return 0;
}

int check_valid_char(std::string str)
{
	int dot = 0;
	for (int i = 0; (size_t)i < str.length(); i++)
	{
		if (isspace(str[i]) && str.length() != 1)
			return 1;
		if (isalpha(str[i]))
		{
			if (str[i] == 'f' && (size_t)i != str.length() - 1)
				return 1;
			else if (str[i] != 'f' && str.length() != 1)
				return 1;
		}
		if (str[i] == '.')
			dot++;
		if ((str[i] == '+' || str[i] == '-') && i != 0)
			return 1;
	}
	if (dot > 1)
		return 1;
	return 0;
}

int find_digit(std::string str)
{
	for (int i = 0; (size_t)i < str.length(); i++)
	{
		if (isdigit(str[i]))
			return 1;
	}
	return 0;
}

void ScalarConverter::convert(std::string str)
{
	if (check_error(str))
		return ;
	if (check_valid_char(str))
	{
		std::cout << "Incorrect input" << std::endl;
		return ;
	}
	if (isprint(str[0]) && !find_digit(str))
	{
		std::cout << "char: \'" << str << "\'" << std::endl;
		std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
		return ;
	}
	if (find_digit(str) && str.find(".") == std::string::npos)
	{
		long result = strtol(str.c_str(), NULL, 10);

		if (result <= 177 && result >= 0)
		{
			if (isprint(static_cast<char>(result)))
				std::cout << "char: \'" << static_cast<char>(result) << "\'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		else
			std::cout << "char: impossible" << std::endl;
		if (result <= std::numeric_limits<int>::max() && result >= std::numeric_limits<int>::min())
			std::cout << "int: " << static_cast<int>(result) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
		if (result <= std::numeric_limits<float>::max() && result >= std::numeric_limits<float>::lowest())
		{
			if (static_cast<int>(result) == result)
				std::cout << "float: " << static_cast<float>(result) << ".0f" << std::endl;
			else
				std::cout << "float: " << static_cast<float>(result) << "f" << std::endl;
		}
		else
			std::cout << "float: impossible" << std::endl;
		if (static_cast<int>(result) == result)
				std::cout << "double: " << static_cast<double>(result) << ".0" << std::endl;
			else
				std::cout << "double: " << static_cast<double>(result) << std::endl;
		return ;
	}
	if (find_digit(str) && str.find(".") != std::string::npos && str.find("f") == str.length() - 1)
	{
		double result = strtof(str.c_str(), NULL);

		if (result <= 177 && result >= 0)
		{
			if (isprint(static_cast<char>(result)))
				std::cout << "char: \'" << static_cast<char>(result) << "\'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		else
			std::cout << "char: impossible" << std::endl;
		if (result <= std::numeric_limits<int>::max() && result >= std::numeric_limits<int>::min())
			std::cout << "int: " << static_cast<int>(result) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
		if (result <= std::numeric_limits<float>::max() && result >= std::numeric_limits<float>::lowest())
		{
			if (static_cast<int>(result) == result)
				std::cout << "float: " << static_cast<float>(result) << ".0f" << std::endl;
			else
				std::cout << "float: " << static_cast<float>(result) << "f" << std::endl;
		}
		else
			std::cout << "float: impossible" << std::endl;
		if (static_cast<int>(result) == result)
				std::cout << "double: " << static_cast<double>(result) << ".0" << std::endl;
			else
				std::cout << "double: " << static_cast<double>(result) << std::endl;
		return ;
	}
	if (find_digit(str) && str.find(".") != std::string::npos && str.find("f") == std::string::npos)
	{
		double result = strtod(str.c_str(), NULL);

		if (result <= 177 && result >= 0)
		{
			if (isprint(static_cast<char>(result)))
				std::cout << "char: \'" << static_cast<char>(result) << "\'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		if (result <= std::numeric_limits<int>::max() && result >= std::numeric_limits<int>::min())
			std::cout << "int: " << static_cast<int>(result) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
		if (result <= std::numeric_limits<float>::max() && result >= std::numeric_limits<float>::lowest())
		{
			if (static_cast<int>(result) == result)
				std::cout << "float: " << static_cast<float>(result) << ".0f" << std::endl;
			else
				std::cout << "float: " << static_cast<float>(result) << "f" << std::endl;
		}
		else
			std::cout << "float: impossible" << std::endl;
		if (static_cast<int>(result) == result)
				std::cout << "double: " << static_cast<double>(result) << ".0" << std::endl;
			else
				std::cout << "double: " << static_cast<double>(result) << std::endl;
		return ;
	}
}
