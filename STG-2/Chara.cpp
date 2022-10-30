#include "Chara.h"
#include "Bomb.h"

extern int cWhite;

#define CHARA_SIZE_HEIGHT	60
#define CHARA_SIZE_WIDTH	25

Chara::Chara() {
	pos.x = 150;
	pos.y = 600;
	life = CHARA_FIRST_LIFE;
	score = 0;
}

void Chara::draw_chara() {
	DrawBox((int)pos.x, (int)pos.y, (int)pos.x + 25, (int)pos.y + 60, cWhite, FALSE);
	DrawCircle((int)(pos.x + CHARA_SIZE_WIDTH / 2), (int)(pos.y + CHARA_SIZE_HEIGHT / 2), CHARA_HIT_CIRCLE, cWhite, TRUE, TRUE);
}
/*
void Chara::check_hit(POS pos,int size) {

}
*/