#pragma once
#ifndef __FUBAOTIME_H__
#define __FUBAOTIME_H__
#define SEC 3		// �����ð� 3��
#include <ctime>

void Fubaotime()
{
	clock_t secs = CLOCKS_PER_SEC * SEC;
	clock_t start = clock();
	// ���ݱ��� ���α׷��� ����� �ð��� ���� clock()�� ���� 0�ʷ� �����.
	while (clock() - start < secs)		// �ð��� ����� ������ ���
		;								// �����ݷп� ����
}

#endif