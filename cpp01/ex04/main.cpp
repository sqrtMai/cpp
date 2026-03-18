#include "sed.hpp"

size_t get_file_size(std::ifstream &in)
{
	in.seekg(0, in.end);
	size_t len = in.tellg();
	in.seekg(0, in.beg);
	return len;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "3 arguments needed" << std::endl;
		return 1;
	}
	std::ifstream in(argv[1], std::ios::binary);
	if (!in)
	{
		std::cout << "File not found" << std::endl;
		return 1;
	}

	char *file = new char [get_file_size(in) + 1];
	file[get_file_size(in)] = 0;
	in.read(file, get_file_size(in));

	std::string copy(file);
	std::string argv2(argv[2]);
	std::string argv3(argv[3]);
	if (argv2 == "" || argv3 == "")
	{
		std::cout << "empty arg" << std::endl;
		delete []file;
		return 1;
	}
	std::cout << file << std::endl;
	size_t i = 0;
	size_t pos;

	while (copy[i])
	{
		pos = copy.find(argv2, 0);
		if (pos != std::string::npos)
		{
			copy.erase(pos, argv2.length());
			copy.insert(pos, argv3);
			i = pos + argv3.length();
		}
		if (copy[i])
			i++;
	}
	std::cout << copy << std::endl;
	std::ofstream out("infile.replace");
	char *new_file = new char [copy.length() + 1];
	new_file[copy.length()] = 0;
	for (size_t j = 0; j < copy.length(); j++)
		new_file[j] = copy[j];
	out.write(new_file, copy.length());
	delete []new_file;
	delete []file;
}

