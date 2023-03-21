#include "DxLib.h"
#include "UMMLIB.h"

 // プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("UMMSYS_Sample.exe");//タイトルをUMMSYS_Sample.exeに変更
	ChangeWindowMode(TRUE);//ウィドウモードに設定
	SetAlwaysRunFlag(TRUE);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	UMMSYS UMM_Sample;
	
	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
