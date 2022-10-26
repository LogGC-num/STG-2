#pragma once
#include "main.h"

#define DEFAULT_BOMB_SIZE	10
#define	BOMB_TYPE_CIRCLE	0
#define DEFAULT_BOMB_SPEED	10

typedef struct _xy {
	double x;
	double y;
}POS;

typedef struct _type {
	int bomb;
	int angle;
	int speed;
}TYPE;

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

	Bomb();					//コンストラクタでメンバを初期化
	void draw_bomb();		//弾幕を表示
	void set_angle();		//時間によってangleが変化するときに用いる
	void set_speed();		//時間によってspeedが変化するときに用いる
	void move_bomb();		//vecを用いてposを変更
	void draw_debug_bomb();

private:
	void get_angle();		//時間によってangleが変化するときに用いる
	void get_speed();		//時間によってspeedが変化するときに用いる
	void get_vec();			//speedとangleからvecを算出
	
};

//Bomb 初期位置 量 速度の変化パターン 角度の変化パターン 反転(1 or -1)
void make_circle(Bomb[1000] ,POS,int amount, int change_speed, int change_angle ,int reverse);		//同心円状に弾幕を張る

//Bomb 初期位置 量 速度の変化パターン 初期角度 角度の変化パターン
void make_beam(Bomb[1000], POS, int amount, int change_speed, double angle, int change_angle);