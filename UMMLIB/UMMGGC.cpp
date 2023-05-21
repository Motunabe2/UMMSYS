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
  *      �C���N���[�h
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
	Components();//�R���|�[�l���g���s
	return retVal;//����I��
}

int MonoLithic::Constructer()
{

	return 0;//����I��
}

int MonoLithic::Start()
{

	return 0;//����I��
}

int MonoLithic::Update()
{

	return 0;//����I��
}

int MonoLithic::Components()
{

	return 0;//����I��
}


int BoxCollider2D :: Start()
{
	
	return 0;//����I��
}

int BoxCollider2D::Update()
{

	return 0;//����I��
}


int Vector2 :: Start()
{

	return 0;//����I��
}

int Vector2::Update()
{

	return 0;//����I��
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
	X = 0;//���ʒu������
	Y = 0;//�c�ʒu������
	Display = false;//������Ԃł͕\�����Ȃ�
	
	GHL = LoadGraph(FName);//�摜�̓ǂݍ���

	return 0;//����I��
}

int Sprite :: Draw()
{
	
	return 0;//����I��
}

int Sprite::FileName(const char FN[256])
{
	//*FName = FN;
	return 0;//����I��
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
	else { return -10;/*�G���[ : �t�@�C���^�C�v�I�����Ԉ���Ă���*/ }
}

int AssetManager::Serch_No_UseHList()
{
	for (int cnt = 0; cnt < HandleSize; cnt++)
	{
		if (HandleList[cnt] == false) { return cnt; }
	}
}
#endif

