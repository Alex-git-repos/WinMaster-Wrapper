#pragma once
#include <Windows.h>
#include <memory>

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

class MainWindowClass {
private:
	LPCWSTR lpszClassReg;
	WNDCLASS WndClass;
	HWND hWndHandle;
	HINSTANCE hInstanceHandle;
	WNDPROC pWndProcPtr;
public:
	MainWindowClass(HINSTANCE hInstance = NULL, LPCWSTR lpszReg = NULL, WNDPROC pWndProc = NULL);
	~MainWindowClass();
	void RegisterWindowClass();
	ULONG64 CombinePosArgs(INT16 nX, INT16 nY, INT16 nWidth, INT16 nHeight);
	ULONG64 CombineStyleArgs(UINT32 nArgs, UINT32 nExArgs);
	void GenerateWindow(ULONG64 nStyleArgsCombined, ULONG64 nPosCombined, LPCWSTR lpszWindowName, HMENU hMenuData, LPVOID pAppStateData);
	void DisplayWindow(INT nCmdShow);
	LPCWSTR& GetClassReg();
	WNDCLASS& GetWndClass();
	HWND& GetWndHandle();
	HINSTANCE& GetInstanceHandle();
	WNDPROC& GetWndProcPtr();
};

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

class BasicFontClass {
private:
	HFONT hFont;
	UINT pxSizing;
	LPCWSTR lpszFontName;
public:
	BasicFontClass(UINT nSz = NULL, LPCWSTR lpszFName = NULL);
	~BasicFontClass();
	void RegisterFont(BOOL bItalic, BOOL bUnderline, BOOL bStrikeOut);
	void ReregisterFont(BOOL bItalic, BOOL bUnderline, BOOL bStrikeOut);
	HFONT& GetFontHandle();
	UINT& GetFontSizing();
	LPCWSTR& GetFontName();
};

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