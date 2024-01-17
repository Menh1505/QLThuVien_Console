#pragma once

#include "book.h"

std::vector<std::string> bookShelf_Get();
void bookShelf_ShowAll();
void bookShelf_Delete();
void bookShelf_Add();

std::string bookList_Link();

void browse_Tittle(std::string);
void browse_Subject(std::string);
void browse_Author(std::string);
void browse_Publisher(std::string);
void browse_PublishDate(std::string);
void bookFind();
void bookDelete();
void bookReplace();
void bookAdd();
void bookDisplay();

bool stringCompare(std::string, std::string);