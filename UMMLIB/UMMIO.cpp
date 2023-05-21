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

#include "UMMIO.h"

UMMInput::UMMInput()
{
	ButtonToggle = false;
}
bool UMMInput :: GetMouseButton(int Button)
{
	wk = GetMouseInputLog2(&ButtonInf, &ClickX, &ClickY, &LogType, true);
	if (wk == 0)
	{
		if (ButtonInf == Button)
		{
			if (LogType == MOUSE_INPUT_LOG_DOWN)
			{
				DrawBox(0, 0, 10, 10, GetColor(255, 0, 0), true);
				ButtonToggle = true;
			}
			else if (LogType == MOUSE_INPUT_LOG_UP)
			{
				DrawBox(0, 0, 10, 10, GetColor(0, 255, 0), true);
				ButtonToggle = false;
			}
		}
	}
	return ButtonToggle;
}
bool UMMInput:: GetMouseButtonDown(int Button)
{
	wk = GetMouseInputLog2(&ButtonInf, &ClickX, &ClickY, &LogType, true);
	if (wk == 0)
	{
		if (ButtonInf == Button)
		{
			if (LogType == MOUSE_INPUT_LOG_DOWN)
			{
				ret = true;
			}
		}
	}
	else if (wk == -1)
	{
		ret = false;
	}
	return ret;
}
bool UMMInput:: GetMouseButtonUp(int Button)
{
	wk = GetMouseInputLog2(&ButtonInf, &ClickX, &ClickY, &LogType, true);
	if (wk == 0)
	{
		if (ButtonInf == Button)
		{
			if (LogType == MOUSE_INPUT_LOG_UP)
			{
				ret = true;
			}
		}
	}
	else if (wk == -1)
	{
		ret = false;
	}
	return ret;
}

bool UMMInput::GetKey(int KeyCode)
{
	GetHitKeyStateAll(KeyBuff);
	if (KeyBuff[KeyCode] == 1)
	{
		ret = true;
	}
	else
	{
		ret = false;
	}
	return ret;;
}
bool UMMInput::GetKeyDown(int KeyCode)
{

	return false;
}
bool UMMInput::GetKeyUp(int KeyCode)
{

	return false;
}
