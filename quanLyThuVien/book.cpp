//#include <iostream>
#include "book.h"

void bookEnter(book *b)
{	
	std::cin.ignore();
	std::cout << "\nEnter isbn: ";
	std::getline(std::cin, b->isbn);

	fflush(stdin);
	std::cout << "Enter tittle: ";
	std::getline(std::cin, b->tittle);

	fflush(stdin);
	std::cout << "Enter subject: ";
	std::getline(std::cin, b->subject);

	fflush(stdin);
	std::cout << "Enter author: ";
	std::getline(std::cin, b->author);

	fflush(stdin);
	std::cout << "Enter publisher: ";
	std::getline(std::cin, b->publisher);

	dateEnter(b->publishDate);

	std::cout << "Enter number of pages: ";
	std::cin >> b->pages;

	std::cout << "Enter number of copies: ";
	std::cin >> b->copies;

	b->Next = NULL;
}

void bookPrint(book *b)
{
	std::cout << "\n1.The International Standard Book Number: " << b->isbn;
	std::cout << "\n2.Tillte: " << b->tittle;
	std::cout << "\n3.Subject: " << b->subject;
	std::cout << "\n4.Author: " << b->author;
	std::cout << "\n5.Publisher: " << b->publisher;
	std::cout << "\n6.Publish date: " << b->publishDate;
	std::cout << "\n7.Number of pages: " << b->pages;
	std::cout << "\n8.Copies: " << b->copies;
}

void bookList_Init(bookList& bl)
{
	bl.firstBook = NULL;
	bl.lastBook = NULL;
}

void Add(bookList& bl, book *b)
{
	if (bl.firstBook == NULL)
	{
		bl.firstBook = bl.lastBook = b;
	}
	else
	{
		bl.lastBook->Next = b;
		bl.lastBook = b;
	}
}

void bookList_Free(bookList& bl)
{
	book* b;
	while (bl.firstBook != NULL)
	{
		b = bl.firstBook;
		bl.firstBook = bl.firstBook->Next;
		delete b;
	}
}

bookList bookList_Get(std::string blLink)
{
	bookList bl;
	bookList_Init(bl);

	std::ifstream blFile(blLink);
	std::string bookInfo;
	while (blFile.is_open())
	{
		while (std::getline(blFile, bookInfo))
		{
			book* tmpBook = new book;
			tmpBook->Next = NULL;

			std::getline(blFile, bookInfo);
			tmpBook->isbn = bookInfo;

			std::getline(blFile, bookInfo);
			tmpBook->tittle = bookInfo;

			std::getline(blFile, bookInfo);
			tmpBook->subject = bookInfo;

			std::getline(blFile, bookInfo);
			tmpBook->author = bookInfo;

			std::getline(blFile, bookInfo);
			tmpBook->publisher = bookInfo;

			std::getline(blFile, bookInfo);
			tmpBook->publishDate = bookInfo;

			std::getline(blFile, bookInfo);
			tmpBook->pages = atoi((char *)bookInfo.c_str());

			std::getline(blFile, bookInfo);
			tmpBook->copies = atoi((char*)bookInfo.c_str());

			Add(bl, tmpBook);
		}
		blFile.close();
	}
	return bl;
}

void bookList_ShowAll(std::string blLink)
{
	std::ifstream blFile(blLink);
	std::string bookInfo;
	while (blFile.is_open())
	{
		while (std::getline(blFile, bookInfo))
		{
			std::cout << "\n" << bookInfo;

			std::getline(blFile, bookInfo);
			std::cout << "\nThe International Standard Book Number: ";
			std::cout << bookInfo;

			std::getline(blFile, bookInfo);
			std::cout << "\nTittle: ";
			std::cout << bookInfo;

			std::getline(blFile, bookInfo);
			std::cout << "\nSubject: ";
			std::cout << bookInfo;

			std::getline(blFile, bookInfo);
			std::cout << "\nAuthor: ";
			std::cout << bookInfo;

			std::getline(blFile, bookInfo);
			std::cout << "\nPublisher: ";
			std::cout << bookInfo;

			std::getline(blFile, bookInfo);
			std::cout << "\nDate: ";
			std::cout << bookInfo;

			std::getline(blFile, bookInfo);
			std::cout << "\nNumber of pages: ";
			std::cout << bookInfo;

			std::getline(blFile, bookInfo);
			std::cout << "\nNumber of copies: ";
			std::cout << bookInfo;
		}
		blFile.close();
	}
	
	std::cout << "\n\n";
	system("pause");
}

void bookList_Add(std::string blLink)
{
	bookList bl = bookList_Get(blLink); //Lấy danh sách xử lý
	book* tmpBook = new book;

	bookEnter(tmpBook); //Nhập sách 
	Add(bl, tmpBook);

	std::ofstream blFile(blLink); //Mở file 
	while (blFile.is_open()) //Chèn thông tin sách mới vào
	{
		for (book* tmp = bl.firstBook; tmp != NULL; tmp = tmp->Next)
		{
			blFile << "-----------------------------------\n";
			blFile << tmp->isbn << std::endl;
			blFile << tmp->tittle << std::endl;
			blFile << tmp->subject << std::endl;
			blFile << tmp->author << std::endl;
			blFile << tmp->publisher << std::endl;
			blFile << tmp->publishDate << std::endl;
			blFile << tmp->pages << std::endl;
			blFile << tmp->copies << std::endl;
		}
		blFile.close();
	}

	bookList_Free(bl); //Giải phóng bộ nhớ
}

void book_Modify(book *b)
{
	bookPrint(b);
	
choose:
	std::string inp;
	std::cout << "\nChoose propertise (1->8) you want to modify, '9' to back: ";
	std::cin >> inp;

	if (inp.size() > 1 || inp.size() <= 0)
	{
		std::cout << "\nInvalid type, choose again";
		goto choose;
	}
	char c = (char)inp[0];
	
	std::string tmp;
	switch (c)
	{
	case '1':
		std::cout << "\nNew isbn is: ";
		std::cin >> tmp;
		b->isbn = tmp;
		break;
	case '2':
		std::cout << "\nNew titlle is: ";
		std::cin >> tmp;
		b->tittle = tmp;
		break;
	case '3':
		std::cout << "\nNew subject is: ";
		std::cin >> tmp;
		b->subject = tmp;
		break;
	case '4':
		std::cout << "\nNew author is: ";
		std::cin >> tmp;
		b->author = tmp;
		break;
	case '5':
		std::cout << "\nNew publisher is: ";
		std::cin >> tmp;
		b->publisher = tmp;
		break;
	case '6':
		std::cout << "\nNew publish date is: ";
		std::cin >> tmp;
		b->publishDate = tmp;
		break;
	case '7':
		std::cout << "\nNew number of pages is: ";
		std::cin >> tmp;
		b->pages = atoi((char *)tmp.c_str());
		break;
	case '8':
		std::cout << "\nNew number of copies is: ";
		std::cin >> tmp;
		b->copies = atoi((char*)tmp.c_str());
		break;
	case '9':
		return;
		break;
	}
}

void bookModify(std::string blLink)
{
	bookList_ShowAll(blLink);
	bookList bl = bookList_Get(blLink);

	std::string bookIsbn;
	std::cout << "\n\nType book's isbn to modify: ";
	std::cin >> bookIsbn;

	bool check = true; //Check xem có tìm thấy mã sách ko
	for (book* tmp = bl.firstBook; tmp != NULL; tmp = tmp->Next)
	{
		if (tmp->isbn == bookIsbn)
		{
			book_Modify(tmp);
			check = false; //Đã tìm thấy sack
			break;
		}
	}
	if (check)
	{
		std::cout << "\nBook not found";
	}

	std::ofstream blFile(blLink); //Mở file 
	while (blFile.is_open()) //Chèn thông tin sách mới vào
	{
		for (book* tmp = bl.firstBook; tmp != NULL; tmp = tmp->Next)
		{
			blFile << "-----------------------------------\n";
			blFile << tmp->isbn << std::endl;
			blFile << tmp->tittle << std::endl;
			blFile << tmp->subject << std::endl;
			blFile << tmp->author << std::endl;
			blFile << tmp->publisher << std::endl;
			blFile << tmp->publishDate << std::endl;
			blFile << tmp->pages << std::endl;
			blFile << tmp->copies << std::endl;
		}
		blFile.close();
	}

	bookList_Free(bl);
}

void bookDelete(std::string blLink)
{
	bookList_ShowAll(blLink);
	bookList bl = bookList_Get(blLink);

	std::string bookIsbn;
	std::cout << "\n\nType book's isbn you want to delete: ";
	std::cin >> bookIsbn;

	bool check = true; //Kiểm tra tìm thấy sách
	if (bl.firstBook->Next == NULL)
	{
		if (bl.firstBook->isbn == bookIsbn)
		{
			std::ofstream blFile(blLink);
			blFile.clear();
			blFile.close();
			
			bookList_Free(bl);
			return;
		}
	}
	else
	{
		for (book* b = bl.firstBook; b != NULL; b = b->Next)
		{
			if (b->Next->isbn == bookIsbn)
			{
				book* tmp;
				tmp = b->Next;
				b->Next = tmp->Next;
				delete tmp;

				check = false; //Đã tìm thấy sách
				break;
			}
		}
	}
	
	if (check) std::cout << "\nBook not found";

	std::ofstream blFile(blLink); //Mở file 
	while (blFile.is_open()) //Chèn thông tin sách mới vào
	{
		for (book* b = bl.firstBook; b != NULL; b = b->Next)
		{
			blFile << "-----------------------------------\n";
			blFile << b->isbn << std::endl;
			blFile << b->tittle << std::endl;
			blFile << b->subject << std::endl;
			blFile << b->author << std::endl;
			blFile << b->publisher << std::endl;
			blFile << b->publishDate << std::endl;
			blFile << b->pages << std::endl;
			blFile << b->copies << std::endl;
		}
		blFile.close();
	}

	bookList_Free(bl);
}






