#pragma once
#include <math.h>
#include "DxLib.h"
#include "Bomb.h"

#define BOMB_MAX			1000		//’e–‹‚ÌÅ‘å—Ê

#define BOMB_SHAPE_TYPE_CIRCLE		0	//’e–‹‚ÌŒ`@‰~Œ`

#define BOMB_ANGLE_TYPE_CIRCLE		0	//1•bŠÔŠÔ•Ï‰»‚Æ‚Æ‚à‚É‹}Œƒ‚È•ûŒü“]Š·‚ğ‚µA‚»‚ÌŒã‚ä‚Á‚­‚èŒvü‚è‚Ì‰ñ“]‚ğ‚Â‚Ã‚¯‚é
#define BOMB_ANGLE_TYPE_CIRCLE_R	1	//1•bŠÔŠÔ•Ï‰»‚Æ‚Æ‚à‚É‹}Œƒ‚È•ûŒü“]Š·‚ğ‚µA‚»‚ÌŒã‚ä‚Á‚­‚è”½Œvü‚è‚Ì‰ñ“]‚ğ‚Â‚Ã‚¯‚é
#define BOMB_ANGLE_TYPE_SAME		2

#define BOMB_SPEED_TYPE_SAME		0	//“¯‚¶‘¬“x‚ğ•Û‚Â(speed = 5)
#define BOMB_SPEED_TYPE_SLOWER		1	//ˆë•bŠÔspeed = 5 ‚»‚ÌŒãspeed = 3;

//‰~ü—¦‚Ì“ó”{
#define TAU 6.2831853


void SetUp();
bool Update();
void Draw();
void Wait();
void NowLoading(int);
int gpUpdateKey();