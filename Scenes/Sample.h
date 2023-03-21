#pragma once

#include <time.h>
#include "DxLib.h"
#include "UMMGGC.h"
#include "UMMUI.h"
#include "UMMADX.h"

class Scene_Sample : public MonoLisic
{
public:
	Scene_Sample();
	int Scene_exec(bool setup = false);
private:
	int Update();
	int Start();

	ummwindow* win;
	ummButton* TBut;
};

class FPSCount : public MonoLisic
{
public:
	FPSCount() { flame = 0; }
	int Update();
	int cnt;
	long CPS;
	double sec;
	int flame;
	int secint;
	
};