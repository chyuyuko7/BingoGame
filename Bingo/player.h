#pragma once
#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <iostream>
#include "Bingo.h"

class Player
{
private:
	int* myNumber;
	int count;		
	bool position;
public:
	Player(int len, bool position);

	bool ShowMyPosition(void);
	void operator=(int num);
};

Player::Player(int len, bool select)
	:position(select), count(0)
{
	myNumber = new int[(len * len) + 1];
}

bool Player::ShowMyPosition()
{
	return position;
}

void Player::operator=(int num)
{
	myNumber[count] = num;
	++count;
}

#endif