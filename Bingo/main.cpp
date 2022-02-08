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
	cout << "������ ������ ũ�⸦ �Է��ϼ��� (ex. 5x5 = 5 || ũ�� 3~9 ����)\n";
	cout << "ũ��: ";
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
		cout << "üũ�� ��ȣ �Է�: ";
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
			cout << "## 1ȸ �̻� �ߺ� �Ұ� ##" << '\n';
			cout << "## 3���� �ٽ� �Է� ##" << '\n';
			Fubaotime();
			goto again;
		}
		cpuNum = bingo.SimpleAi();
		if (!bingo.ShowThreeNumber(num, cpuNum, player, CPU))			// ��ǻ�Ϳ� �Է� ���ڰ� ������ ���
		{
			goto again;
		}
		state = bingo.CheckState();										// ��ȣ üũ�� ���� ���� Ȯ��
		if (state)
		{
			cout << bingo;
			if (state == P1_ROW_WIN) cout << "## Player ���� ����! ##\n##  �� ��  ## \n\n";
			else if (state == P2_ROW_WIN) cout << "## CPU ���� ����! ##\n##  �� ��  ## \n\n";
			else if (state == P1_COLUMN_WIN) cout << "## Player ���� ����! ##\n##  �� ��  ## \n\n";
			else if (state == P2_COLUMN_WIN) cout << "## CPU ���� ����! ##\n##  �� ��  ## \n\n";
			else if (state == P1_DIAGONAL_WIN) cout << "## Player �밢�� ����! ##\n##  �� ��  ## \n\n";
			else if (state == P2_DIAGONAL_WIN) cout << "## CPU �밢�� ����! ##\n##  �� ��  ## \n\n";
			break;
		}
	}

	return 0;
}