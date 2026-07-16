#pragma once
#define ULONG64_BLANK 0b1111111111111111111111111111111111111111111111111111111111111111

#define FIRST16 0b0000000000000000000000000000000000000000000000001111111111111111
#define FIRST32 0b0000000000000000000000000000000011111111111111111111111111111111

constexpr DWORD dwDefaultListBoxStyle = WS_CHILD | WS_VISIBLE | LBS_NOTIFY;

class ListBoxClass {
private:
	LPCWSTR lpszClassReg;
	HWND hWndHandle;
	HWND hParentHandle;
	HINSTANCE hInstanceHandle;
public:
	ListBoxClass(HINSTANCE hInstance = NULL, HWND hParent = NULL);
	~ListBoxClass();
	ULONG64 CombinePosArgs(INT16 nX, INT16 nY, INT16 nWidth, INT16 nHeight);
	ULONG64 CombineStyleArgs(UINT32 nArgs, UINT32 nExArgs);
	void GenerateWindow(ULONG64 nStyleArgsCombined, ULONG64 nPosCombined, ULONG64 nLongCtrlID);
	void SetFont(HFONT hNewFont);
	HFONT GetFont();
	void DisplayWindow(INT nCmdShow);
	void AddItem(LPCWSTR lpszNewStr);
	void DeleteItem(ULONG64 nLongIndex);
	ULONG64 GetSize();
	ULONG64 GetSelection();
	ULONG64 GetEntryIndex(LPCWSTR lpszFindStr);
	LPCWSTR& GetClassReg();
	HWND& GetWndHandle();
	HWND& GetParentHandle();
	HINSTANCE& GetInstanceHandle();
};