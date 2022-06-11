//*************************************************************************************************
// MainWindow.h
// 
// メインウィンドウ
//*************************************************************************************************

#pragma once

class CMainWindow final : public kos_y::CWindow
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	CMainWindow();

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~CMainWindow();

	/// <summary>
	/// WM_PAINTイベントハンドラ
	/// </summary>
	/// <returns>結果</returns>
	virtual LRESULT OnPaint() override;
};
