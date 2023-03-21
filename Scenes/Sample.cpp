#include "Sample.h"


Scene_Sample :: Scene_Sample()//コンストラクタ
{
	this->Scene_exec(true);
}

int Scene_Sample :: Scene_exec(bool setup)
{
	int retVal = 0;

	if (setup == true) { retVal = Start(); }//最初に実行する
	else { retVal = Update(); }//1tickごとに実行する

	return retVal;//終了
}

int Scene_Sample::Start()
{
	win = new ummwindow;
	win->window_point_X = 200;
	win->window_point_Y = 200;
	win->window_size_H = 200;
	win->window_size_W = 300;

	win->Draw_window();
	win->Bar_text("TEST");
	win->Print_tex(5, 5, "黄色の枠内をクリック", 0, 0, 0);

	TBut = new ummButton;
	TBut->SetButtonSize(64, 64);
	TBut->SetButtonPosition(win->perm_area_XS + 64, win->perm_area_YS + 64);
	return 0;//正常終了
}

int Scene_Sample :: Update()
{
	static FPSCount FPSCount;
	FPSCount.Update();

	if (TBut->GetButtonDown(MOUSE_INPUT_LEFT) == true)
	{
		win->Print_tex(5, 24, "key Hit!!", 0, 0, 0);
		DrawString(0, 0, "h", GetColor(255, 255, 255));
	}
	return 0;//正常終了
}

int FPSCount::Update()
{
	flame++;
	CPS = clock();
	sec = (double)CPS / CLOCKS_PER_SEC;
	secint = (int)sec;

	if (secint > cnt)
	{
		DrawBox(0, 0, 128, 64, 0, true);
		DrawFormatString(0, 0, GetColor(255, 255, 0), "FPS %d", flame);
		cnt = secint;
		flame = 0;
	}
	return 0;//正常終了
}