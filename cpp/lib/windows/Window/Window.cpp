//*************************************************************************************************
// Window.cpp
// 
// �E�B���h�E�N���X
//*************************************************************************************************

#include "pch.h"
#include "Window.h"

using namespace std;

namespace kos_y
{
/// <summary>
/// �����f�[�^
/// </summary>
struct CWindow::DATA
{
	HINSTANCE				m_hInstance;			// �C���X�^���X�n���h��
	basic_string<TCHAR>		m_strWindowClass;		// �E�B���h�E�N���X��
	basic_string<TCHAR>		m_strWindowTitle;		// �E�B���h�E�^�C�g��
	HICON					m_hIcon;				// �A�C�R��
	HICON					m_hIconSm;				// �X���[���A�C�R��
	HCURSOR					m_hCursor;				// �J�[�\��
	HBRUSH					m_hBackground;			// �w�i�u���V
	WNDPROC					m_lpfnWndProc;			// �E�B���h�E�v���V�[�W��
	int						m_nCmdShow;				// �E�B���h�E�\�����

	HWND					m_hWnd;					// �E�B���h�E�n���h��

	CWindow::DATA()
		:m_hInstance(NULL), m_hIcon(NULL), m_hIconSm(NULL), m_hCursor(NULL),
		m_hBackground(NULL), m_lpfnWndProc(NULL), m_nCmdShow(0), m_hWnd(NULL)
	{
	}
};

/// <summary>
/// �R���X�g���N�^
/// </summary>
CWindow::CWindow()
	:m_pData(new DATA())
{
	SetWndProc(WndProc);
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
CWindow::~CWindow()
{
}

/// <summary>
/// �E�B���h�E�̍쐬
/// </summary>
/// <returns>�쐬����</returns>
bool CWindow::Create()
{
	// �E�B���h�E�N���X�̓o�^
	if (RegisterWindowClass() == 0) [[unlikely]] {
		return false;
	}

	// �E�B���h�E�̍쐬
	m_pData->m_hWnd = ::CreateWindow(
		m_pData->m_strWindowClass.c_str(),	// �E�B���h�E�N���X��
		m_pData->m_strWindowTitle.c_str(),	// �E�B���h�E�^�C�g��
		WS_OVERLAPPEDWINDOW,				// �E�B���h�E�X�^�C��
		CW_USEDEFAULT,						// X���W
		0,									// Y���W
		CW_USEDEFAULT,						// ��
		0,									// ����
		nullptr,							// �e�E�B���h�E�n���h��
		nullptr,							// ���j���[�n���h��
		m_pData->m_hInstance,				// �C���X�^���X�n���h��
		this								// �p�����[�^
	);
	if (m_pData->m_hWnd == NULL) [[unlikely]] {
		return false;
	}

	return true;
}

/// <summary>
/// �E�B���h�E�̏���\��
/// </summary>
void CWindow::ShowWindowFirst()
{
	::ShowWindow(m_pData->m_hWnd, m_pData->m_nCmdShow);
	::UpdateWindow(m_pData->m_hWnd);
}

/// <summary>
/// �C���X�^���X�n���h���̐ݒ�
/// </summary>
/// <param name="hInstance">�C���X�^���X�n���h��</param>
void CWindow::SetInstance(HINSTANCE hInstance)
{
	// �E�B���h�E�쐬��͐ݒ�s��
	if (m_pData->m_hWnd != NULL) [[unlikely]] {
		return;
	}

	m_pData->m_hInstance = hInstance;
}

/// <summary>
/// �E�B���h�E�N���X���̐ݒ�
/// </summary>
/// <param name="lpClassName">�E�B���h�E�N���X��</param>
void CWindow::SetClassName(LPCTSTR lpClassName)
{
	// �E�B���h�E�쐬��͐ݒ�s��
	if (m_pData->m_hWnd != NULL) [[unlikely]] {
		return;
	}

	if (lpClassName == nullptr) [[unlikely]] {
		return;
	}

	m_pData->m_strWindowClass = lpClassName;
}

/// <summary>
/// �E�B���h�E�^�C�g���̐ݒ�
/// </summary>
/// <param name="lpTitle">�E�B���h�E�^�C�g��</param>
void CWindow::SetTitle(LPCTSTR lpTitle)
{
	if (lpTitle == nullptr) [[unlikely]] {
		return;
	}

	m_pData->m_strWindowTitle = lpTitle;
}

/// <summary>
/// �A�C�R���̐ݒ�
/// </summary>
/// <param name="hIcon">�A�C�R��</param>
void CWindow::SetIcon(HICON hIcon)
{
	m_pData->m_hIcon = hIcon;
}

/// <summary>
/// �X���[���A�C�R���̐ݒ�
/// </summary>
/// <param name="hIconSm">�X���[���A�C�R��</param>
void CWindow::SetIconSm(HICON hIconSm)
{
	m_pData->m_hIconSm = hIconSm;
}

/// <summary>
/// �J�[�\���̐ݒ�
/// </summary>
/// <param name="hCursor">�J�[�\��</param>
void CWindow::SetCursor(HCURSOR hCursor)
{
	m_pData->m_hCursor = hCursor;
}

/// <summary>
/// �w�i�u���V
/// </summary>
/// <param name="hBackground">�w�i�u���V</param>
void CWindow::SetBackground(HBRUSH hBackground)
{
	m_pData->m_hBackground = hBackground;
}

/// <summary>
/// �E�B���h�E�v���V�[�W���̐ݒ�
/// </summary>
/// <param name="lpfnWndProc">�E�B���h�E�v���V�[�W��</param>
void CWindow::SetWndProc(WNDPROC lpfnWndProc)
{
	if (lpfnWndProc == nullptr) [[unlikely]] {
		return;
	}

	m_pData->m_lpfnWndProc = lpfnWndProc;
}

/// <summary>
/// �E�B���h�E�\����Ԃ̐ݒ�
/// </summary>
/// <param name="nCmdShow">�E�B���h�E�\�����</param>
void CWindow::SetCmdShow(int nCmdShow)
{
	m_pData->m_nCmdShow = nCmdShow;
}

/// <summary>
/// �E�B���h�E�n���h���̎擾
/// </summary>
/// <returns>�E�B���h�E�n���h��</returns>
HWND CWindow::GetWnd()
{
	return m_pData->m_hWnd;
}

/// <summary>
/// WM_CREATE�C�x���g�n���h��
/// </summary>
/// <returns>����</returns>
LRESULT CWindow::OnCreate()
{
	return 0;
}

/// <summary>
/// WM_DESTROY�C�x���g�n���h��
/// </summary>
/// <returns>����</returns>
LRESULT CWindow::OnDestroy()
{
	::PostQuitMessage(0);

	return 0;
}

/// <summary>
/// WM_PAINT�C�x���g�n���h��
/// </summary>
/// <returns>����</returns>
LRESULT CWindow::OnPaint()
{
	return 0;
}

/// <summary>
/// �E�B���h�E�N���X�̓o�^
/// </summary>
/// <returns>�o�^����</returns>
ATOM CWindow::RegisterWindowClass()
{
	WNDCLASSEX wc = { sizeof(WNDCLASSEX) };

	wc.style         = CS_HREDRAW | CS_VREDRAW;				// �E�B���h�E�N���X�X�^�C��
	wc.hInstance     = m_pData->m_hInstance;				// �C���X�^���X�n���h��
	wc.lpszClassName = m_pData->m_strWindowClass.c_str();	// �E�B���h�E�N���X��
	wc.hIcon         = m_pData->m_hIcon;					// �A�C�R��
	wc.hIconSm       = m_pData->m_hIconSm;					// �X���[���A�C�R��
	wc.hCursor       = m_pData->m_hCursor;					// �J�[�\��
	wc.hbrBackground = m_pData->m_hBackground;				// �w�i�u���V
	wc.lpfnWndProc   = m_pData->m_lpfnWndProc;				// �E�B���h�E�v���V�[�W��

	return ::RegisterClassEx(&wc);
}

/// <summary>
/// �E�B���h�E�v���V�[�W��
/// </summary>
/// <param name="hWnd">�E�B���h�E�n���h��</param>
/// <param name="message">���b�Z�[�W</param>
/// <param name="wParam">�p�����[�^�P</param>
/// <param name="lParam">�p�����[�^�Q</param>
/// <returns>����</returns>
LRESULT CALLBACK CWindow::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	CWindow* pWnd = reinterpret_cast<CWindow*>(::GetWindowLongPtr(hWnd, GWLP_USERDATA));
	LPCREATESTRUCT lpCreate = nullptr;

	switch (message) {
	case WM_CREATE:
		// CreateWindow���ɓn���ꂽ�|�C���^��ێ�
		lpCreate = reinterpret_cast<LPCREATESTRUCT>(lParam);
		::SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(lpCreate->lpCreateParams));

		pWnd = reinterpret_cast<CWindow*>(lpCreate->lpCreateParams);
		return pWnd->OnCreate();

	case WM_DESTROY:
		if (pWnd != nullptr) {
			return pWnd->OnDestroy();
		}
		break;

	case WM_PAINT:
		if (pWnd != nullptr) {
			return pWnd->OnPaint();
		}
		break;
	}

	return ::DefWindowProc(hWnd, message, wParam, lParam);
}

}

