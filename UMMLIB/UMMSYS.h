/****************************************************************************
 *
 * UMMSYStem
 *
 * 
 *
 * Library  : UMMLIB
 * Module   : System Body
 * File     : UMMSYS.h
 *
 ****************************************************************************/


  /* 多重定義防止					*/
  /* Prevention of redefinition	*/
#pragma once

/***************************************************************************
 *      マクロ定数宣言
 *      Macro
 ***************************************************************************/
#define MAX_SCENE_NUM 256
#define SCREEN_SIZE_H 640
#define SCREEN_SIZE_W 480

 /***************************************************************************
  *      インクルード
  *      include
  ***************************************************************************/
#include "DxLib.h"
#include "Sample.h"

class Button;
class SceneProgramer;

class UMMSYS
{
public:
	UMMSYS();//コンストラクタ
	~UMMSYS();//デコンストラクタ
	int DrawBlank();
	int Loading_Start();
	int Loading_End();


	
private:
	int BOOT();
	int window_size_H;
	int window_size_W;

	unsigned short scene_status;
	//シーンポインタ
	SceneProgramer* ScenePP;//シーンプログラマ

};

#define SCENE_Sample 0

class SceneProgramer
{
public:
	SceneProgramer();//コンストラクタ
	int SceneExec(int tick);//シーンの実行
	int SceneChange(int CheneNum);
private:
	int RunningScene;
	int SceneID;

	//シーンポインタ宣言
	Scene_Sample* Sample;
};
