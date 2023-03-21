//参考
/*
https://w.atwiki.jp/soundtasukeai/pages/33.html#id_573b6636
https://game.criware.jp/manual/native/adx2/latest/index.html
*/
/* 多重定義防止					*/
/* Prevention of redefinition	*/
#pragma once


/* CRI SDK ヘッダー */
#include <cri_le_xpt.h>

/* CRI ADX2 ヘッダー */
#include <cri_le_atom_ex.h>
#include <cri_le_atom_wasapi.h>
/*Dxライブラリ ヘッダー*/
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
	/* エラーコールバック関数 */
	static void UserErrorCallbackFunc(const CriChar8* errid, CriUint32 p1, CriUint32 p2, CriUint32* parray)
	{
		const CriChar8* ErrMsg;

		/* エラー文字列の表示 */
		ErrMsg = criErr_ConvertIdToMessage(errid, p1, p2);
		printfDx("ADX2 エラー : %s\n", ErrMsg);
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
	bool Allocate[256];//trueであれば使用中　falseであれば未使用
	ADXSoundPlayer* SoundPlayerPointer[256];
};

class UMMBGMPLAYER
{
public:

private:

};