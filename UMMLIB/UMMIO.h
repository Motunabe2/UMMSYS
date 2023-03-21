/****************************************************************************
 *
 * UMMSYStem
 *
 * Copyright (c) Motunabe2
 *
 * Library  : UMMLIB
 * Module   : InputOutput
 * File     : UMMIO.h
 *
 ****************************************************************************/

 /* ëΩèdíËã`ñhé~					*/
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
	//à»â∫privateÇ≈âBÇ∑
	int wk;
	bool ret;
	bool ButtonToggle;
	int ButtonInf;
	int ClickX;
	int ClickY;
	int LogType;
	char KeyBuff[256];
};
