#pragma once
#ifndef __BINGO_H__
#define __BINGO_H__
#include <iostream>
#include <string>
#include <cstdlib>
#include "player.h"
#include "fubaotime.h"

using std::string;

class BinGo
{
private:
	int** matrix;
	int len;
public:
	BinGo();
	~BinGo();
	void Deliver(int num, Player& player);
	bool ShowThreeNumber(const int, const int, Player&, Player&);
	const int CheckState(void) const;
	int SimpleAi();
	BinGo* operator=(const int& ln);
	friend std::ostream& operator<<(std::ostream& os, BinGo& bingo);
};

BinGo::BinGo()			// ������
	: len(0)
{
	matrix = nullptr;
}

BinGo::~BinGo()			// �Ҹ���
{
	if (matrix != nullptr)
	{
		for (int i = 0; i < len; i++)
			delete matrix[i];
		delete[] matrix;
	}
}

void BinGo::Deliver(int num, Player& player)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (matrix[i][j] == num)
			{
				if (player.ShowMyPosition())
					matrix[i][j] = 79;
				else
					matrix[i][j] = 88;
				return;
			}
		}
	}
	return;
}

bool BinGo::ShowThreeNumber(const int num1, const int num2, Player& player, Player& cpu)
{
	using std::cout;
	int i = 0;
	int temp;
	int* n = new int[len];
	bool check = false;
	bool check2 = false;

	cout << '\n';
	cout << "## ��÷ ��ȣ ##" << '\n';
	cout << "[ ";
	while (1)
	{
		again:
		temp = matrix[rand() % len][rand() % len];
		if (temp == 88 || temp == 79)
			goto again;
		for (int x = 0; x < len; x++)
			if (temp == n[x])
				check2 = true;
		if (!check2)
		{
			cout << temp << ' ';
			n[i] = temp;
			++i;
		}
		if (i == len) break;
		check2 = false;
	}
	cout << "]" << '\n' << '\n';
	cout << "Player�� ������ ��ȣ: " << num1 << '\n';
	cout << "CPU�� ������ ��ȣ: " << num2 << '\n';
	cout << '\n';

	if (num1 == num2)
	{
		cout << "## Player, CPU ������ ��ȣ �ߺ� ##\n";
		cout << "## 3���� �ٽ� �Է� ##" << '\n';
		Fubaotime();
		return false;										// üũ ����
	}

	for (int i = 0; i < 3; i++)
	{
		if (n[i] == num1)
		{
			cout << "## Player ��ȣ ��÷! ##\n";
			cout << "## ��" << num1 << "�� üũ �Ϸ� ##\n";
			Deliver(num1, player);
			check = true;
		}
		if (n[i] == num2)
		{
			cout << "## CPU�� ��ȣ ��÷! ##\n";
			cout << "## ��" << num2 << "�� üũ �Ϸ� ##\n";
			Deliver(num2, cpu);
			check = true;
		}
	}
	if (!check)
	{
		std::cin.clear();
		std::cin.ignore(10, '\n');
		cout << "## ��÷�� ��ȣ�� �����ϴ�. ##" << '\n';
		cout << "## 3�� �� �ٽ� �Է� ##" << '\n';
		Fubaotime();
		return false;
	}

	Fubaotime();
	return true;											// üũ ����
	delete[]n;
}

const int BinGo::CheckState(void) const
{
	int player1 = 0;
	int player2 = 0;
	const int P1_ROW_WIN = 111;
	const int P2_ROW_WIN = 222;
	const int P1_COLUMN_WIN = 1111;
	const int P2_COLUMN_WIN = 2222;
	const int P1_DIAGONAL_WIN = 11111;
	const int P2_DIAGONAL_WIN = 22222;
	
	for (int i = 0; i < len; i++)								// ���� �˻�
	{
		for (int j = 0; j < len; j++)
		{
			if (matrix[i][j] == 79) player1 += 1;
			if (matrix[i][j] == 88) player2 += 1;
		}
		if (player1 == len) return P1_ROW_WIN;
		if (player2 == len) return P2_ROW_WIN;
		player1 = 0;
		player2 = 0;
	}

	for (int width = 0; width < len; width++)					// ���� �˻�
	{
		for (int height = 0; height < len; height++)
		{
			if (matrix[height][width] == 79) player1 += 1;
			if (matrix[height][width] == 88) player2 += 1;
		}
		if (player1 == len) return P1_COLUMN_WIN;
		if (player2 == len) return P2_COLUMN_WIN;
		player1 = 0;
		player2 = 0;
	}

	for (int i = 0; i < len; i++)								// �밢�� �˻� 
	{
		if (matrix[i][i] == 79) player1 += 1;
		if (matrix[i][i] == 88) player2 += 1;
	}
	if (player1 == len) return P1_DIAGONAL_WIN;
	if (player2 == len) return P2_DIAGONAL_WIN;
	player1 = 0;
	player2 = 0;

	for (int x = len - 1, y = 0; x >= 0 && y < len; x--, y++)	// �밢�� �˻�
	{
		if (matrix[y][x] == 79) player1 += 1;
		if (matrix[y][x] == 88) player2 += 1;
	}
	if (player1 == len) return P1_DIAGONAL_WIN;
	if (player2 == len) return P2_DIAGONAL_WIN;
	player1 = 0;
	player2 = 0;

	return 0;
}

int BinGo::SimpleAi()
{
	int temp;
	while (1)
	{
	again:
		temp = matrix[rand() % len][rand() % len];
		if (temp == 88 || temp == 79)
			goto again;
		return temp;
	}
}


BinGo* BinGo::operator=(const int& ln)
{
	int arrlen, num;		// num�� ���� ���� �������� �����ϴ� ����
	arrlen = ln;
	if (matrix != nullptr)
	{
		for (int i = 0; i < len; i++)
			delete matrix[i];
		delete[] matrix;
	}
	len = arrlen;
	matrix = new int* [arrlen + 1];
	for (int i = 0; i < len; i++)
		matrix[i] = new int[arrlen + 1];

	srand(static_cast<unsigned int>(time(nullptr)));		// �ð��� �̿��� ������ �ʱ�ȭ�Ѵ�.
	for (int height = 0; height < len; height++)			// �������� �����.
	{
		for (int width = 0; width < len; width++)
		{
		again:												// ���� �ߺ��� Ȯ�ε� ��� ��������
			num = rand() % (arrlen * arrlen) + 1;			// ����� ���̺��� ���� ����
			for (int i = 0; i < len; i++)					// ���� �ߺ� �˻� ����
			{
				for (int j = 0; j < len; j++)
				{
					if (num == matrix[i][j])				// ���� �ߺ� ����
						goto again;
				}
			}
			matrix[height][width] = num;					// �ߺ��� ���� ������ ��� �����ǿ� ����
		}
	}
	return this;
}

std::ostream& operator<<(std::ostream& os, BinGo& bingo)
{
	system("cls");
	printf("------------------------------------------\n");
	printf("               B I N G O                  \n");
	printf("------------------------------------------\n\n");
	for (int i = 0; i < bingo.len; i++)
	{
		for (int j = 0; j < bingo.len; j++)
		{
			if(bingo.matrix[i][j] == 79) 
				printf("%5s ", "��");
			if(bingo.matrix[i][j] == 88)
				printf("%5s ", "��");
			if(bingo.matrix[i][j] != 79 && bingo.matrix[i][j] != 88)
				printf("%5d ", bingo.matrix[i][j]);
		}
		printf("\n\n");
	}
	printf("------------------------------------------\n");
	return os;
}
#endif