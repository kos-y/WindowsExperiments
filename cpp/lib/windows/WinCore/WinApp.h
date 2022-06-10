//*************************************************************************************************
// WinApp.h
// 
// Windows �A�v���P�[�V�����N���X
//*************************************************************************************************
#pragma once

namespace kos_y
{
class CWinApp
{
	HINSTANCE	m_hInstance;		// �C���X�^���X�n���h��
	LPTSTR		m_lpCmdLine;		// �R�}���h���C������
	int			m_nCmdShow;			// �E�B���h�E�\�����

public:
	/// <summary>
	/// Singleton�I�u�W�F�N�g�擾
	/// </summary>
	/// <returns>�I�u�W�F�N�g</returns>
	static CWinApp& Get();

	/// <summary>
	/// WinMain �����̐ݒ�
	/// </summary>
	/// <param name="hInstance">�C���X�^���X�n���h��</param>
	/// <param name="m_lpCmdLine">�R�}���h���C������</param>
	/// <param name="nCmdShow">�E�B���h�E�\�����</param>
	void SetWinMainArgs(HINSTANCE hInstance, LPTSTR m_lpCmdLine, int nCmdShow);

	/// <summary>
	/// �C���X�^���X�n���h���̎擾
	/// </summary>
	/// <returns>�C���X�^���X�n���h��</returns>
	HINSTANCE GetInstance();

	/// <summary>
	/// �E�B���h�E�\����Ԃ̎擾
	/// </summary>
	/// <returns>�E�B���h�E�\�����</returns>
	int GetCmdShow();

private:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	CWinApp();
};
}
