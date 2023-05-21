/****************************************************************************
 *
 * UMMSYStem
 *
 * Copyright (c) Motunabe2
 *
 * Library  : UMMLIB
 * Module   : Generic Game Components
 * File     : UMMGGC.h
 *
 ****************************************************************************/

 /***************************************************************************
  *      インクルード
  *      include
  ***************************************************************************/
#include "UMMGGC.h"

int MonoLithic :: Execute()
{
	retVal = 0;
	if (StartFL == true) 
	{
		retVal = Start();
		StartFL = false;
	}
	else { retVal = Update(); }
	Components();//コンポーネント実行
	return retVal;//正常終了
}

int MonoLithic::Constructer()
{

	return 0;//正常終了
}

int MonoLithic::Start()
{

	return 0;//正常終了
}

int MonoLithic::Update()
{

	return 0;//正常終了
}

int MonoLithic::Components()
{

	return 0;//正常終了
}


int BoxCollider2D :: Start()
{
	
	return 0;//正常終了
}

int BoxCollider2D::Update()
{

	return 0;//正常終了
}


int Vector2 :: Start()
{

	return 0;//正常終了
}

int Vector2::Update()
{

	return 0;//正常終了
}




int WindowAbyss :: Start()
{

	return 0;
}
int WindowAbyss :: Update()
{
	if (0 < WAX && WAX < 480)
	{
		if (0 < WAY && WAY < 640)
		{
			CheckHit = false;
		}
	}
	else
	{
		CheckHit = true;
	}
	return 0;
}

#if USE_DXLib
int Sprite::Start()
{
	X = 0;//横位置初期化
	Y = 0;//縦位置初期化
	Display = false;//初期状態では表示しない
	
	GHL = LoadGraph(FName);//画像の読み込み

	return 0;//正常終了
}

int Sprite :: Draw()
{
	
	return 0;//正常終了
}

int Sprite::FileName(const char FN[256])
{
	//*FName = FN;
	return 0;//正常終了
}


int AssetManager :: LoadAsset(const char FileName[],int FileType)
{
	HandleList[2] = 0;
	if (FileType == ASSET_TYPE_IMAGE)
	{
		return LoadGraph(FileName);
	}
	else if (FileType == ASSET_TYPE_SOUND)
	{
		work = LoadSoundMem(FileName);
		
	}
	else { return -10;/*エラー : ファイルタイプ選択が間違っている*/ }
}

int AssetManager::Serch_No_UseHList()
{
	for (int cnt = 0; cnt < HandleSize; cnt++)
	{
		if (HandleList[cnt] == false) { return cnt; }
	}
}
#endif

