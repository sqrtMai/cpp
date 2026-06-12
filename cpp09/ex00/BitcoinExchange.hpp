#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cctype>
#include <cstdlib>

class BitcoinExchange
{
private:
	std::string compareDates(std::string date1, std::string date2);
	int isValidValue(std::string &value, bool type);
	int isValidDate(std::string &date, bool type);
	int check_date(std::string date, std::string year, std::string month, std::string day);
	void trim_dash(std::string date, std::string &year, std::string &month, std::string &day);
	std::string trim_space(std::string line);
	std::map<std::string, double> fillMap(void);
	std::map<std::string, double>::iterator findNearestDate(std::map<std::string, double>& data, const std::string& date);
	bool Bisextiloupa(int year);
	bool isValidDate2(double year, double month, double day);
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange& operator =(const BitcoinExchange &other);
	~BitcoinExchange();

	int exchange(char **argv);
};

#endif
