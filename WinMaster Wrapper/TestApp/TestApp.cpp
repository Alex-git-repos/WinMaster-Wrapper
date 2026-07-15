#include "pch.h"
#include "uch.h"

using namespace std;

LRESULT CALLBACK WndProc(HWND hWndHandle, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	case WM_CTLCOLORSTATIC: {
		HDC hDC{ (HDC)wParam };
		SetBkColor(hDC, RGB(255, 255, 255));
		return (LRESULT)CreateSolidBrush(RGB(255, 255, 255));
	}
	case WM_PAINT: {
		PAINTSTRUCT PaintStructure{};
		HDC hDC{ BeginPaint(hWndHandle, &PaintStructure) };
		FillRect(hDC, &PaintStructure.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
		EndPaint(hWndHandle, &PaintStructure);
		return 0;
	}
	case WM_CLOSE:
		DestroyWindow(hWndHandle);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hWndHandle, uMsg, wParam, lParam);
	}
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
	// To-do: add cue text to edits
	BasicFontClass Font(16, L"Consolas");
	Font.RegisterFont(FALSE, FALSE, FALSE);
	HFONT hSetFont{ Font.GetFontHandle() };

	MainWindowClass MainWnd(hInstance, L"TestApp", WndProc);
	TextWindowClass TextWnd(hInstance);
	ButtonWindowClass ButtonWnd(hInstance);
	ListBoxClass ListWnd(hInstance);
	BasicEditControlClass EditWnd(hInstance);

	ULONG64 nLongCombinedPos{ MainWnd.CombinePosArgs(cpaUseDefault, cpaUseDefault, 300, 200) };
	ULONG64 nLongCombinedStyles{ MainWnd.CombineStyleArgs(WS_OVERLAPPEDWINDOW, 0) };

	MainWnd.RegisterWindowClass();
	MainWnd.GenerateWindow(nLongCombinedStyles, nLongCombinedPos, L"TestApp", (HMENU)NULL, NULL);

	TextWnd.GetParentHandle() = MainWnd.GetWndHandle();
	ButtonWnd.GetParentHandle() = MainWnd.GetWndHandle();
	ListWnd.GetParentHandle() = MainWnd.GetWndHandle();
	EditWnd.GetParentHandle() = MainWnd.GetWndHandle();

	nLongCombinedPos = TextWnd.CombinePosArgs(10, 10, 90, 40);
	nLongCombinedStyles = TextWnd.CombineStyleArgs(dwDefaultTextStyle | dwCenterAlign, NULL);

	TextWnd.GenerateWindow(nLongCombinedStyles, nLongCombinedPos, L"Hello, world.");
	TextWnd.SetFont(hSetFont);

	nLongCombinedPos = ButtonWnd.CombinePosArgs(10, 50, 90, 30);
	nLongCombinedStyles = ButtonWnd.CombineStyleArgs(dwDefaultButtonStyle, 0);

	ButtonWnd.GenerateWindow(nLongCombinedStyles, nLongCombinedPos, L"Click Me!!", 1000);
	ButtonWnd.SetFont(hSetFont);

	nLongCombinedPos = ListWnd.CombinePosArgs(110, 10, 160, 140);
	nLongCombinedStyles = ListWnd.CombineStyleArgs(dwDefaultListBoxStyle, WS_EX_CLIENTEDGE);
	
	ListWnd.GenerateWindow(nLongCombinedStyles, nLongCombinedPos, 1001);
	ListWnd.SetFont(hSetFont);

	nLongCombinedPos = EditWnd.CombinePosArgs(10, 90, 90, 30);
	nLongCombinedStyles = EditWnd.CombineStyleArgs(dwDefaultEditControl, WS_EX_CLIENTEDGE);

	EditWnd.GenerateWindow(nLongCombinedStyles, nLongCombinedPos, L"'Sup", 1002);
	EditWnd.SetFont(hSetFont);

	MainWnd.DisplayWindow(nCmdShow);
	TextWnd.DisplayWindow(nCmdShow);
	ButtonWnd.DisplayWindow(nCmdShow);
	ListWnd.DisplayWindow(nCmdShow);
	EditWnd.DisplayWindow(nCmdShow);

	ListWnd.AddItem(L"Listbox item!");

	MSG Msg;
	while (GetMessage(&Msg, MainWnd.GetWndHandle(), NULL, NULL) > 0) {
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return 0;
}