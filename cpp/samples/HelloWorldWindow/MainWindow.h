//*************************************************************************************************
// MainWindow.h
// 
// ���C���E�B���h�E
//*************************************************************************************************

#pragma once

class CMainWindow : public kos_y::CWindow
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	CMainWindow();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~CMainWindow();

	/// <summary>
	/// WM_PAINT�C�x���g�n���h��
	/// </summary>
	/// <returns>����</returns>
	virtual LRESULT OnPaint();
};
