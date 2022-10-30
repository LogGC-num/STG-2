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

//�\���� POS ��ʃt�@�C���ł��g�p�ł���悤�ɂ���
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
	POS pos;				//���W
	POS vec;				//�ړ�����x�N�g��
	double speed;			//�e���̃X�s�[�h
	double angle;			//�e���̕���
	bool isUse;				//�e�����g��Ă��邩�ǂ���
	int size;				//�e���̑傫��
	double time;			//�e�����̎���
	TYPE type;				//�e���̎��	
	int max_time;			//�e�������݂���ő厞��
	int reverse;

	Bomb();						//�R���X�g���N�^�Ń����o�������� �����Œe���̌`���w��
	void draw_bomb();			//�e����\��
	void set_angle();			//���Ԃɂ����angle���ω�����Ƃ��ɗp����
	void set_speed();			//���Ԃɂ����speed���ω�����Ƃ��ɗp����
	void set_bomb_type(int);	//�e���̌`�̕ω�
	void move_bomb();			//vec��p����pos��ύX
	void draw_debug_bomb();	
	void check_hit(POS);		//�L�����ɓ����������ǂ���
	bool check_out_field();		//�e�����͈͊O�֍s������e��������

private:
	void get_angle();		//���Ԃɂ����angle���ω�����Ƃ��ɗp����
	void get_speed();		//���Ԃɂ����speed���ω�����Ƃ��ɗp����
	void get_vec();			//speed��angle����vec���Z�o
	
};

//Bomb �����ʒu �� ���x�̕ω��p�^�[�� �p�x�̕ω��p�^�[�� ���](1 or -1)
void make_circle(Bomb[1000] ,POS,int amount, int change_speed, int change_angle ,int reverse);		//���S�~��ɒe���𒣂�

//Bomb �����ʒu �� ���x�̕ω��p�^�[�� �����p�x �p�x�̕ω��p�^�[��
void make_beam(Bomb[1000], POS, int amount, int change_speed, double angle, int change_angle);