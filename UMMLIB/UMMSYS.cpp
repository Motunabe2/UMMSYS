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
  *      �C���N���[�h
  *      include
  ***************************************************************************/
#include "UMMLIB.h"

UMMSYS :: UMMSYS()//�R���X�g���N�^
{
	//�E�B���h�E�T�C�Y�ݒ�
	window_size_H = 480;
	window_size_W = 640;

	//�V�[������
	ScenePP = new SceneProgramer;
	//�t�H���g�ݒ�

	BOOT();
}
UMMSYS :: ~UMMSYS()//�f�R���X�g���N�^
{

}

int UMMSYS::BOOT()
{
	for (int FL = 0; FL == 0;)
	{
	WaitTimer(30);
		FL = ScenePP->SceneExec(1);
	}
	return 0;//����I��
}




//SceneProgramer
SceneProgramer :: SceneProgramer()
{//�V�[���|�C���^�̏���������
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
	return 0;//����I��
}
