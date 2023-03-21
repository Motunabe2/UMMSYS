/***************************************************************************
 *      インクルード
 *      include
 ***************************************************************************/
#include "UMMADX.h"

ADXSoundPlayer::ADXSoundPlayer(char ACB_FILE[256], char ACF_FILE[256], CriAtomExCueId CRI_CUESHEET)
{
	//PlayerHL = criAtomExPlayer_Create(NULL, NULL, 0);
	criErr_SetCallback(UserErrorCallbackFunc);
	/* メモリアロケータの登録 */
	criAtomEx_SetUserAllocator(UserAllocationFunc,UserFreeFunc, NULL); 
	criAtomEx_Initialize_WASAPI(NULL, NULL, 0);
	criAtomEx_RegisterAcfFile(NULL, ACF_FILE, NULL, 0);
	AcbHL = criAtomExAcb_LoadAcbFile(NULL, ACB_FILE, NULL, NULL, NULL, 0);
	VoicePool = criAtomExVoicePool_AllocateStandardVoicePool(NULL, NULL, 0);
	PlayerHL = criAtomExPlayer_Create(NULL,NULL,0);
	criAtomExPlayer_SetCueId(PlayerHL, AcbHL, CRI_CUESHEET);
}

ADXSoundPlayer :: ~ADXSoundPlayer()
{
	criAtomEx_Finalize_WASAPI();
}
int ADXSoundPlayer::Play()
{
	criAtomExPlayer_Start(this->PlayerHL);
	return 0;//正常終了
}



int UMMSEPLAYER::AddPlayer(char AcbFile[256],char AcfFile[256],CriAtomExCueId CRI_CUESHEET)
{
	SoundPlayerPointer[EmptyPoint] = new ADXSoundPlayer(AcbFile, AcfFile, CRI_CUESHEET);
	return 0;//正常終了
}

int UMMSEPLAYER :: DeletePlayer(char PlayerID)
{
	delete SoundPlayerPointer[PlayerID];
	Allocate[PlayerID] = false;
	EmptyPoint = ReSerchEP();
	return 0;//正常終了
}

int UMMSEPLAYER::ReSerchEP()
{
	bool EF = false;
	char ret;
	for (int cnt = 0;EF == false ;cnt++)
	{
		if (Allocate[cnt] == false)
		{
			ret = cnt;
			EF = true;
		}
	}
	return ret;//値を戻して終了
}
int UMMSEPLAYER :: Play(char PlayerID)
{
	SoundPlayerPointer[PlayerID]->Play();
	return 0;//正常終了
}