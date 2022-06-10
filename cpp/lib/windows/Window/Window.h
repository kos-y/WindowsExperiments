//*************************************************************************************************
// Window.h
// 
// ウィンドウクラス
//*************************************************************************************************
#pragma once

#include <memory>

namespace kos_y
{
/// <summary>
/// ウィンドウクラス
/// </summary>
class CWindow
{
	struct DATA;
	std::unique_ptr<DATA> m_pData;

public:
	/// <summary>
	/// ウィンドウの作成
	/// </summary>
	/// <returns>作成結果</returns>
	bool Create();

	/// <summary>
	/// ウィンドウの初回表示
	/// </summary>
	void ShowWindowFirst();

protected:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	CWindow();

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~CWindow();

	/// <summary>
	/// インスタンスハンドルの設定
	/// </summary>
	/// <param name="hInstance">インスタンスハンドル</param>
	void SetInstance(HINSTANCE hInstance);

	/// <summary>
	/// ウィンドウクラス名の設定
	/// </summary>
	/// <param name="lpClassName">ウィンドウクラス名</param>
	void SetClassName(LPCTSTR lpClassName);

	/// <summary>
	/// ウィンドウタウトルの設定
	/// </summary>
	/// <param name="lpTitle">ウィンドウタイトル</param>
	void SetTitle(LPCTSTR lpTitle);

	/// <summary>
	/// アイコンの設定
	/// </summary>
	/// <param name="hIcon">アイコン</param>
	void SetIcon(HICON hIcon);

	/// <summary>
	/// スモールアイコンの設定
	/// </summary>
	/// <param name="hIconSm">スモールアイコン</param>
	void SetIconSm(HICON hIconSm);

	/// <summary>
	/// カーソルの設定
	/// </summary>
	/// <param name="hCursor">カーソル</param>
	void SetCursor(HCURSOR hCursor);

	/// <summary>
	/// 背景ブラシの設定
	/// </summary>
	/// <param name="hBackground">背景ブラシ</param>
	void SetBackground(HBRUSH hBackground);

	/// <summary>
	/// ウィンドウプロシージャの設定
	/// </summary>
	/// <param name="lpfnWndProc">ウィンドウプロシージャ</param>
	void SetWndProc(WNDPROC lpfnWndProc);

	/// <summary>
	/// ウィンドウ表示状態の設定
	/// </summary>
	/// <param name="nCmdShow">ウィンドウ表示状態</param>
	void SetCmdShow(int nCmdShow);

	/// <summary>
	/// WM_CREATEイベントハンドラ
	/// </summary>
	/// <returns>結果</returns>
	virtual LRESULT OnCreate();

	/// <summary>
	/// WM_DESTROYイベントハンドラ
	/// </summary>
	/// <returns>結果</returns>
	virtual LRESULT OnDestroy();

private:
	/// <summary>
	/// ウィンドウクラスの登録
	/// </summary>
	/// <returns>登録結果</returns>
	ATOM RegisterWindowClass();

	/// <summary>
	/// ウィンドウプロシージャ
	/// </summary>
	/// <param name="hWnd">ウィンドウハンドル</param>
	/// <param name="message">メッセージ</param>
	/// <param name="wParam">パラメータ１</param>
	/// <param name="lParam">パラメータ２</param>
	/// <returns>結果</returns>
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};
}
