#pragma once
#ifndef __CINCHECK_H__
#define __CINCHECK_H__
#include <iostream>
void InitMessegi()
{
	std::cout << "## �߸��� �Է� ##" << '\n';
	std::cout << "## 3���� �ٽ� �Է�##" << '\n';
	std::cin.clear();
	std::cin.ignore(1000, '\n');
}
#endif