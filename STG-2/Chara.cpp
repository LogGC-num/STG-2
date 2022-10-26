#include "Chara.h"

extern int cWhite;



Chara::Chara() {
	x = 150;
	y = 600;
	life = CHARA_FIRST_LIFE;
	score = 0;
}

void Chara::draw_chara() {
	DrawBox(x, y, x + 25, y + 60, cWhite, FALSE);
}