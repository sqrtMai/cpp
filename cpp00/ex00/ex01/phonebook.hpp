#ifndef PHONEBOOK
# define PHONEBOOK

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class Contact
{
public:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string number;
	std::string secret;

};

class PhoneBook
{
public:
	Contact contact[8];
};


#endif
