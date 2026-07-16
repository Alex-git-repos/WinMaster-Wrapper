#pragma once
#define ULONG64_BLANK 0b1111111111111111111111111111111111111111111111111111111111111111

#define FIRST16 0b0000000000000000000000000000000000000000000000001111111111111111
#define FIRST32 0b0000000000000000000000000000000011111111111111111111111111111111

constexpr DWORD dwDefaultButtonStyle = WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER;
constexpr DWORD dwFlatButtonStyle = WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_FLAT;

class ButtonWindowClass {
private:
	LPCWSTR lpszClassReg;
	HWND hWndHandle;
	HWND hParentHandle;
	HINSTANCE hInstanceHandle;
public:
	ButtonWindowClass(HINSTANCE hInstance = NULL, HWND hParent = NULL);
	~ButtonWindowClass();
	ULONG64 CombinePosArgs(INT16 nX, INT16 nY, INT16 nWidth, INT16 nHeight);
	ULONG64 CombineStyleArgs(UINT32 nArgs, UINT32 nExArgs);
	void GenerateWindow(ULONG64 nStyleArgsCombined, ULONG64 nPosCombined, LPCWSTR lpszButtonText, ULONG64 nLongCtrlID);
	void SetFont(HFONT hNewFont);
	HFONT GetFont();
	void EnableButton();
	void DisableButton();
	void DisplayWindow(INT nCmdShow);
	LPCWSTR& GetClassReg();
	HWND& GetWndHandle();
	HWND& GetParentHandle();
	HINSTANCE& GetInstanceHandle();
};