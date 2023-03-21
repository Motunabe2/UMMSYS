#include "DxLib.h"
#include "UMMLIB.h"

 // �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("UMMSYS_Sample.exe");//�^�C�g����UMMSYS_Sample.exe�ɕύX
	ChangeWindowMode(TRUE);//�E�B�h�E���[�h�ɐݒ�
	SetAlwaysRunFlag(TRUE);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	UMMSYS UMM_Sample;
	
	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}
