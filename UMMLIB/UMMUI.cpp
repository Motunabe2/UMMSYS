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

/***************************************************************************
 *      インクルード
 *      include
 ***************************************************************************/
#include "UMMUI.h"
#include "Dxlib.h"

int GetFonthandle()
{
	// ＤＸフォントデータファイルを読み込み、フォントハンドルを変数 FontHandle に保存する
	return LoadFontDataToHandle("assets/Fonts/wanpakuruika07.dft", 0);
}

//ウィンドウ関連
ummwindow::ummwindow()
{
	graph_barHL = LoadGraph("assets/UI/window_upper.png");
	bar = 20;
}
int ummwindow::Draw_window()//3msから8ms位の処理時間
{
	DrawBox(window_point_X - 1, window_point_Y - 1, window_point_X + window_size_W + 1, window_point_Y + window_size_H + 1, GetColor(10, 10, 10), TRUE);//ウィンドウ下地の描写
	DrawBox(window_point_X, window_point_Y, window_point_X + window_size_W, window_point_Y + window_size_H, GetColor(200, 200, 200), TRUE);//ウィンドウボックス表示の描写

	for (int cnt1 = window_point_X; cnt1 < window_point_X + window_size_W; cnt1++) { DrawGraph(cnt1, window_point_Y, graph_barHL, TRUE); }

	Get_permission_area();
	return 0;
}
int ummwindow::Bar_text(const char tex[256])
{
	DrawString(window_point_X + 1, window_point_Y + 1, tex, GetColor(WINDOW_BAR_TEXT_COLOR_R, WINDOW_BAR_TEXT_COLOR_G, WINDOW_BAR_TEXT_COLOR_B), TRUE);
	return 0;
}
int ummwindow::Print_tex(int x, int y, const char tex[256], int R, int G, int B)
{
	DrawString(window_point_X + x + 2, window_point_Y + y + bar, tex, GetColor(R, G, B), TRUE);
	return 0;
}
int ummwindow::Get_permission_area()
{
	this ->perm_area_XS = window_point_X;					//横始を求める式
	this->perm_area_XE = window_point_X + window_size_W;	//横終を求める式

	this->perm_area_YS = window_point_Y + bar;			//縦始を求める式
	this->perm_area_YE = window_point_Y + window_size_H;	//縦終を求める式
	return 0;
}
int ummwindow::DrawBoxUmm(int xs, int ys, int xe, int ye, unsigned int color, bool flg)
{
	//if (perm_area_XS > perm_area_XS + xe) { printfDx("描写範囲外です XS\n"); }
	//if (perm_area_YS > perm_area_YS + ye) { printfDx("描写範囲外です YS\n"); }
	//if (perm_area_XE < perm_area_XS + xe) { printfDx("描写範囲外です XE\n"); }
	//if (perm_area_YE < perm_area_YS + ye) { printfDx("描写範囲外です YE\n"); }

	DrawBox(perm_area_XS + xs, perm_area_YS + ys, perm_area_XS + xe, perm_area_YS + ye - bar, color, flg);
	return 0;
}
int ummwindow::Print_str(int X, int Y, const char tex[512], int BetLine, bool derec, unsigned int Color)
{
	DrawFormatString(window_point_X + X + 2, window_point_Y + Y + bar + 3, Color, "%s", tex);
	return 0;
}
int ummwindow::Print_char(int X, int Y, char Char, unsigned int Color)
{
	DrawFormatString(window_point_X + X + 2, window_point_Y + Y + bar + 3, Color, "%c", Char);
	return 0;
}
int ummwindow::Print_dec(int X, int Y, int dec, unsigned int Color)
{
	DrawFormatString(window_point_X + X + 2, window_point_Y + Y + bar + 3, Color, "%d", dec);
	return 0;
}
int ummwindow::CrearWindow()
{
	//Get_permission_area();
	DrawBoxUmm(0,0,window_size_W,window_size_H, GetColor(200, 200, 200), true);
	return 0;
}

//Class Button
int ummButton::SetButtonPicture(bool Trans)
{
	int A = 0;
	return 0;//正常終了
}
int ummButton::SetButtonSize(int Height, int Wide)
{
	Size_Height = Height;
	Size_Wide = Wide;
	return 0;//正常終了
}
int ummButton::SetButtonPosition(int X, int Y)
{
	PositionXS = X;
	PositionYS = Y;
	PositionXE = X + Size_Wide;
	PositionYE = Y + Size_Height;
	return 0;//正常終了
}
bool ummButton::GetButtonDown(int Button)
{
	retnum = GetMouseInputLog2(&ButtonInf, &ClickPointX, &ClickPointY, &LogType, true);
	DrawBox(PositionXS, PositionYS, PositionXE, PositionYE, GetColor(255, 255, 0), false);
	if (retnum == 0)//履歴が取得できた
	{
		if (ButtonInf == Button)
		{
			if (LogType == MOUSE_INPUT_LOG_DOWN)
			{
				if (PositionXS < ClickPointX && ClickPointX < PositionXE)
				{
					if (PositionYS < ClickPointY && ClickPointY < PositionYE)
					{
						retb = true;
						//printfDx("clicked");
						DrawBox(PositionXS, PositionYS, PositionXE, PositionYE, GetColor(0, 0, 255), false);
					}
				}
			}
		}
	}
	else if (retnum == -1)//履歴が無い
	{
		DrawLine(PositionXS, PositionYS, PositionXE, PositionYE, GetColor(0, 255, 0));
		retb = false;
	}
	return retb;
}
bool ummButton::GetButtonUp(int Button)
{
	retnum = GetMouseInputLog2(&ButtonInf, &ClickPointX, &ClickPointY, &LogType, true);
	DrawBox(PositionXS, PositionYS, PositionXE, PositionYE, GetColor(255, 255, 0), false);
	if (retnum == 0)//履歴が取得できた
	{
		if (ButtonInf == Button)
		{
			if (LogType == MOUSE_INPUT_LOG_UP)
			{
				if (PositionXS < ClickPointX && ClickPointX < PositionXE)
				{
					if (PositionYS < ClickPointY && ClickPointY < PositionYE)
					{
						retb = true;
						printfDx("clicked");
						DrawBox(PositionXS, PositionYS, PositionXE, PositionYE, GetColor(0, 0, 255), false);
					}
				}
			}
		}
	}
	else if (retnum == -1)//履歴が無い
	{
		DrawLine(PositionXS, PositionYS, PositionXE, PositionYE, GetColor(0, 255, 0));
		retb = false;
	}
	return retb;
}
