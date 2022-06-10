//*************************************************************************************************
// MainWindow.h
// 
// ���C���E�B���h�E
//*************************************************************************************************

#include "stdafx.h"
#include "SimpleWindow.h"

using namespace kos_y;

#define MAX_LOADSTRING 100


/// <summary>
/// �R���X�g���N�^
/// </summary>
CMainWindow::CMainWindow()
	:CWindow()
{
	HINSTANCE hInstance = CWinApp::Get().GetInstance();

	TCHAR szTitle[MAX_LOADSTRING];
	TCHAR szWindowClass[MAX_LOADSTRING];

	// �����񃊃\�[�X�̓Ǎ�
	::LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	::LoadString(hInstance, IDC_SIMPLEWINDOW, szWindowClass, MAX_LOADSTRING);

	__super::SetInstance(hInstance);
	__super::SetTitle(szTitle);
	__super::SetClassName(szWindowClass);
	__super::SetCmdShow(CWinApp::Get().GetCmdShow());
	__super::SetIcon(::LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SIMPLEWINDOW)));
	__super::SetIconSm(::LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SMALL)));
	__super::SetCursor(::LoadCursor(nullptr, IDC_ARROW));
	__super::SetBackground((HBRUSH)(COLOR_WINDOW + 1));


}

/// <summary>
/// �f�X�g���N�^
/// </summary>
CMainWindow::~CMainWindow()
{
}