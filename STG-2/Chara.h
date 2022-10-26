#pragma once
#include "main.h"
#include "Bomb.h"

#define CHARA_FIRST_LIFE	3

class Chara
{
public:	
	Chara();

	int x, y;

	void draw_chara();

private:
	int life;
	int score;


};

