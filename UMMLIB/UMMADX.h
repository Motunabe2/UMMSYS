//�Q�l
/*
https://w.atwiki.jp/soundtasukeai/pages/33.html#id_573b6636
https://game.criware.jp/manual/native/adx2/latest/index.html
*/
/* ���d��`�h�~					*/
/* Prevention of redefinition	*/
#pragma once


/* CRI SDK �w�b�_�[ */
#include <cri_le_xpt.h>

/* CRI ADX2 �w�b�_�[ */
#include <cri_le_atom_ex.h>
#include <cri_le_atom_wasapi.h>
/*Dx���C�u���� �w�b�_�[*/
#include "DxLib.h"

//#define ACF_FILE "assets/Sound/Public/UMMTEST.acf"
//#define ACB_FILE "assets/Sound/Public/WorkUnit_0/g1kansaiw.acb"


class ADXSoundPlayer
{
public:
	//ADXSoundPlayer();
	ADXSoundPlayer(char* ACB_FILE, char* ACF_FILE, CriAtomExCueId CRI_CUESHEET);
	~ADXSoundPlayer();
	int Play();
	int SetVolume(int Volume);


	CriAtomExPlayerHn PlayerHL;
private:
	/* �G���[�R�[���o�b�N�֐� */
	static void UserErrorCallbackFunc(const CriChar8* errid, CriUint32 p1, CriUint32 p2, CriUint32* parray)
	{
		const CriChar8* ErrMsg;

		/* �G���[������̕\�� */
		ErrMsg = criErr_ConvertIdToMessage(errid, p1, p2);
		printfDx("ADX2 �G���[ : %s\n", ErrMsg);
	}

	static void* UserAllocationFunc(void* obj, CriUint32 size)
	{
		void* ret;
		ret = malloc(size);
		return ret;
	}

	static void UserFreeFunc(void* obj, void* ptr)
	{
		free(ptr);
	}
private:
	CriAtomExVoicePoolHn VoicePool;
	CriAtomExAcbHn AcbHL;
};

class UMMSEPLAYER
{
public:
	int AddPlayer(char AcbFile[256],char AcFile[256],CriAtomExCueId CRI_CUESHEET);
	int DeletePlayer(char PlayerID);
	int Play(char PlayerID);
private:
	char EmptyPoint;
	int ReSerchEP();
	char default_CueSheet[256];
	bool Allocate[256];//true�ł���Ύg�p���@false�ł���Ζ��g�p
	ADXSoundPlayer* SoundPlayerPointer[256];
};

class UMMBGMPLAYER
{
public:

private:

};