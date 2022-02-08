#pragma once
#ifndef __FUBAOTIME_H__
#define __FUBAOTIME_H__
#define SEC 3		// 지연시간 3초
#include <ctime>

void Fubaotime()
{
	clock_t secs = CLOCKS_PER_SEC * SEC;
	clock_t start = clock();
	// 지금까지 프로그램이 경과한 시간을 새로 clock()로 빼서 0초로 만든다.
	while (clock() - start < secs)		// 시간이 경과할 때까지 대기
		;								// 세미콜론에 유의
}

#endif