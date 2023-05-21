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

 /* 多重定義防止					*/
 /* Prevention of redefinition	*/
#pragma once

/***************************************************************************
 *      マクロ定数宣言
 *      Macro
 ***************************************************************************/
#define USE_DXLib true//Dxライブラリを使用する

//クラス判別用定数
#define TYPE_ACTOR 125
#define TYPE_COMPONENTS 126
#define TYPE_SCENE 127

 /***************************************************************************
  *      インクルード
  *      include
  ***************************************************************************/
#if USE_DXLib 
#include "DxLib.h"
#endif


/**
* コンポーネントやシーン等のオブジェクト用の基底クラスです。
*/
class MonoLithic//コンポーネント
{
//private:
public:
	bool StartFL;
	MonoLithic() 
	{
		StartFL = true; 
		Constructer();
	}
	virtual int Constructer();
private : int retVal;
public:
	int Execute();
	virtual int Start();
	virtual int Update();
	virtual int Components();
};

class Actor :public MonoLithic
{
public:
	const unsigned char Type = TYPE_ACTOR;
};
class Components :public MonoLithic
{
public:
	const unsigned char Type = TYPE_COMPONENTS;
};
class Scene :public MonoLithic
{
public:
	const unsigned char Type = TYPE_SCENE;
};

class Actor2
{
public:
	enum
	{
		EActive,
		EPaused,
		EDead
	};
public:
	void AddComponent(MonoLithic* Comp);
	void RemoveComponent(MonoLithic* Comp);

	//void Update();

	void UpdateAllComponent();

	virtual int Start();
	virtual int Update();
	//コンポーネント

private:
	//std::unordered_set<MonoLisic*>mComponents:
};



class BoxCollider2D : public Components
{
public:
	//BoxCollider2D() { Start(); }
	int Start();
	int Update();
	bool CheckHit;
	int BoxX, BoxY;
	int SizeXS, SizeYS, SizeXE, SizeYE;
};

class Transform2D : public Components
{
public:
	int X, Y;
	int Rotate;
};

class TransformP2D : public Components
{
public:
	int X;
	int Y;
	int Rotate;
	int Direction;
};

class Vector2 : public Components
{
public:
	int Update();
	int Start();

	float Strength;
	float X;
	float Y;
};

class WindowAbyss : public Components
{
public:
	int Start();
	int Update();
	int WAX, WAY;
	int WASizeX, WASizeY;
	bool CheckHit;
};

class PCamera : public Components
{
public:
	int Start();
	int Update();

};

#if USE_DXLib
class Sprite : public Components
{
public:
	int Start();
	int Draw();
	int FileName(const char FN[256]);

	char FName[256];
	bool Display;
	int X;
	int Y;

private:
	int GHL;
};


#define ASSET_TYPE_IMAGE 50
#define ASSET_TYPE_SOUND 60

class AssetManager
{
public:
	AssetManager(int HLSize = 256)
	{
		HandleList = new int[HLSize];
		UsedHandleList = new bool[HLSize];
		HandleSize = HLSize;
		for (int cnt = 0; cnt < HLSize; cnt++) 
		{
			UsedHandleList[cnt] = false;
		}
	}
public:
	int LoadAsset(const char FileName[],int FileType);
	int DeleteAsset(int Handle);
	int* HandleList;
private:
	int work;
	bool* UsedHandleList;
	int HandleSize;
	int Serch_No_UseHList();
};
#endif