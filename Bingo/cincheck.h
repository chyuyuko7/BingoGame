#pragma once
#ifndef __CINCHECK_H__
#define __CINCHECK_H__
#include <iostream>
void InitMessegi()
{
	std::cout << "## 잘못된 입력 ##" << '\n';
	std::cout << "## 3초후 다시 입력##" << '\n';
	std::cin.clear();
	std::cin.ignore(1000, '\n');
}
#endif