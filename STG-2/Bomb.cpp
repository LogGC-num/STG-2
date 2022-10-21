#include "Bomb.h"


#define BOMB_ANGLE_TYPE_CISCLE		0	//1�b�Ԏ��ԕω��ƂƂ��ɋ}���ȕ����]�������A���̌������莞�v����̉�]���Â���
#define BOMB_ANGLE_TYPE_CISCLE_R	1	//1�b�Ԏ��ԕω��ƂƂ��ɋ}���ȕ����]�������A���̌������蔽���v����̉�]���Â���

#define BOMB_SPEED_TYPE_SAME		0	//�������x��ۂ�(speed = 5)
#define BOMB_SPEED_TYPE_SLOWER		1	//��b��speed = 5 ���̌�speed = 3;

extern int cWhite;

//���̃v���O�����̍��W�n�̘b
//x���͕��ʒʂ�
//y���͉�����
//�܂�p�x�Ƃ�������� x�����玞�v���ɉ�]����

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
	//angle����x y������speed�{���ăx�N�g���ɑ��
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
	//�g���Ă���Ȃ�Ε\��
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

//Bomb �����ʒu �� ���x�̕ω���(time������) �p�x�̕ω���(time������) ���](1 or -1)
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