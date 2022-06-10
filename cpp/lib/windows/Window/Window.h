//*************************************************************************************************
// Window.h
// 
// �E�B���h�E�N���X
//*************************************************************************************************
#pragma once

#include <memory>

namespace kos_y
{
/// <summary>
/// �E�B���h�E�N���X
/// </summary>
class CWindow
{
	struct DATA;
	std::unique_ptr<DATA> m_pData;

public:
	/// <summary>
	/// �E�B���h�E�̍쐬
	/// </summary>
	/// <returns>�쐬����</returns>
	bool Create();

	/// <summary>
	/// �E�B���h�E�̏���\��
	/// </summary>
	void ShowWindowFirst();

protected:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	CWindow();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~CWindow();

	/// <summary>
	/// �C���X�^���X�n���h���̐ݒ�
	/// </summary>
	/// <param name="hInstance">�C���X�^���X�n���h��</param>
	void SetInstance(HINSTANCE hInstance);

	/// <summary>
	/// �E�B���h�E�N���X���̐ݒ�
	/// </summary>
	/// <param name="lpClassName">�E�B���h�E�N���X��</param>
	void SetClassName(LPCTSTR lpClassName);

	/// <summary>
	/// �E�B���h�E�^�E�g���̐ݒ�
	/// </summary>
	/// <param name="lpTitle">�E�B���h�E�^�C�g��</param>
	void SetTitle(LPCTSTR lpTitle);

	/// <summary>
	/// �A�C�R���̐ݒ�
	/// </summary>
	/// <param name="hIcon">�A�C�R��</param>
	void SetIcon(HICON hIcon);

	/// <summary>
	/// �X���[���A�C�R���̐ݒ�
	/// </summary>
	/// <param name="hIconSm">�X���[���A�C�R��</param>
	void SetIconSm(HICON hIconSm);

	/// <summary>
	/// �J�[�\���̐ݒ�
	/// </summary>
	/// <param name="hCursor">�J�[�\��</param>
	void SetCursor(HCURSOR hCursor);

	/// <summary>
	/// �w�i�u���V�̐ݒ�
	/// </summary>
	/// <param name="hBackground">�w�i�u���V</param>
	void SetBackground(HBRUSH hBackground);

	/// <summary>
	/// �E�B���h�E�v���V�[�W���̐ݒ�
	/// </summary>
	/// <param name="lpfnWndProc">�E�B���h�E�v���V�[�W��</param>
	void SetWndProc(WNDPROC lpfnWndProc);

	/// <summary>
	/// �E�B���h�E�\����Ԃ̐ݒ�
	/// </summary>
	/// <param name="nCmdShow">�E�B���h�E�\�����</param>
	void SetCmdShow(int nCmdShow);

	/// <summary>
	/// �E�B���h�E�n���h���̎擾
	/// </summary>
	/// <returns>�E�B���h�E�n���h��</returns>
	HWND GetWnd();

	/// <summary>
	/// WM_CREATE�C�x���g�n���h��
	/// </summary>
	/// <returns>����</returns>
	virtual LRESULT OnCreate();

	/// <summary>
	/// WM_DESTROY�C�x���g�n���h��
	/// </summary>
	/// <returns>����</returns>
	virtual LRESULT OnDestroy();

	/// <summary>
	/// WM_PAINT�C�x���g�n���h��
	/// </summary>
	/// <returns>����</returns>
	virtual LRESULT OnPaint();

private:
	/// <summary>
	/// �E�B���h�E�N���X�̓o�^
	/// </summary>
	/// <returns>�o�^����</returns>
	ATOM RegisterWindowClass();

	/// <summary>
	/// �E�B���h�E�v���V�[�W��
	/// </summary>
	/// <param name="hWnd">�E�B���h�E�n���h��</param>
	/// <param name="message">���b�Z�[�W</param>
	/// <param name="wParam">�p�����[�^�P</param>
	/// <param name="lParam">�p�����[�^�Q</param>
	/// <returns>����</returns>
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};
}
