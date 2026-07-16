#pragma once
#define ULONG64_BLANK 0b1111111111111111111111111111111111111111111111111111111111111111

#define FIRST16 0b0000000000000000000000000000000000000000000000001111111111111111
#define FIRST32 0b0000000000000000000000000000000011111111111111111111111111111111

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