#pragma once
#include <math.h>
#include "DxLib.h"
#include "Bomb.h"

#define BOMB_MAX			1000		//�e���̍ő��

#define BOMB_SHAPE_TYPE_CIRCLE		0	//�e���̌`�@�~�`

#define BOMB_ANGLE_TYPE_CIRCLE		0	//1�b�Ԏ��ԕω��ƂƂ��ɋ}���ȕ����]�������A���̌������莞�v����̉�]���Â���
#define BOMB_ANGLE_TYPE_CIRCLE_R	1	//1�b�Ԏ��ԕω��ƂƂ��ɋ}���ȕ����]�������A���̌������蔽���v����̉�]���Â���
#define BOMB_ANGLE_TYPE_SAME		2

#define BOMB_SPEED_TYPE_SAME		0	//�������x��ۂ�(speed = 5)
#define BOMB_SPEED_TYPE_SLOWER		1	//��b��speed = 5 ���̌�speed = 3;

//�~�����̓�{
#define TAU 6.2831853


void SetUp();
bool Update();
void Draw();
void Wait();
void NowLoading(int);
int gpUpdateKey();