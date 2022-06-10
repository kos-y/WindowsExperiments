//*************************************************************************************************
// WinApp.cpp
// 
// Windows アプリケーションクラス
//*************************************************************************************************

#include "pch.h"
#include "WinApp.h"

namespace kos_y
{
/// <summary>
/// Singletonオブジェクトの取得
/// </summary>
/// <returns>オブジェクト</returns>
CWinApp& CWinApp::Get()
{
	static CWinApp obj;
	return obj;
}

/// <summary>
/// WinMain 引数の設定
/// </summary>
/// <param name="hInstance">インスタンスハンドル</param>
/// <param name="m_lpCmdLine">コマンドライン引数</param>
/// <param name="nCmdShow">ウィンドウ表示状態</param>
void CWinApp::SetWinMainArgs(HINSTANCE hInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	m_hInstance = hInstance;
	m_lpCmdLine = lpCmdLine;
	m_nCmdShow  = nCmdShow;
}

/// <summary>
/// インスタンスハンドルの取得
/// </summary>
/// <returns>インスタンスハンドル</returns>
HINSTANCE CWinApp::GetInstance()
{
	return m_hInstance;
}

/// <summary>
/// ウィンドウ表示状態の取得
/// </summary>
/// <returns>ウィンドウ表示状態</returns>
int CWinApp::GetCmdShow()
{
	return m_nCmdShow;
}

/// <summary>
/// コンストラクタ
/// </summary>
CWinApp::CWinApp()
	:m_hInstance(NULL), m_lpCmdLine(nullptr), m_nCmdShow(0)
{
}

}
