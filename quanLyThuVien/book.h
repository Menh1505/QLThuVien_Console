#pragma once

#include "date.h"
#include <fstream>
#include <cstdio>
#include <vector>
#include <Windows.h>

struct book
{
	std::string isbn; //Mã số
	std::string tittle; //Tên sách
	std::string subject; //Chủ đề
	std::string author;	//Tác giả	
	std::string publisher; //Nhà xuất bản
	std::string publishDate; //Ngày tháng xuất bản
	int  pages; //Số trang
	int copies; //Số bản copies trong thư viện

	book* Next;
};

struct bookList
{
	book *firstBook;
	book *lastBook;
};

void bookEnter(book *);
void bookPrint(book *);
void bookList_Init(bookList &);
void Add(bookList &, book);
void bookList_Free(bookList &);

bookList bookList_Get(std::string);
void bookList_ShowAll(std::string);
void bookList_Add(std::string);
void book_Modify(book *);
void bookModify(std::string);
void bookDelete(std::string);


