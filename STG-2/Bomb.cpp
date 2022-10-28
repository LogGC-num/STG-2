#include "Bomb.h"

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

void Bomb::set_bomb_type(int type_bomb) {
	type.bomb = type_bomb;
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
	//type.angleによって方向の変化パターンを変える
	switch (type.angle)
	{
		
	case BOMB_ANGLE_TYPE_CIRCLE:
		if (time < 1)
			angle += (TAU / 4) * 0.05 * time;
		else
			angle += (TAU / 32) * 0.05;
		break;
		
	case BOMB_ANGLE_TYPE_CIRCLE_R:
		if (time < 1)
			angle += (TAU / 4) * -0.05 * time;
		else
			angle += (TAU / 32) * -0.05;
		break;
	case BOMB_ANGLE_TYPE_SAME:
		
		break;
	default:
		break;
	}
	
}

void Bomb::get_speed() {
	//type.speedによって速度の変化パターンを変える
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
		switch (type.bomb) {
		case BOMB_TYPE_CIRCLE:
			DrawCircle((int)pos.x, (int)pos.y, size, cWhite, TRUE, TRUE);
			break;
		case BOMB_TYPE_QUAD:
			DrawBox((int)pos.x, (int)pos.y, (int)pos.x + size, (int)pos.y + size, cWhite, TRUE);
			break;

		case BOMB_TYPE_TRIANGLE:
			DrawTriangle((int)pos.x - (int)size / 2, (int)pos.y - (int)size / 2, (int)pos.x + (int)size / 2, (int)pos.y - (int)size / 2, (int)pos.x, (int)pos.y + (int)size / 2, cWhite, FALSE);
			break;


		default:
			break;
		}
	}
}

void Bomb::move_bomb() {
	//もし使っているのならば速度、向きを決め、vecを定めその方向に進めさせる
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
	//Debugツール
	DrawFormatString(500, 0, cWhite, "x : %f y : %f", pos.x, pos.y);
	DrawFormatString(500, 20, cWhite, "vx : %f vy : %f", vec.x, vec.y);
	DrawFormatString(500, 40, cWhite, "sp : %f an : %f", speed, angle);
	DrawFormatString(500, 60, cWhite, "time : %f", time);
}

//Bomb 初期位置 量 速度の変化量(time当たり) 角度の変化量(time当たり) 反転(1 or -1)
void make_circle(Bomb bomb[BOMB_MAX],POS pos,int amount, int change_speed, int change_angle,int reverse) {
	int cnt_amount = 0;
	while (cnt_amount != amount) {
		for (int i = 0; i < BOMB_MAX; i++) {
			if (bomb[i].isUse == false) {
				bomb[i].isUse = true;
				bomb[i].pos.x = pos.x;
				bomb[i].pos.y = pos.y;
				bomb[i].angle += (TAU / amount) * cnt_amount * reverse;
				bomb[i].type.angle = change_angle;
				bomb[i].type.speed = change_speed;
				cnt_amount++;
			}
			if (cnt_amount == amount)	break;

		}
	}
}

void make_beam(Bomb bomb[BOMB_MAX], POS pos, int amount, int change_speed, double angle , int change_angle) {
	int cnt_amount = 0;
	while (cnt_amount != amount) {
		for (int i = 0; i < BOMB_MAX; i++) {
			if (bomb[i].isUse == false) {
				bomb[i].isUse = true;
				bomb[i].set_bomb_type(BOMB_TYPE_QUAD);
				bomb[i].pos.x = pos.x + ((double)amount - (double)cnt_amount) * (bomb[i].size / 2) * cos(angle);
				bomb[i].pos.y = pos.y + ((double)amount - (double)cnt_amount) * (bomb[i].size / 2) * sin(angle);
				bomb[i].angle = angle;
				bomb[i].type.angle = change_angle;
				bomb[i].type.speed = change_speed;
				cnt_amount++;
			}

			if (cnt_amount == amount)	break;
		}
	}
}