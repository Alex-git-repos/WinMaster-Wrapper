#include "pch.h"
#include "MainWindowClass.h"

MainWindowClass::MainWindowClass(HINSTANCE hInstance, LPCWSTR lpszReg, WNDPROC pWndProc) : hInstanceHandle{ hInstance }, lpszClassReg{ lpszReg }, pWndProcPtr{ pWndProc }, hWndHandle{ NULL }, WndClass{} {
	WndClass.lpszClassName = lpszClassReg;
	WndClass.lpfnWndProc = pWndProcPtr;
	WndClass.hInstance = hInstanceHandle;
}

MainWindowClass::~MainWindowClass() {
	DestroyWindow(hWndHandle); // NOTE: window proceedure must handle WM_DESTROY by manually calling PostQuitMessage(0);. *The only software device that this class is responsible for is the window*
	return;
}

void MainWindowClass::RegisterWindowClass() {
	ATOM aSuccess{ RegisterClass(&WndClass) };
	assert(aSuccess != 0);
	return;
}

ULONG64 MainWindowClass::CombinePosArgs(INT16 nX, INT16 nY, INT16 nWidth, INT16 nHeight) {
	ULONG64 nLongX{ ULONG64_BLANK & nX }, nLongY{ ULONG64_BLANK & nY }, nLongWidth{ ULONG64_BLANK & nWidth }, nLongHeight{ ULONG64_BLANK & nHeight }, nFinalArg{ 0 }; // & With a blank to satisfy the compiler
	nFinalArg = nFinalArg | nLongX;
	nFinalArg = nFinalArg | (nLongY << 16);
	nFinalArg = nFinalArg | (nLongWidth << 32);
	nFinalArg = nFinalArg | (nLongHeight << 48);

	return nFinalArg;
}

ULONG64 MainWindowClass::CombineStyleArgs(UINT32 nArgs, UINT32 nExArgs) {
	ULONG64 nLongArgs{ nArgs }, nLongExArgs{ nExArgs }, nFinalArg{ 0 };
	nFinalArg = nFinalArg | nLongExArgs;
	nFinalArg = nFinalArg | (nLongArgs << 32);

	return nFinalArg;
}

void MainWindowClass::GenerateWindow(ULONG64 nStyleArgsCombined, ULONG64 nPosCombined, LPCWSTR lpszWindowName, HMENU hMenuData, LPVOID pAppStateData) {
	INT32 nX{ (INT16)(nPosCombined & FIRST16) }; // First 16 bits already
	INT32 nY{ (INT16)((nPosCombined >> 16) & FIRST16) }; // Second 16 bits: shift right 16
	INT32 nWidth{ (INT16)((nPosCombined >> 32) & FIRST16) }; // Third 16 bits: shift right 32
	INT32 nHeight{ (INT16)((nPosCombined >> 48) & FIRST16) }; // Fourth 16 bits: shift right 48

	UINT32 nExArgs{ (UINT32)(nStyleArgsCombined & FIRST32) };
	UINT32 nArgs{ (UINT32)((nStyleArgsCombined >> 32) & FIRST32) };
	if (nX == MAXINT16) {
		nX = CW_USEDEFAULT;
	}
	if (nY == MAXINT16) {
		nY = CW_USEDEFAULT;
	}
	if (nWidth == MAXINT16) {
		nWidth = CW_USEDEFAULT;
	}
	if (nHeight == MAXINT16) {
		nHeight = CW_USEDEFAULT;
	}

	hWndHandle = CreateWindowEx(
		nExArgs,
		lpszClassReg,
		lpszWindowName,
		nArgs,
		(INT32)nX, (INT32)nY, (INT32)nWidth, (INT32)nHeight,
		NULL,
		hMenuData,
		hInstanceHandle,
		pAppStateData
	);

	assert(hWndHandle != NULL); // Fail if NULL
	return;
}

void MainWindowClass::DisplayWindow(INT nCmdShow) {
	// Return value ignored because it isn't really useful for the average programmer. See win32 documentation for more details on this function
	ShowWindow(hWndHandle, nCmdShow); // nCmdShow is not necessary for first call but still used for other potential circumstances
	return;
}

LPCWSTR& MainWindowClass::GetClassReg() {
	return lpszClassReg;
}

WNDCLASS& MainWindowClass::GetWndClass() {
	return WndClass;
}

HWND& MainWindowClass::GetWndHandle() {
	return hWndHandle;
}

HINSTANCE& MainWindowClass::GetInstanceHandle() {
	return hInstanceHandle;
}

WNDPROC& MainWindowClass::GetWndProcPtr() {
	return pWndProcPtr;
}