#include "user.h"

bool userLogin()
{	
	std::string name, pass;

	std::cout << "\n------LOGIN------";

login:
	std::cout << "\nName: "; 
	std::cin >> name;
	
	std::cout << "Password: ";
	std::cin >> pass;

	if (name == "Admin" && pass == "admin1")
	{
		return true;
	}
	else
	{
		std::cout << "\nWrong password or user's name inexistent";
		std::cout << "\n1. Continue login";
		std::cout << "\n2. Back\n";

		char c;
		std::cin >> c;
		switch (c)
		{
		case '1':
			goto login;
			break;
		case '2':
			return false;
			break;
		default:
			std::cout << "Enter '1' or '2' please\n";
			goto login;
			break;
		}
	}
}