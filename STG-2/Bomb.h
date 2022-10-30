#pragma once
#include "main.h"

#define DEFAULT_BOMB_SIZE	10

#define	BOMB_TYPE_CIRCLE	0
#define BOMB_TYPE_QUAD		1
#define	BOMB_TYPE_TRIANGLE	2

#define DEFAULT_BOMB_SPEED	10

#define OUT_FIELD_MAX		750
#define OUT_FIELD_MIN		-250

/*
typedef struct _xy {
	double x;
	double y;
}POS;
*/

//構造体 POS を別ファイルでも使用できるようにする
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




class Bomb
{
public:
	POS pos;				//座標
	POS vec;				//移動するベクトル
	double speed;			//弾幕のスピード
	double angle;			//弾幕の方向
	bool isUse;				//弾幕が使わているかどうか
	int size;				//弾幕の大きさ
	double time;			//弾幕内の時間
	TYPE type;				//弾幕の種類	
	int max_time;			//弾幕が存在する最大時間
	int reverse;

	Bomb();						//コンストラクタでメンバを初期化 引数で弾幕の形を指定
	void draw_bomb();			//弾幕を表示
	void set_angle();			//時間によってangleが変化するときに用いる
	void set_speed();			//時間によってspeedが変化するときに用いる
	void set_bomb_type(int);	//弾幕の形の変化
	void move_bomb();			//vecを用いてposを変更
	void draw_debug_bomb();	
	void check_hit(POS);		//キャラに当たったかどうか
	bool check_out_field();		//弾幕が範囲外へ行ったら弾幕を消す

private:
	void get_angle();		//時間によってangleが変化するときに用いる
	void get_speed();		//時間によってspeedが変化するときに用いる
	void get_vec();			//speedとangleからvecを算出
	
};

//Bomb 初期位置 量 速度の変化パターン 角度の変化パターン 反転(1 or -1)
void make_circle(Bomb[1000] ,POS,int amount, int change_speed, int change_angle ,int reverse);		//同心円状に弾幕を張る

//Bomb 初期位置 量 速度の変化パターン 初期角度 角度の変化パターン
void make_beam(Bomb[1000], POS, int amount, int change_speed, double angle, int change_angle);