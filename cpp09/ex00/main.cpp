#include "BitcoinExchange.hpp"

std::string trim_space(std::string line)
{
	int start = 0;
	int end = line.length();

	while (start < end && isspace(line[start]))
		start++;
	while (end > start && isspace(line[end - 1]))
		end--;

	return line.substr(start, end - start);
}

void trim_dash(std::string date, std::string &year, std::string &month, std::string &day)
{
	int prev;
	size_t start = 0;

	for (; start < date.length(); start++)
	{
		if (date[start] == '-')
			break;
	}
	year = date.substr(0, start);
	prev = ++start;

//	std::cout << "start = " << start << std::endl;
	for (; start < date.length(); start++)
	{
		if (date[start] == '-')
			break;
	}
	month =  date.substr(prev, start - prev);
	prev = ++start;

	for (; start < date.length(); start++)
	{
		if (date[start] == '-')
			break;
	}
	day = date.substr(prev, start - prev);

	//std::cout << "DATES /" << date << "/" << std::endl;

}

int check_date(std::string date, std::string year, std::string month, std::string day)
{
	char *end;

	if (day.length() != 2 || month.length() != 2 || year.length() != 4)
	{
		//std::cout << "Error: bad date -input- => " << day << std::endl;
		return 1;
	}

	double dYear = strtod(year.c_str(), &end);
	if (*end != 0)
	{
			std::cout << "Error: bad date input => " << date << std::endl;
			return 0;
	}
	(void)dYear;
	double dMonth = strtod(month.c_str(), &end);
	if (*end != 0)
	{
			std::cout << "Error: bad date input => " << date << std::endl;
			return 0;
	}
	(void)dMonth;

	double dDay = strtod(day.c_str(), &end);
	if (*end != 0)
	{
			std::cout << "Error: bad date input => " << date << std::endl;
			return 0;
	}
	(void)dDay;
	return 0;
}

int isValidDate(std::string &date, bool type)
{
	int dash = 0;

	if (type)
		date = trim_space(date);
	std::string year;
	std::string month;
	std::string day;

	for (size_t i = 0; i < date.length(); i++)
	{
		if (date[i] == '-')
			dash++;
	}

	if (dash != 2)
	{
		std::cout << "Error: bad date input => " << date << std::endl;
		return 0;
	}


	//std::cout << "Error: bad date -input- => " << date << std::endl;
	trim_dash(date, year, month, day);
	if (check_date(date, year, month, day))
		return 0;
	return 1;
}

int isValidValue(std::string &value, bool type)
{
	if (type)
		value = trim_space(value);

	char *end;
	double dValue = strtod(value.c_str(), &end);
	//std::cout << "VALUE = |" << dValue << "|" << std::endl;

	if (*end != 0)
	{
		std::cout << "Error: bad line" << std::endl;
		return 0;
	}
	if (type && dValue > 1000)
	{
		std::cout << "Error: number exceeds 1000" << std::endl;
		return 0;
	}
	if (type && dValue < 0)
	{
		std::cout << "Error: not a positive number" << std::endl;
		return 0;
	}
	return 1;
}

std::string compareDates(std::string date1, std::string date2)
{
	std::string year;
	std::string month;
	std::string day;

	std::string year2;
	std::string month2;
	std::string day2;

	trim_dash(date1, year, month, day);
	trim_dash(date2, year2, month2, day2);

	if (strtod(year.c_str(), NULL) < strtod(year2.c_str(), NULL))
		return date2;
	if (strtod(year.c_str(), NULL) > strtod(year2.c_str(), NULL))
		return date1;
	if (strtod(year.c_str(), NULL) == strtod(year2.c_str(), NULL))
	{
		if (strtod(month.c_str(), NULL) < strtod(month2.c_str(), NULL))
			return date2;
		if (strtod(month.c_str(), NULL) > strtod(month2.c_str(), NULL))
			return date1;
		if (strtod(month.c_str(), NULL) == strtod(month2.c_str(), NULL))
		{
			if (strtod(day.c_str(), NULL) < strtod(day2.c_str(), NULL))
				return date2;
			if (strtod(day.c_str(), NULL) >= strtod(day2.c_str(), NULL))
				return date1;
		}
	}
	return date1;
}

std::map<std::string, double> fillMap(void)
{
	std::map<std::string, double> data;
	std::ifstream in("data.csv", std::ios::binary);
	std::string line;
	std::string date;
	std::string value;

	if (!in)
	{
		std::cout << "File: data.csv not found" << std::endl;
		exit(1);
	}
	std::getline(in, line);
	while (std::getline(in, line))
	{
		size_t pos = line.find(",");
		if (pos == std::string::npos)
			continue;
		date = line.substr(0, pos);
		value = line.substr(pos + 1, line.length() - pos);
		if (!isValidDate(date, false) || !isValidValue(value, false))
			continue;
		data[date] = std::strtod(value.c_str(), NULL);
	}
	return data;
}

std::map<std::string, double>::iterator findNearestDate(
    std::map<std::string, double>& data,
    const std::string& date)
{
    std::map<std::string, double>::iterator it = data.lower_bound(date);

    if (it == data.end())
    {
        --it;
        return it;
    }

    if (it->first == date)
        return it;

    if (it == data.begin())
    {
        std::cerr << "Error: no lower date available" << std::endl;
        return data.end();
    }

    --it;
    return it;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "./btc [file]" << std::endl;
		return 1;
	}
	std::map<std::string, double> data = fillMap();
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
	std::map<std::string, double>::iterator it;

	while (std::getline(in, line))
	{
		if (i == 0 && line == "date | value")
		{
			i++;
			continue;
		}
		line = trim_space(line);
		size_t pos = line.find("|");
		if (pos == std::string::npos)
			std::cout << "Error: bad line" << std::endl;
		else
		{
			date = line.substr(0, pos);
			value = line.substr(pos + 1, line.length() - pos);
			if (!isValidDate(date, 1) || !isValidValue(value, true))
				continue;

			it = findNearestDate(data, date);
			if (it != data.end())
				std::cout << date << "=> " << value << " = " << std::strtod(value.c_str(), NULL) * it->second << std::endl;
		}
	}

	return 0;
}
