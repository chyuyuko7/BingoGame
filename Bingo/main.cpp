#include <iostream>
#include "Bingo.h"
#include "cincheck.h"

#define P1_ROW_WIN 111
#define P2_ROW_WIN 222
#define P1_COLUMN_WIN 1111
#define P2_COLUMN_WIN 2222
#define P1_DIAGONAL_WIN 11111
#define P2_DIAGONAL_WIN 22222

int main(void)
{
	using namespace std;
	int len, num, cpuNum;
	int state;
	int count = -98765;
	BinGo bingo;

start:
	system("cls");
	cout << "생성할 빙고의 크기를 입력하세요 (ex. 5x5 = 5 || 크기 3~9 까지)\n";
	cout << "크기: ";
	cin >> len;
	while ((!cin >> len) || len >= 9 || len < 3)
	{
		if (!cin.good())
		{
			InitMessegi();
			Fubaotime();
			goto start;
		}
	}
	bingo = len;
	Player player(len, true);
	Player CPU(len, false);

	while (1)
	{
		again:
		cout << bingo;
		cout << "체크할 번호 입력: ";
		while (!(cin >> num))
		{
			InitMessegi();
			Fubaotime();
			goto again;
		}
		if (count != num)
		{
			count = num;
		}
		else if (num == count)
		{
			num = -98765;
			cout << "## 1회 이상 중복 불가 ##" << '\n';
			cout << "## 3초후 다시 입력 ##" << '\n';
			Fubaotime();
			goto again;
		}
		cpuNum = bingo.SimpleAi();
		if (!bingo.ShowThreeNumber(num, cpuNum, player, CPU))			// 컴퓨터와 입력 숫자가 동일할 경우
		{
			goto again;
		}
		state = bingo.CheckState();										// 번호 체크후 승패 여부 확인
		if (state)
		{
			cout << bingo;
			if (state == P1_ROW_WIN) cout << "## Player 가로 빙고! ##\n##  승 리  ## \n\n";
			else if (state == P2_ROW_WIN) cout << "## CPU 가로 빙고! ##\n##  패 배  ## \n\n";
			else if (state == P1_COLUMN_WIN) cout << "## Player 세로 빙고! ##\n##  승 리  ## \n\n";
			else if (state == P2_COLUMN_WIN) cout << "## CPU 세로 빙고! ##\n##  패 배  ## \n\n";
			else if (state == P1_DIAGONAL_WIN) cout << "## Player 대각선 빙고! ##\n##  승 리  ## \n\n";
			else if (state == P2_DIAGONAL_WIN) cout << "## CPU 대각선 빙고! ##\n##  패 배  ## \n\n";
			break;
		}
	}

	return 0;
}