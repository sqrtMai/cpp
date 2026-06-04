#include "BitcoinExchange.hpp"

size_t get_file_size(std::ifstream &in)
{
	in.seekg(0, in.end);
	size_t len = in.tellg();
	in.seekg(0, in.beg);
	return len;
}

std::string trim_space(std::string line)
{
	int start = 0;
	int end = line.size();

	while (start < end && isspace(line[start]))
		start++;
	while (end > start && isspace(line[end]))
		end--;

	return line.substr(start, end - start);
}

void trim_dash(std::string date, std::string &year, std::string &month, std::string &day)
{
	int start = 0;
	int prev;

	while (date[start] && date[start] != '-')
		start++;
	year = date.substr(0, start - date.length());
	prev = start;
	while (date[start] && date[start] != '-')
		start++;
	month =  date.substr(prev, start - prev);
	prev = start;
	while (date[start] && date[start] != '-')
		start++;
	day = date.substr(prev, start - prev);

}

int check_date(std::string date, std::string year, std::string month, std::string day)
{
	int
}

int isValidDate(std::string date)
{
	int i = 0;
	int dash = 0;
	date = trim_space(date);

	std::string year;
	std::string month;
	std::string day;

	while (date[i])
	{
		if (!isdigit(date[i]) && date[i] != '-')
		{
			std::cout << "Error: bad date input => " << date << std::endl;
			return 0;
		}
		if (date[i] != '-')
			dash++;
		i++;
	}

	if (dash != 2)
	{
		std::cout << "Error: bad date input => " << date << std::endl;
		return 0;
	}

	trim_dash(date, year, month, day);

	return 1;
}

int isValidValue(std::string value)
{
	int i = 0;
	value = trim_space(value);

	while (value[i])
	{
		if (!isdigit(value[i]))
		{
			std::cout << "Error: bad value input => " << value << std::endl;
			return 1;
		}
		i++;
	}

	double dValue = strtod(value.c_str(), NULL);

	if (dValue > 1000)
	{
		std::cout << "Error: number exceeds 1000" << std::endl;
		return 1;
	}
	if (dValue < 0)
	{
		std::cout << "Error: not a positive number" << std::endl;
		return 1;
	}

	return 0;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "./btc [file]" << std::endl;
		return 1;
	}

	std::ifstream in(argv[1], std::ios::binary);
	if (!in)
	{
		std::cout << "File: " << argv[1] << " not found" << std::endl;
		return 1;
	}

	int i = 0;
	std::string line;
	std::string date;
	std::string value;
	while (std::getline(in, line))
	{
		if (i == 0 && line == "data | value")
		{
			i++;
			continue;
		}
		line = trim_space(line);
		size_t pos = line.find("|");
		if (pos == std::string::npos)
			std::cout << "Error: bad line [" << i << "]" << std::endl;
		else
		{
			date = line.substr(0, 0 + pos);
			value = line.substr(pos, line.size() - pos);

		}
		i++;
	}

	return 0;
}
