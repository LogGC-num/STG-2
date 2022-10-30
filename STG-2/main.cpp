#include "main.h"

extern int cWhite;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetUp();
	Bomb bomb[BOMB_MAX];
	for (int i = 0; i < BOMB_MAX; i++) {
		bomb[i] = Bomb();
	}
	Chara chara = Chara();
	UI ui = UI();

	int cnt = 0;
	int bomb_cnt = 0;
	int push_cnt = 0;
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {
		Update();
		Draw();
		clsDx();
		ui.draw_UIbox();
		bomb_cnt = 0;		//Debug
		if (cnt % 30 == 0) {
			push_cnt++;
			POS makepos = { 300,100 };
			if (push_cnt % 2 == 0) {
				make_circle(bomb, makepos, 32, BOMB_SPEED_TYPE_SLOWER, BOMB_ANGLE_TYPE_CIRCLE, 1);
			}
			else {
				make_circle(bomb, makepos, 32, BOMB_SPEED_TYPE_SLOWER, BOMB_ANGLE_TYPE_CIRCLE, -1);
			}
			
//			make_beam(bomb, makepos, 8, BOMB_SPEED_TYPE_SAME, TAU * 3 / 8, BOMB_ANGLE_TYPE_SAME);
//			make_beam(bomb, makepos, 8, BOMB_SPEED_TYPE_SAME, TAU * 2 / 8, BOMB_ANGLE_TYPE_SAME);
//			make_beam(bomb, makepos, 8, BOMB_SPEED_TYPE_SAME, TAU * 1 / 8, BOMB_ANGLE_TYPE_SAME);

		}
//	bomb.draw_debug_bomb(bomb_cnt);
		for (int i = 0; i < BOMB_MAX; i++) {
			bomb[i].draw_bomb();
			bomb[i].move_bomb();
			if (bomb[i].isUse == true) {
				bomb_cnt++;
			}
		}

		DrawFormatString(750, 20, cWhite, "%d", bomb_cnt);

		chara.draw_chara();


		printfDx("%d", cnt);
		cnt++;
		Wait();
	}
	DxLib_End();
	return 0;
}