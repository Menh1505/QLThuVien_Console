#define _CRT_SECURE_NO_WARNINGS //bỏ thông báo bảo mật khi dùng hàm lấy thông tin system
#include "date.h"

bool checkDate(std::string d)
{
	time_t curr_time = time(NULL);
	tm* Now = std::localtime(&curr_time);

	int yyyy = (int)(d[6] - '0') * 1000 + (int)(d[7] - '0') * 100 + (int)(d[8] - '0') * 10 + (int)(d[9] - '0'); //lấy năm từ chuỗi
	//if (d.yyyy < 0 || d.yyyy > Now->tm_year) return false; //Kiểm tra năm

	bool leapYear = false; //Kiểm tra năm nhuận
	if (yyyy % 4 == 0 || yyyy % 400 == 0) leapYear = true;

	int mm = (int)(d[3] - '0') * 10 + (int)(d[4] - '0'); //lấy tháng từ chuỗi
	if (mm < 1 || mm > 12) return false; //Kiểm tra tháng

	int dd = (int)(d[0] - '0') * 10 + (int)(d[1] - '0'); //lấy ngày từ chuỗi
	if (dd < 1) return false; //Kiểm tra ngày
	if (mm == 2)
	{
		if (leapYear && dd > 29) return false;
		else if (dd > 28) return false;
	}
	else if (mm == 4 || mm == 6 || mm == 9 || mm == 11)
	{
		if (dd > 30) return false;
	}
	else if (dd > 31) return false;

	return true;
}

bool checkString(std::string inp)
{
	if (inp.length() != 10) return false;

	if (inp[2] != '/' || inp[5] != '/')
	{
		return false;
	}

	for (int i = inp.length() - 1; i >= 0; --i) //kiểm tra ký tự khác ký tự trong form
	{
		if (inp[i] < '0' || inp[i] > '9')
		{
			if (i == 2 || i == 5) continue;
			return false;
		}
	}

	return true;
}

void dateEnter(std::string &date)
{
dateEnter:
	fflush(stdin);
	std::cout << "Enter date with form DD/MM/YYYY: ";
	std::cin >> date;

	if (!(checkString(date) && checkDate(date)))
	{ 
		std::cout << "Invalid date. Enter again please\n";
		goto dateEnter;
	}
}

