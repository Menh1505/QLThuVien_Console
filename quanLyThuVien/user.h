#pragma once

#include <iostream>
#include <string>
struct user
{
	std::string userID;
	std::string userName;
	std::string password;
};

bool userLogin();
