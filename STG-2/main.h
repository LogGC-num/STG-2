#pragma once
#include <math.h>
#include "DxLib.h"
#include "Bomb.h"
#include "Chara.h"
#include "UI.h"

#define BOMB_MAX			1000		//弾幕の最大量

#define BOMB_SHAPE_TYPE_CIRCLE		0	//弾幕の形　円形

#define BOMB_ANGLE_TYPE_CIRCLE		0	//1秒間時間変化とともに急激な方向転換をし、その後ゆっくり時計周りの回転をつづける
#define BOMB_ANGLE_TYPE_CIRCLE_R	1	//1秒間時間変化とともに急激な方向転換をし、その後ゆっくり反時計周りの回転をつづける
#define BOMB_ANGLE_TYPE_SAME		2

#define BOMB_SPEED_TYPE_SAME		0	//同じ速度を保つ(speed = 5)
#define BOMB_SPEED_TYPE_SLOWER		1	//壱秒間speed = 5 その後speed = 3;

//円周率の弐倍
#define TAU 6.2831853


void SetUp();
bool Update();
void Draw();
void Wait();
void NowLoading(int);
int gpUpdateKey();