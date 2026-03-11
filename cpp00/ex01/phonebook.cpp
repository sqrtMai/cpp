#include "phonebook.hpp"

int is_digit(std::string str){
	size_t i = 0;
	while (i < str.length())
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return 1;
	}
	return 0;
}

void search(PhoneBook *phonebook, int max)
{
	std::cout << std::setw(10) << "INDEX";
	std::cout << "|";
	std::cout << std::setw(10) << "FIRST NAME";
	std::cout << "|";
	std::cout << std::setw(10) << "LAST NAME";
	std::cout << "|";
	std::cout << std::setw(10) << "NICKNAME" << std::endl;

	if (!max)
		return (std::cout << std::endl, (void)1);
	for (int i = 0; i < max; i++)
	{
		std::cout << std::right << std::setw(10) << i;
		if (phonebook->contact[i].first_name.length() > 10)
			std::cout << std::right << std::setw(10) << phonebook->contact[i].first_name.substr(0, 9) << ". ";
		else
			std::cout << std::right <<  std::setw(10) << phonebook->contact[i].first_name;
		if (phonebook->contact[i].last_name.length() > 10)
			std::cout << std::right <<  std::setw(10) <<phonebook->contact[i].last_name.substr(0, 9) << ". ";
		else
			std::cout << std::right <<  std::setw(10) <<phonebook->contact[i].last_name;
		if (phonebook->contact[i].nickname.length() > 10)
			std::cout << std::right <<   std::setw(10) <<phonebook->contact[i].nickname.substr(0, 9) << ". ";
		else
			std::cout << std::right << std::setw(10) << phonebook->contact[i].nickname;
		std::cout << std::endl;
	}

	std::string nbr;
	int nb = 10;

	while (nb > max - 1)
	{
		std::cout << "Please put a number (0 - " << max - 1 << ")" << std::endl;
		std::cin >> nbr;
		if (is_digit(nbr))
			continue ;
		std::stringstream ss(nbr);
		ss >> nb;
		if (nb < 0)
		{
			nb = 10;
		}
	}
	std::cout << "First name: " << phonebook->contact[nb].first_name << std::endl;
	std::cout << "Last name: " << phonebook->contact[nb].last_name << std::endl;
	std::cout << "Nickame: " << phonebook->contact[nb].nickname << std::endl;
	std::cout << "Darkest Secret: " << phonebook->contact[nb].secret << std::endl;
	std::cout << "Phone number: " << phonebook->contact[nb].number << std::endl;

}



void add(PhoneBook *phonebook, int *i)
{
	Contact contact;

	while (contact.first_name == "")
	{
		std::cout << "Contact FIRST NAME: ";
		std::getline(std::cin, contact.first_name);
		if (contact.first_name == "")
			std::cout << "Field cannot be empty" << std::endl;
	}
	std::cout << std::endl;
	while (contact.last_name == "")
	{
		std::cout << "Contact LAST NAME: ";
		std::getline(std::cin, contact.last_name);
		if (contact.last_name == "")
			std::cout << "Field cannot be empty" << std::endl;
	}
	std::cout << std::endl;
	while (contact.nickname == "")
	{
		std::cout << "Contact NICKNAME: ";
		std::getline(std::cin, contact.nickname);
		if (contact.nickname == "")
			std::cout << "Field cannot be empty" << std::endl;
	}
	std::cout << std::endl;
	while (contact.number == "")
	{
		std::cout << "Contact NUMBER: ";
		std::getline(std::cin, contact.number);
		if (contact.number == "")
			std::cout << "Field cannot be empty" << std::endl;
	}
	std::cout << std::endl;
	while (contact.secret == "")
	{
		std::cout << "Contact DARKEST SECRET: ";
		std::getline(std::cin, contact.secret);
		if (contact.secret == "")
			std::cout << "Field cannot be empty" << std::endl;
	}
	std::cout << std::endl;
	phonebook->contact[*i] = contact;
	if (*i < 7)
		(*i)++;
}

int main(void)
{
	PhoneBook phonebook;
	std::string input;
	int i;

	i = 0;
	while (1)
	{
		std::cout << "ADD, SEARCH, EXIT" << std::endl;
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			add(&phonebook, &i);
		}
		else if (input == "SEARCH")
		{
			search(&phonebook, i);
		}
		else if (input == "EXIT")
			break ;
	}
	return 0;
}
