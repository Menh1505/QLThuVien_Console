#include "bookShelf.h"

std::vector<std::string> bookShelf_Get()
{
	std::vector<std::string> tmp;
	
	std::fstream bsFile("allBookShelf.txt", std::ios_base::in);
	std::string str;

	while (bsFile.is_open())
	{
		while (std::getline(bsFile, str))
		{
			tmp.push_back(str);
		}
		bsFile.close();
	}
	return tmp;
}

void bookShelf_ShowAll()
{
	std::fstream bsFile("allBookShelf.txt", std::ios_base::in);
	std::string str;

	int i = 1;
	while (bsFile.is_open())
	{
		while (std::getline(bsFile, str))
		{
			std::cout << i++ << "." << str << std::endl;
		}
		bsFile.close();
	}
}

void bookShelf_Delete()
{
	bookShelf_ShowAll();
	std::vector<std::string> bsList = bookShelf_Get(); //Lấy danh sách kệ vào vector để xử lý

	std::cout << "\nChoose bookShelf to delete: ";
choose:
	std::string choose;
	std::cin >> choose;

	int numCheck = atoi((char*)choose.c_str());
	if (numCheck < 1 || numCheck > bsList.size())
	{
		std::cout << "\nBookshelf not found, choose again please\n";
		goto choose;
	}

	std::string bsName_Remove = bsList[numCheck - 1] + ".txt"; //Xoá file kệ sách
	remove((char *)bsName_Remove.c_str());

	bsList.erase(bsList.begin() + numCheck - 1); //Xoá tên kệ sách trên vector

	std::fstream bsFileIn("allBookShelf.txt", std::ios_base::in); //Mở file để xoá hết thông tin cũ
	bsFileIn.clear();
	bsFileIn.close();

	std::fstream bsFileOut("allBookShelf.txt", std::ios_base::out); //Mở file để đè thông tin mới vào
	while (bsFileOut.is_open())
	{
		for (auto i : bsList)
		{
			bsFileOut << i << std::endl;
		}
		bsFileOut.close();
	}
}

void bookShelf_Add()
{
	std::fstream bsFileOut("allBookShelf.txt", std::ios_base::out| std::ios_base::app);
	std::string bsName;
	std::cout << "\nEnter bookshelf's name: ";
	std::cin >> bsName;

	bsFileOut << std::endl;  //Nhập tên kệ sách mới vào file
	bsFileOut << bsName;

	bsName += ".txt"; //Tạo file kệ sách mới
	std::ofstream newBookShelf(bsName); 

	newBookShelf.close();
	bsFileOut.close();
}

std::string bookList_Link()
{
	std::vector<std::string> bsList = bookShelf_Get(); //Lấy danh sách kệ
	std::cout << "\nChoose a bookshelf to open: ";

choose:
	std::string choose;
	std::cin >> choose;

	int numCheck = atoi((char*)choose.c_str());
	if (numCheck < 1 || numCheck > bsList.size())
	{
		std::cout << "\nBookshelf not found, choose again please\n";
		goto choose;
	}

	std::cout << "\nYour choice: " << bsList[numCheck - 1];
	std::string bookListLink = bsList[numCheck - 1] + ".txt"; //Trả về link kệ sách đã chọn
	return bookListLink;
}

void browse_Tittle(std::string info)
{
	std::ifstream bsFile("allBookShelf.txt");

	std::string str;
	while (bsFile.is_open()) //Duyệt từng file kệ sách
	{
		while (std::getline(bsFile, str)) 
		{
			str += ".txt";
			bookList bl = bookList_Get(str);

			for (book* b = bl.firstBook; b != NULL; b = b->Next)
			{
				if (stringCompare(b->tittle, info))
				{
					std::cout << "\n-----------------------------------";
					bookPrint(b);
				}
			}
			bookList_Free(bl);
		}
		bsFile.close();
	}
}

void browse_Subject(std::string info)
{
	std::ifstream bsFile("allBookShelf.txt");

	std::string str;
	while (bsFile.is_open()) //Duyệt từng file kệ sách
	{
		while (std::getline(bsFile, str))
		{
			str += ".txt";
			bookList bl = bookList_Get(str);

			for (book* b = bl.firstBook; b != NULL; b = b->Next)
			{
				if (stringCompare(b->subject, info))
				{
					std::cout << "\n-----------------------------------";
					bookPrint(b);
				}
			}
			bookList_Free(bl);
		}
		bsFile.close();
	}
}

void browse_Author(std::string info)
{
	std::ifstream bsFile("allBookShelf.txt");

	std::string str;
	while (bsFile.is_open()) //Duyệt từng file kệ sách
	{
		while (std::getline(bsFile, str))
		{
			str += ".txt";
			bookList bl = bookList_Get(str);

			for (book* b = bl.firstBook; b != NULL; b = b->Next)
			{
				if (stringCompare(b->author, info))
				{
					std::cout << "\n-----------------------------------";
					bookPrint(b);
				}
			}
			bookList_Free(bl);
		}
		bsFile.close();
	}
}

void browse_Publisher(std::string info)
{
	std::ifstream bsFile("allBookShelf.txt");

	std::string str;
	while (bsFile.is_open()) //Duyệt từng file kệ sách
	{
		while (std::getline(bsFile, str))
		{
			str += ".txt";
			bookList bl = bookList_Get(str);

			for (book* b = bl.firstBook; b != NULL; b = b->Next)
			{
				if (stringCompare(b->publisher, info))
				{
					std::cout << "\n-----------------------------------";
					bookPrint(b);
				}
			}
			bookList_Free(bl);
		}
		bsFile.close();
	}
}

void browse_PublishDate(std::string info)
{
	std::ifstream bsFile("allBookShelf.txt");

	std::string str;
	while (bsFile.is_open()) //Duyệt từng file kệ sách
	{
		while (std::getline(bsFile, str))
		{
			str += ".txt";
			bookList bl = bookList_Get(str);

			for (book* b = bl.firstBook; b != NULL; b = b->Next)
			{
				if (b->publishDate == info)
				{
					std::cout << "\n-----------------------------------";
					bookPrint(b);
				}
			}
			bookList_Free(bl);
		}
		bsFile.close();
	}
}


void bookFind()
{
	system("cls");
	std::cout << "\n1.Tillte";
	std::cout << "\n2.Subject";
	std::cout << "\n3.Author";
	std::cout << "\n4.Publisher";
	std::cout << "\n5.Publish date";
	std::cout << "\n6.Back to menu";

choose:
	std::cout << "\n\nChoose which you want to find: ";
	fflush(stdin);
	std::string inp;
	std::cin >> inp;

	if (inp.size() > 1 || inp[0] < 1 || inp[0] > '6')
	{
		std::cout << "\nInvalid type, choose again";
		goto choose;
	}
	char c = (char)inp[0];

	std::string find;
	switch (c)
	{
	case '1':
		std::cout << "\nFind tille: ";
		std::cin.ignore();
		std::getline(std::cin, find);
		browse_Tittle(find);
		break;
	case '2':
		std::cout << "\nFind subject: ";
		std::cin.ignore();
		std::getline(std::cin, find);
		browse_Subject(find);
		break;
	case '3':
		std::cout << "\nFind author: ";
		std::cin.ignore();
		std::getline(std::cin, find);
		browse_Author(find);
		break;
	case '4':
		std::cout << "\nFind publisher: ";
		std::cin.ignore();
		std::getline(std::cin, find);
		browse_Publisher(find);
		break;
	case '5':
		std::cout << "\nFind publish date: ";
		std::cin.ignore();
		std::getline(std::cin, find);
		browse_PublishDate(find);
		break;
	}

	std::cout << "\n\n";
	system("pause");
}

void bookDelete()
{
	system("cls");
	bookShelf_ShowAll();
	bookDelete(bookList_Link());
}

void bookReplace()
{
	system("cls");
	bookShelf_ShowAll();
	bookModify(bookList_Link());
}

void bookAdd()
{
	system("cls");
	bookShelf_ShowAll();
	bookList_Add(bookList_Link());
}

void bookDisplay()
{
	system("cls");
	bookShelf_ShowAll();
	bookList_ShowAll(bookList_Link());
}

bool stringCompare(std::string book, std::string info)
{
	int i = 0;
	while (info[i])
	{
		int compare = (int)info[i] - (int)book[i];
		if (compare != 0 && compare != -32 && compare != 32)
		{
			return false;
		}
		++i;
	}
	return true;
}

