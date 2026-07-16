#pragma once
#define ULONG64_BLANK 0b1111111111111111111111111111111111111111111111111111111111111111

#define FIRST16 0b0000000000000000000000000000000000000000000000001111111111111111
#define FIRST32 0b0000000000000000000000000000000011111111111111111111111111111111

constexpr DWORD dwDefaultEditControl = WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL;

class BasicEditControlClass {
private:
	LPCWSTR lpszClassReg;
	HWND hWndHandle;
	HWND hParentHandle;
	HINSTANCE hInstanceHandle;
public:
	BasicEditControlClass(HINSTANCE hInstance = NULL, HWND hParent = NULL);
	~BasicEditControlClass();
	ULONG64 CombinePosArgs(INT16 nX, INT16 nY, INT16 nWidth, INT16 nHeight);
	ULONG64 CombineStyleArgs(UINT32 nArgs, UINT32 nExArgs);
	void GenerateWindow(ULONG64 nStyleArgsCombined, ULONG64 nPosCombined, LPCWSTR lpszStartText, ULONG64 nLongCtrlID);
	void SetFont(HFONT hNewFont);
	HFONT GetFont();
	std::shared_ptr<WCHAR> GetEditText();
	void DisplayWindow(INT nCmdShow);
	LPCWSTR& GetClassReg();
	HWND& GetWndHandle();
	HWND& GetParentHandle();
	HINSTANCE& GetInstanceHandle();
};