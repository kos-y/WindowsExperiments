//*************************************************************************************************
// WinApp.h
// 
// Windows アプリケーションクラス
//*************************************************************************************************
#pragma once

namespace kos_y
{
class CWinApp
{
	HINSTANCE	m_hInstance;		// インスタンスハンドル
	LPTSTR		m_lpCmdLine;		// コマンドライン引数
	int			m_nCmdShow;			// ウィンドウ表示状態

public:
	/// <summary>
	/// Singletonオブジェクト取得
	/// </summary>
	/// <returns>オブジェクト</returns>
	static CWinApp& Get();

	/// <summary>
	/// WinMain 引数の設定
	/// </summary>
	/// <param name="hInstance">インスタンスハンドル</param>
	/// <param name="m_lpCmdLine">コマンドライン引数</param>
	/// <param name="nCmdShow">ウィンドウ表示状態</param>
	void SetWinMainArgs(HINSTANCE hInstance, LPTSTR m_lpCmdLine, int nCmdShow);

	/// <summary>
	/// インスタンスハンドルの取得
	/// </summary>
	/// <returns>インスタンスハンドル</returns>
	HINSTANCE GetInstance();

	/// <summary>
	/// ウィンドウ表示状態の取得
	/// </summary>
	/// <returns>ウィンドウ表示状態</returns>
	int GetCmdShow();

private:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	CWinApp();
};
}
