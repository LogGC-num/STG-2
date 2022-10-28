#include "Chara.h"
#include "Bomb.h"

extern int cWhite;


Chara::Chara() {
	pos.x = 150;
	pos.y = 600;
	life = CHARA_FIRST_LIFE;
	score = 0;
}

void Chara::draw_chara() {
	DrawBox((int)pos.x, (int)pos.y, (int)pos.x + 25, (int)pos.y + 60, cWhite, FALSE);
}

void Chara::check_hit(POS pos,int size) {

}