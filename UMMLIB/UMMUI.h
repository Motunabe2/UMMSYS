/****************************************************************************
 *
 * UMMSYStem
 *
 * Copyright (c) Motunabe2
 *
 * Library  : UMMLIB
 * Module   : User Interface
 * File     : UMMUI.h
 *
 ****************************************************************************/


/* ���d��`�h�~					*/
/* Prevention of redefinition	*/
#pragma once

/***************************************************************************
 *      �}�N���萔�錾
 *      Macro
 ***************************************************************************/

#define SCREEN_SIZE_H 640
#define SCREEN_SIZE_W 480

#define WINDOW_BAR_TEXT_COLOR_R 255
#define WINDOW_BAR_TEXT_COLOR_G 255
#define WINDOW_BAR_TEXT_COLOR_B 255

#define MSGBOX_SIZE_W 300
#define MSGBOX_SIZE_H 200
#define MSGBOX_POINT_Y (SCREEN_SIZE_W / 2) - (MSGBOX_SIZE_W / 2)
#define MSGBOX_POINT_X (SCREEN_SIZE_H / 2) - (MSGBOX_SIZE_H / 2)

#include "DxLib.h"

class ummwindow
{
public:
	ummwindow(void);

	int perm_area_XS;//�`�ʋ��X�y�[�X�@���n
	int perm_area_YS;//�`�ʋ��X�y�[�X�@�c�n
	int perm_area_XE;//�`�ʋ��X�y�[�X�@���I
	int perm_area_YE;//�`�ʋ��X�y�[�X�@�c�I

	int window_point_Y;//�E�B���h�E�ʒu�@�c
	int window_point_X;//�E�B���h�E�ʒu�@��

	int window_size_H;//�E�B���h�E�T�C�Y�@�c
	int window_size_W;//�E�B���h�E�T�C�Y�@��

	int bar;//�^�C�g���o�[�@��

	int graph_barHL;

	int Draw_window();//�E�B���h�E��`��
	int Bar_text(const char tex[256]);//�^�C�g���e�L�X�g��\��
	int Print_tex(int X, int Y, const char tex[256], int R, int G, int B);//�e�L�X�g��\��
	int Print_str(int X, int Y, const char tex[512], int BetLine, bool derec, unsigned int Color);//�������\��
	int Print_char(int X, int Y, char Char, unsigned int Color);//������\��
	int Print_dec(int X, int Y, int dec, unsigned int Color);//���l��\��
	int Get_permission_area();//�`�ʋ����擾
	int DrawBoxUmm(int xs, int ys, int xe, int ye, unsigned int color, bool flg);//�l�p�`��`��
	int CrearWindow();
};

int GetFonthandle();

class ummButton
{
public:
	int FH;//�t�H���g�n���h��
	int SetButtonPosition(int X, int Y);//�{�^���ʒu�ݒ�
	int SetButtonSize(int Height, int Wide);//�{�^���T�C�Y�ݒ�
	int SetButtonPicture(bool Trans = true);//�{�^���摜�ݒ�
	bool GetButtonDown(int Button);
	bool GetButtonUp(int Button);
private:
	int PositionXS;//�{�^�����n���W
	int PositionYS;//�{�^���c�n���W
	int PositionXE;//�{�^�����I���W
	int PositionYE;//�{�^���c�I���W

	int Size_Height;//�{�^������
	int Size_Wide;//�{�^������


	int retnum;//GetMouseInputLog2�̖߂�l���i�[
	bool retb;
	int ButtonInf;
	int ClickPointX, ClickPointY;
	int LogType;

};