#include "main.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetUp();
	Bomb bomb[1000];
	for (int i = 0; i < 1000; i++) {
		bomb[i] = Bomb();
	}

	int cnt = 0;
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {
		Update();
		Draw();
		clsDx();
		if (cnt % 30 == 0) {
			POS makepos = { 100,100 };
			make_circle(bomb,makepos,8,1,0,1);
			make_circle(bomb, makepos, 8, 1, 1, -1);
		}
//		bomb.draw_debug_bomb();
		for (int i = 0; i < 1000; i++) {
			bomb[i].draw_bomb();
			bomb[i].move_bomb();
		}
		printfDx("%d", cnt);
		cnt++;
		Wait();
	}
	DxLib_End();
	return 0;
}