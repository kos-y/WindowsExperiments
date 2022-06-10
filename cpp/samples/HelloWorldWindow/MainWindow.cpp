//*************************************************************************************************
// MainWindow.h
// 
// ���C���E�B���h�E
//*************************************************************************************************

#include "framework.h"
#include "HelloWorldWindow.h"

using namespace kos_y;

#define MAX_LOADSTRING	100

#define OUT_TEXT		_T("Hello! World")


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
	::LoadString(hInstance, IDC_HELLOWORLDWINDOW, szWindowClass, MAX_LOADSTRING);

	__super::SetInstance(hInstance);
	__super::SetTitle(szTitle);
	__super::SetClassName(szWindowClass);
	__super::SetCmdShow(CWinApp::Get().GetCmdShow());
	__super::SetIcon(::LoadIcon(hInstance, MAKEINTRESOURCE(IDI_HELLOWORLDWINDOW)));
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

/// <summary>
/// WM_PAINT�C�x���g�n���h��
/// </summary>
/// <returns>���ʒl</returns>
LRESULT CMainWindow::OnPaint()
{
	HDC				hdc    = NULL;
	PAINTSTRUCT		ps     = { 0 };

	hdc = ::BeginPaint(__super::GetWnd(), &ps);
	::TextOut(hdc, 10, 10, OUT_TEXT, (int)::_tcslen(OUT_TEXT));
	::EndPaint(__super::GetWnd(), &ps);

	return 0;
}
