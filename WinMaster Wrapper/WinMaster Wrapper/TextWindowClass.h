#pragma once
#define ULONG64_BLANK 0b1111111111111111111111111111111111111111111111111111111111111111

#define FIRST16 0b0000000000000000000000000000000000000000000000001111111111111111
#define FIRST32 0b0000000000000000000000000000000011111111111111111111111111111111

constexpr DWORD dwDefaultTextStyle = WS_CHILD | WS_VISIBLE;
constexpr DWORD dwBorderedTextStyle = WS_CHILD | WS_VISIBLE | WS_BORDER;
constexpr DWORD dwLeftAlign = ES_LEFT;
constexpr DWORD dwRightAlign = ES_RIGHT;
constexpr DWORD dwCenterAlign = ES_CENTER;

class TextWindowClass {
private:
	LPCWSTR lpszClassReg;
	HWND hWndHandle;
	HWND hParentHandle;
	HINSTANCE hInstanceHandle;
public:
	TextWindowClass(HINSTANCE hInstance = NULL, HWND hParent = NULL);
	~TextWindowClass();
	ULONG64 CombinePosArgs(INT16 nX, INT16 nY, INT16 nWidth, INT16 nHeight);
	ULONG64 CombineStyleArgs(UINT32 nArgs, UINT32 nExArgs);
	void GenerateWindow(ULONG64 nStyleArgsCombined, ULONG64 nPosCombined, LPCWSTR lpszText);
	void SetFont(HFONT hNewFont);
	HFONT GetFont();
	void DisplayWindow(INT nCmdShow);
	LPCWSTR& GetClassReg();
	HWND& GetWndHandle();
	HWND& GetParentHandle();
	HINSTANCE& GetInstanceHandle();
};