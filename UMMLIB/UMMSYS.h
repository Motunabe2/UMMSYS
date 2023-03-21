/****************************************************************************
 *
 * UMMSYStem
 *
 * Copyright (c) Motunabe2
 *
 * Library  : UMMLIB
 * Module   : System Body
 * File     : UMMSYS.h
 *
 ****************************************************************************/


  /* ���d��`�h�~					*/
  /* Prevention of redefinition	*/
#pragma once

/***************************************************************************
 *      �}�N���萔�錾
 *      Macro
 ***************************************************************************/
#define MAX_SCENE_NUM 256
#define SCREEN_SIZE_H 640
#define SCREEN_SIZE_W 480

 /***************************************************************************
  *      �C���N���[�h
  *      include
  ***************************************************************************/
#include "DxLib.h"
#include "Sample.h"

class Button;
class SceneProgramer;

class UMMSYS
{
public:
	UMMSYS();//�R���X�g���N�^
	~UMMSYS();//�f�R���X�g���N�^
	int DrawBlank();
	int Loading_Start();
	int Loading_End();


	
private:
	int BOOT();
	int window_size_H;
	int window_size_W;

	unsigned short scene_status;
	//�V�[���|�C���^
	SceneProgramer* ScenePP;//�V�[���v���O���}

};

#define SCENE_Sample 0

class SceneProgramer
{
public:
	SceneProgramer();//�R���X�g���N�^
	int SceneExec(int tick);//�V�[���̎��s
	int SceneChange(int CheneNum);
private:
	int RunningScene;
	int SceneID;

	//�V�[���|�C���^�錾
	Scene_Sample* Sample;
};