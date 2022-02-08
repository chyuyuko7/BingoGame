#pragma once
#ifndef __BSTRING_H__
#define __BSTRING_H__
#include <iostream>

class bstring
{
private:
	char* ptr;
	int len;
public:
	bstring(void);
	bstring(const char* ptr);
	bstring(const bstring& str);
	~bstring();

	bstring& operator=(const bstring& str);
	bstring& operator=(const int num);
	bstring operator+(const bstring& str);
	friend void operator+=(bstring& str1, const bstring& str2);
	bool operator==(const bstring& str) const;
	bool operator!=(const bstring& str) const;

	friend std::ostream& operator<<(std::ostream& os, const bstring& str1);
	friend std::istream& operator>>(std::istream& is, bstring& str1);
};

#endif