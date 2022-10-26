#include "main.h"



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetUp();
	Bomb bomb[BOMB_MAX];
	for (int i = 0; i < BOMB_MAX; i++) {
		bomb[i] = Bomb();
	}
	Chara chara = Chara();

	int cnt = 0;
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {
		Update();
		Draw();
		clsDx();
		if (cnt % 30 == 0) {
			POS makepos = { 300,100 };
			make_circle(bomb, makepos, 32, BOMB_SPEED_TYPE_SLOWER, BOMB_ANGLE_TYPE_CIRCLE,1);
			make_beam(bomb, makepos, 8, BOMB_SPEED_TYPE_SAME, TAU * 3 / 8, BOMB_ANGLE_TYPE_SAME);
			make_beam(bomb, makepos, 8, BOMB_SPEED_TYPE_SAME, TAU * 2 / 8, BOMB_ANGLE_TYPE_SAME);
			make_beam(bomb, makepos, 8, BOMB_SPEED_TYPE_SAME, TAU * 1 / 8, BOMB_ANGLE_TYPE_SAME);

		}
//		bomb.draw_debug_bomb();
		for (int i = 0; i < BOMB_MAX; i++) {
			bomb[i].draw_bomb();
			bomb[i].move_bomb();
		}

		chara.draw_chara();

		printfDx("%d", cnt);
		cnt++;
		Wait();
	}
	DxLib_End();
	return 0;
}