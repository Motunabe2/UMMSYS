/****************************************************************************
 *
 * UMMSYStem
 *
 *
 *
 * Library  : UMMLIB
 * Module   : User Interface
 * File     : UMMUI.h
 *
 ****************************************************************************/


/* 多重定義防止					*/
/* Prevention of redefinition	*/
#pragma once

/***************************************************************************
 *      マクロ定数宣言
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

	int perm_area_XS;//描写許可スペース　横始
	int perm_area_YS;//描写許可スペース　縦始
	int perm_area_XE;//描写許可スペース　横終
	int perm_area_YE;//描写許可スペース　縦終

	int window_point_Y;//ウィンドウ位置　縦
	int window_point_X;//ウィンドウ位置　横

	int window_size_H;//ウィンドウサイズ　縦
	int window_size_W;//ウィンドウサイズ　横

	int bar;//タイトルバー　幅

	int graph_barHL;

	int Draw_window();//ウィンドウを描写
	int Bar_text(const char tex[256]);//タイトルテキストを表示
	int Print_tex(int X, int Y, const char tex[256], int R, int G, int B);//テキストを表示
	int Print_str(int X, int Y, const char tex[512], int BetLine, bool derec, unsigned int Color);//文字列を表示
	int Print_char(int X, int Y, char Char, unsigned int Color);//文字を表示
	int Print_dec(int X, int Y, int dec, unsigned int Color);//数値を表示
	int Get_permission_area();//描写許可を取得
	int DrawBoxUmm(int xs, int ys, int xe, int ye, unsigned int color, bool flg);//四角形を描写
	int CrearWindow();
};

int GetFonthandle();

class ummButton
{
public:
	int FH;//フォントハンドル
	int SetButtonPosition(int X, int Y);//ボタン位置設定
	int SetButtonSize(int Height, int Wide);//ボタンサイズ設定
	int SetButtonPicture(bool Trans = true);//ボタン画像設定
	bool GetButtonDown(int Button);
	bool GetButtonUp(int Button);
private:
	int PositionXS;//ボタン横始座標
	int PositionYS;//ボタン縦始座標
	int PositionXE;//ボタン横終座標
	int PositionYE;//ボタン縦終座標

	int Size_Height;//ボタン高さ
	int Size_Wide;//ボタン横幅


	int retnum;//GetMouseInputLog2の戻り値を格納
	bool retb;
	int ButtonInf;
	int ClickPointX, ClickPointY;
	int LogType;

};
