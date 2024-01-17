#include "book.h"
#include "user.h"
#include "bookShelf.h"
#include <fstream>


void admin();
void user();
void launch();

int main()
{
	launch();
	return 0;
}

void admin()
{
	while (1)
	{
		system("cls");
		std::cout << "\n--------------------ADMIN--------------------";
		std::cout << "\n|| 1. Display bookshelf                    ||";
		std::cout << "\n|| 2. Add bookshelf                        ||";
		std::cout << "\n|| 3. Delete bookshelf                     ||";
		std::cout << "\n|| 4. Find a book                          ||";
		std::cout << "\n|| 5. Add book                             ||";
		std::cout << "\n|| 6. Delete a book                        ||";
		std::cout << "\n|| 7. Replace book                         ||";
		std::cout << "\n|| 8. Back                                 ||";
		std::cout << "\n---------------------------------------------\n";
		std::cout << "\nYour choice: ";

		char c;
		std::cin >> c;
		switch (c)
		{
		case '1':
			bookDisplay();
			break;
		case '2':
			bookShelf_Add();
			break;
		case '3':
			bookShelf_Delete();
			break;
		case '4':
			bookFind();
			break;
		case '5':
			bookAdd();
			break;
		case '6':
			bookDelete();
			break;
		case '7':
			bookReplace();
			break;
		case '8':
			launch();
			break;
		default:
			std::cout << "\nInvalid value";
			admin();
			break;
		}
	}
}
void user()
{
	while (1)
	{
		system("cls");
		std::cout << "\n--------------------GUEST--------------------";
		std::cout << "\n|| 1. Display bookshelf                    ||";
		std::cout << "\n|| 2. Find a book                          ||";
		std::cout << "\n|| 3. Back                                 ||";
		std::cout << "\n---------------------------------------------\n";
		std::cout << "\nYour choice: ";

		char c;
		std::cin >> c;
		switch (c)
		{
		case '1':
			bookDisplay();
			break;
		case '2':
			bookFind();
			break;
		case '3':
			launch();
			break;
		default:
			std::cout << "\nInvalid value";
			user();
			break;
		}
	}
}

void launch()
{
	system("cls");
start:
	std::cout << "\n----------LIBRARY MANAGE----------";
	std::cout << "\n|| 1. Login                      ||";
	std::cout << "\n|| 2. Access as guest            ||";
	std::cout << "\n|| 3. Exit                       ||";
	std::cout << "\n----------------------------------\n";

	char c;
	std::cin >> c;
	switch (c)
	{
	case '1':
		if (userLogin()) admin();
		else goto start;
		break;
	case '2':
		user();
		break;
	case '3':
		exit(0);
		break;
	default:
		std::cout << "Enter '1' or '2' please";
		goto start;
		break;
	}
}