//*************************************************************************************************
// Window.cpp
// 
// ウィンドウクラス
//*************************************************************************************************

#include "pch.h"
#include "Window.h"

using namespace std;

namespace kos_y
{
/// <summary>
/// 内部データ
/// </summary>
struct CWindow::DATA
{
	HINSTANCE				m_hInstance;			// インスタンスハンドル
	basic_string<TCHAR>		m_strWindowClass;		// ウィンドウクラス名
	basic_string<TCHAR>		m_strWindowTitle;		// ウィンドウタイトル
	HICON					m_hIcon;				// アイコン
	HICON					m_hIconSm;				// スモールアイコン
	HCURSOR					m_hCursor;				// カーソル
	HBRUSH					m_hBackground;			// 背景ブラシ
	WNDPROC					m_lpfnWndProc;			// ウィンドウプロシージャ
	int						m_nCmdShow;				// ウィンドウ表示状態

	HWND					m_hWnd;					// ウィンドウハンドル

	CWindow::DATA()
		:m_hInstance(NULL), m_hIcon(NULL), m_hIconSm(NULL), m_hCursor(NULL),
		m_hBackground(NULL), m_lpfnWndProc(NULL), m_nCmdShow(0), m_hWnd(NULL)
	{
	}
};

/// <summary>
/// コンストラクタ
/// </summary>
CWindow::CWindow()
	:m_pData(new DATA())
{
	SetWndProc(WndProc);
}

/// <summary>
/// デストラクタ
/// </summary>
CWindow::~CWindow()
{
}

/// <summary>
/// ウィンドウの作成
/// </summary>
/// <returns>作成結果</returns>
bool CWindow::Create()
{
	// ウィンドウクラスの登録
	if (RegisterWindowClass() == 0) {
		return false;
	}

	// ウィンドウの作成
	m_pData->m_hWnd = ::CreateWindow(
		m_pData->m_strWindowClass.c_str(),	// ウィンドウクラス名
		m_pData->m_strWindowTitle.c_str(),	// ウィンドウタイトル
		WS_OVERLAPPEDWINDOW,				// ウィンドウスタイル
		CW_USEDEFAULT,						// X座標
		0,									// Y座標
		CW_USEDEFAULT,						// 幅
		0,									// 高さ
		nullptr,							// 親ウィンドウハンドル
		nullptr,							// メニューハンドル
		m_pData->m_hInstance,				// インスタンスハンドル
		this								// パラメータ
	);
	if (m_pData->m_hWnd == NULL) {
		return false;
	}

	return true;
}

/// <summary>
/// ウィンドウの初回表示
/// </summary>
void CWindow::ShowWindowFirst()
{
	::ShowWindow(m_pData->m_hWnd, m_pData->m_nCmdShow);
	::UpdateWindow(m_pData->m_hWnd);
}

/// <summary>
/// インスタンスハンドルの設定
/// </summary>
/// <param name="hInstance">インスタンスハンドル</param>
void CWindow::SetInstance(HINSTANCE hInstance)
{
	// ウィンドウ作成後は設定不可
	if (m_pData->m_hWnd != NULL) {
		return;
	}

	m_pData->m_hInstance = hInstance;
}

/// <summary>
/// ウィンドウクラス名の設定
/// </summary>
/// <param name="lpClassName">ウィンドウクラス名</param>
void CWindow::SetClassName(LPCTSTR lpClassName)
{
	// ウィンドウ作成後は設定不可
	if (m_pData->m_hWnd != NULL) {
		return;
	}

	m_pData->m_strWindowClass = lpClassName;
}

/// <summary>
/// ウィンドウタイトルの設定
/// </summary>
/// <param name="lpTitle">ウィンドウタイトル</param>
void CWindow::SetTitle(LPCTSTR lpTitle)
{
	m_pData->m_strWindowTitle = lpTitle;
}

/// <summary>
/// アイコンの設定
/// </summary>
/// <param name="hIcon">アイコン</param>
void CWindow::SetIcon(HICON hIcon)
{
	m_pData->m_hIcon = hIcon;
}

/// <summary>
/// スモールアイコンの設定
/// </summary>
/// <param name="hIconSm">スモールアイコン</param>
void CWindow::SetIconSm(HICON hIconSm)
{
	m_pData->m_hIconSm = hIconSm;
}

/// <summary>
/// カーソルの設定
/// </summary>
/// <param name="hCursor">カーソル</param>
void CWindow::SetCursor(HCURSOR hCursor)
{
	m_pData->m_hCursor = hCursor;
}

/// <summary>
/// 背景ブラシ
/// </summary>
/// <param name="hBackground">背景ブラシ</param>
void CWindow::SetBackground(HBRUSH hBackground)
{
	m_pData->m_hBackground = hBackground;
}

/// <summary>
/// ウィンドウプロシージャの設定
/// </summary>
/// <param name="lpfnWndProc">ウィンドウプロシージャ</param>
void CWindow::SetWndProc(WNDPROC lpfnWndProc)
{
	m_pData->m_lpfnWndProc = lpfnWndProc;
}

/// <summary>
/// ウィンドウ表示状態
/// </summary>
/// <param name="nCmdShow"></param>
void CWindow::SetCmdShow(int nCmdShow)
{
	m_pData->m_nCmdShow = nCmdShow;
}

/// <summary>
/// ウィンドウハンドルの取得
/// </summary>
/// <returns>ウィンドウハンドル</returns>
HWND CWindow::GetWnd()
{
	return m_pData->m_hWnd;
}

/// <summary>
/// WM_CREATEイベントハンドラ
/// </summary>
/// <returns>結果</returns>
LRESULT CWindow::OnCreate()
{
	return 0;
}

/// <summary>
/// WM_DESTROYイベントハンドラ
/// </summary>
/// <returns>結果</returns>
LRESULT CWindow::OnDestroy()
{
	::PostQuitMessage(0);

	return 0;
}

/// <summary>
/// WM_PAINTイベントハンドラ
/// </summary>
/// <returns>結果</returns>
LRESULT CWindow::OnPaint()
{
	return 0;
}

/// <summary>
/// ウィンドウクラスの登録
/// </summary>
/// <returns>登録結果</returns>
ATOM CWindow::RegisterWindowClass()
{
	WNDCLASSEX wc = { sizeof(WNDCLASSEX) };

	wc.style         = CS_HREDRAW | CS_VREDRAW;				// ウィンドウクラススタイル
	wc.hInstance     = m_pData->m_hInstance;				// インスタンスハンドル
	wc.lpszClassName = m_pData->m_strWindowClass.c_str();	// ウィンドウクラス名
	wc.hIcon         = m_pData->m_hIcon;					// アイコン
	wc.hIconSm       = m_pData->m_hIconSm;					// スモールアイコン
	wc.hCursor       = m_pData->m_hCursor;					// カーソル
	wc.hbrBackground = m_pData->m_hBackground;				// 背景ブラシ
	wc.lpfnWndProc   = m_pData->m_lpfnWndProc;				// ウィンドウプロシージャ

	return ::RegisterClassEx(&wc);
}

/// <summary>
/// ウィンドウプロシージャ
/// </summary>
/// <param name="hWnd">ウィンドウハンドル</param>
/// <param name="message">メッセージ</param>
/// <param name="wParam">パラメータ１</param>
/// <param name="lParam">パラメータ２</param>
/// <returns>結果</returns>
LRESULT CALLBACK CWindow::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	CWindow* pWnd = reinterpret_cast<CWindow*>(::GetWindowLongPtr(hWnd, GWLP_USERDATA));
	LPCREATESTRUCT lpCreate = nullptr;

	switch (message) {
	case WM_CREATE:
		// CreateWindow時に渡されたポインタを保持
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

