#pragma once
#include "main.h"
#include "Bomb.h"

#define CHARA_FIRST_LIFE	3

#define CHARA_HIT_CIRCLE	5

//�\���� POS ��ʃt�@�C���ł��g����悤����
#ifndef _POS_DEFINED
#define _POS_DEFINED
	typedef struct _xy {
		double x;
		double y;
	}POS;

#endif

#ifndef _TYPE_DEFINED
#define _TYPE_DEFINED
	typedef struct _type {
		int bomb;
		int angle;
		int speed;
	}TYPE;
#endif


class Chara
{
public:	
	Chara();

	POS pos;
//	void check_hit(POS,int);		//�����蔻��:�e����POS��size���擾
	void draw_chara();				//���̂Ƃ���{�b�N�X ��X�摜

private:
	int life;
	int score;


};

