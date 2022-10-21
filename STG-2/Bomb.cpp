#include "Bomb.h"


#define BOMB_ANGLE_TYPE_CISCLE		0	//1秒間時間変化とともに急激な方向転換をし、その後ゆっくり時計周りの回転をつづける
#define BOMB_ANGLE_TYPE_CISCLE_R	1	//1秒間時間変化とともに急激な方向転換をし、その後ゆっくり反時計周りの回転をつづける

#define BOMB_SPEED_TYPE_SAME		0	//同じ速度を保つ(speed = 5)
#define BOMB_SPEED_TYPE_SLOWER		1	//壱秒間speed = 5 その後speed = 3;

extern int cWhite;

//このプログラムの座標系の話
//x軸は普通通り
//y軸は下向き
//つまり角度θが増えると x軸から時計回りに回転する

Bomb::Bomb() {
	pos.x = 100;
	pos.y = 100;
	vec.x = 0;
	vec.y = 0;
	speed = DEFAULT_BOMB_SPEED - (double)5;
	angle = TAU / 8;
	isUse = false;
	size = DEFAULT_BOMB_SIZE;
	time = 0;
	type.bomb = 0;
	type.angle = 0;
	type.speed = 0;
}

void Bomb::get_vec() {
	//angleからx y成分をspeed倍してベクトルに代入
	vec.x = (cos(angle) * speed);
	vec.y = (sin(angle) * speed);
}

void Bomb::set_angle() {
	get_angle();
}

void Bomb::set_speed() {
	get_speed();
}

void Bomb::get_angle(){
	switch (type.angle)
	{
		
	case BOMB_ANGLE_TYPE_CISCLE:
		if (time < 1)
			angle += (TAU / 4) * 0.05 * time;
		else
			angle += (TAU / 32) * 0.05;
		break;
		
	case BOMB_ANGLE_TYPE_CISCLE_R:
		if (time < 1)
			angle += (TAU / 4) * -0.05 * time;
		else
			angle += (TAU / 32) * -0.05;
		break;
	default:
		break;
	}
	
}

void Bomb::get_speed() {
	switch (type.speed)
	{
	case BOMB_SPEED_TYPE_SAME:
		speed = 5;
		break;
	case BOMB_SPEED_TYPE_SLOWER:
		if (time < 1)
			speed = 5;
		else

			speed = 3;
		break;
	default:
		break;
	}
	
}

void Bomb::draw_bomb() {
	//使っているならば表示
	if (isUse == true) {
		DrawCircle((int)pos.x, (int)pos.y, size, cWhite, TRUE, TRUE);
	}
}

void Bomb::move_bomb() {
	if (isUse == true) {
		set_speed();
		set_angle();
		get_vec();
		pos.x += vec.x;
		pos.y += vec.y;
		time += 0.01;
	}
}

void Bomb::draw_debug_bomb() {
	DrawFormatString(500, 0, cWhite, "x : %f y : %f", pos.x, pos.y);
	DrawFormatString(500, 20, cWhite, "vx : %f vy : %f", vec.x, vec.y);
	DrawFormatString(500, 40, cWhite, "sp : %f an : %f", speed, angle);
	DrawFormatString(500, 60, cWhite, "time : %f", time);
}

//Bomb 初期位置 量 速度の変化量(time当たり) 角度の変化量(time当たり) 反転(1 or -1)
void make_circle(Bomb bomb[1000],POS pos,int amount, int change_speed, int change_angle,int reverse) {
	int cnt_amount = 0;
	while (cnt_amount != amount) {
		for (int i = 0; i < 1000; i++) {
			if (bomb[i].isUse == false) {
				bomb[i].isUse = true;
				bomb[i].pos.x = 100;
				bomb[i].pos.y = 100;
				bomb[i].angle += (TAU / amount) * cnt_amount * reverse;
				bomb[i].type.angle = change_angle;
				bomb[i].type.speed = change_speed;
				cnt_amount++;
			}
			if (cnt_amount == amount)	break;

		}
	}
}