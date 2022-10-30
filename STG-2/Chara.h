#pragma once
#include "main.h"
#include "Bomb.h"

#define CHARA_FIRST_LIFE	3

#define CHARA_HIT_CIRCLE	5

//構造体 POS を別ファイルでも使えるようする
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
//	void check_hit(POS,int);		//当たり判定:弾幕のPOSとsizeを取得
	void draw_chara();				//今のところボックス 後々画像

private:
	int life;
	int score;


};

