/****************************************************************************
 *
 * UMMSYStem
 *
 *
 *
 * Library  : UMMLIB
 * Module   : InputOutput
 * File     : UMMIO.h
 *
 ****************************************************************************/

 /* 多重定義防止					*/
 /* Prevention of redefinition	*/
#pragma once

#include "DxLib.h"

class UMMInput
{
public:
	UMMInput();
	bool GetKey(int KeyCode);
	bool GetKeyDown(int KeyCode);
	bool GetKeyUp(int KeyCode);
	bool GetMouseButton(int Button);
	bool GetMouseButtonDown(int Button);
	bool GetMouseButtonUp(int Button);

private:
	//以下privateで隠す
	int wk;
	bool ret;
	bool ButtonToggle;
	int ButtonInf;
	int ClickX;
	int ClickY;
	int LogType;
	char KeyBuff[256];
};
