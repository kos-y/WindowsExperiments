//*************************************************************************************************
// HelloWorldWindow.cpp
// 
// ウィンドウに「Hello! World」と表示する
//*************************************************************************************************

#include "framework.h"
#include "HelloWorldWindow.h"

using namespace kos_y;

//*************************************************************************************************
// エントリーポイント
//
// 引　数：hInstance		インスタンスハンドル
// 　　　　hPrevInstance	（未使用）
// 　　　　lpCmdLine		コマンドライン引数
// 　　　　nCmdShow			ウィンドウ表示状態
#pragma warning(disable:28251)
int APIENTRY _tWinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPTSTR lpCmdLine,
    int nCmdShow
)
#pragma warning(default:28251)
{
    // 未使用警告の排除
    UNREFERENCED_PARAMETER(hPrevInstance);

    // WinMain 引数を保持
    CWinApp::Get().SetWinMainArgs(hInstance, lpCmdLine, nCmdShow);

    // メインウィンドウの作成
    std::unique_ptr<CMainWindow> pWnd(new CMainWindow());
    if (!pWnd->Create()) [[unlikely]] {
        return -1;
    }

    // ウィンドウ初回表示
    pWnd->ShowWindowFirst();

    MSG msg;

    // メイン メッセージ ループ:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}
