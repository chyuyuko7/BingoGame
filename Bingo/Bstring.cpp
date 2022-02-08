#include <iostream>
#include <cstring>
#include <cctype>
#include "bstring.h"

bstring::bstring()
{
	ptr = nullptr;
	len = 0;
}
bstring::bstring(const char* ptr)						// 생성자
{
	len = strlen(ptr) + 1;
	this->ptr = new char[len];
	strcpy(this->ptr, ptr);
}

bstring::~bstring()										 // 소멸자
{
	if (ptr != nullptr)
		delete[]ptr;
}

bstring& bstring::operator=(const bstring& str)			 // 같은 bstring끼리 대입 연산 
{
	if (ptr != nullptr)
		delete[]ptr;
	len = strlen(str.ptr) + 1;
	ptr = new char[len];
	strcpy(ptr, str.ptr);
	return *this;
}

bstring& bstring::operator=(const int num)				// 상수를 ptr에 저장
{
}

void operator+=(bstring& str1, const bstring& str2)
{
	char* tempstr = new char[(str1.len + str2.len) - 1];
	strcpy(tempstr, str1.ptr);
	strcat(tempstr, str2.ptr);

	if (str1.ptr != nullptr)
		delete[]str1.ptr;
	str1.len = (str1.len + str2.len) - 1;
	str1.ptr = new char[str1.len];
	strcpy(str1.ptr, tempstr);
	delete[]tempstr;
}

bstring bstring::operator+(const bstring& str)
{
	char* tempstr = new char[(len + str.len) - 1];
	strcpy(tempstr, ptr);
	strcat(tempstr, str.ptr);
	return bstring(tempstr);
}

bool bstring::operator==(const bstring& str) const
{
	if (!strcmp(ptr, str.ptr))
		return true;
	else
		return false;
}

bool bstring::operator!=(const bstring& str) const
{
	if (strcmp(ptr, str.ptr))
		return true;
	else
		return false;
}

std::ostream& operator<<(std::ostream& os, const bstring& str1)
{
	os << str1.ptr;
	return os;
}

std::istream& operator>>(std::istream& is, bstring& str1)
{
	char str[100];
	is >> str;
	str1 = bstring(str);
	return is;
}