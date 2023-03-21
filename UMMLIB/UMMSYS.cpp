/****************************************************************************
 *
 * UMMSYStem
 *
 * Copyright (c) Motunabe2
 *
 * Library  : UMMSYS
 * Module   : System Body
 * File     : UMMSYS.h
 *
 ****************************************************************************/

 /***************************************************************************
  *      インクルード
  *      include
  ***************************************************************************/
#include "UMMLIB.h"

UMMSYS :: UMMSYS()//コンストラクタ
{
	//ウィンドウサイズ設定
	window_size_H = 480;
	window_size_W = 640;

	//シーン制御
	ScenePP = new SceneProgramer;
	//フォント設定

	BOOT();
}
UMMSYS :: ~UMMSYS()//デコンストラクタ
{

}

int UMMSYS::BOOT()
{
	for (int FL = 0; FL == 0;)
	{
	WaitTimer(30);
		FL = ScenePP->SceneExec(1);
	}
	return 0;//正常終了
}




//SceneProgramer
SceneProgramer :: SceneProgramer()
{//シーンポインタの初期化処理
	SceneID = SCENE_Sample;
	RunningScene = SCENE_Sample;
	Sample = new Scene_Sample;
}



int SceneProgramer::SceneExec(int tick)
{
	
	if (RunningScene != SceneID)
	{
		switch (SceneID)
		{
		case SCENE_Sample :Sample = new Scene_Sample;
			break;
		}
	}
	switch (SceneID)
	{
	case SCENE_Sample:RunningScene = SCENE_Sample;
		break;
	}
	switch (SceneID)
	{
	case SCENE_Sample:SceneID = Sample->Scene_exec();
		break;
	}
	return 0;//正常終了
}
