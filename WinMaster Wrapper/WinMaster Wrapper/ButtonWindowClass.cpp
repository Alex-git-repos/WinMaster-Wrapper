#include "pch.h"
#include "ButtonWindowClass.h"

ButtonWindowClass::ButtonWindowClass(HINSTANCE hInstance, HWND hParent) : hInstanceHandle{ hInstance }, hParentHandle{ hParent }, lpszClassReg{ L"BUTTON" }, hWndHandle{ NULL } {
	return;
}

ButtonWindowClass::~ButtonWindowClass() {
	DestroyWindow(hWndHandle); // NOTE: window proceedure must handle WM_DESTROY by manually calling PostQuitMessage(0);. *The only software device that this class is responsible for is the window*
	return;
}

ULONG64 ButtonWindowClass::CombinePosArgs(INT16 nX, INT16 nY, INT16 nWidth, INT16 nHeight) {
	ULONG64 nLongX{ ULONG64_BLANK & nX }, nLongY{ ULONG64_BLANK & nY }, nLongWidth{ ULONG64_BLANK & nWidth }, nLongHeight{ ULONG64_BLANK & nHeight }, nFinalArg{ 0 }; // & With a blank to satisfy the compiler
	nFinalArg = nFinalArg | nLongX;
	nFinalArg = nFinalArg | (nLongY << 16);
	nFinalArg = nFinalArg | (nLongWidth << 32);
	nFinalArg = nFinalArg | (nLongHeight << 48);

	return nFinalArg;
}

ULONG64 ButtonWindowClass::CombineStyleArgs(UINT32 nArgs, UINT32 nExArgs) {
	ULONG64 nLongArgs{ nArgs }, nLongExArgs{ nExArgs }, nFinalArg{ 0 };
	nFinalArg = nFinalArg | nLongExArgs;
	nFinalArg = nFinalArg | (nLongArgs << 32);

	return nFinalArg;
}

void ButtonWindowClass::GenerateWindow(ULONG64 nStyleArgsCombined, ULONG64 nPosCombined, LPCWSTR lpszButtonText, ULONG64 nLongCtrlID) {
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
		lpszButtonText,
		nArgs,
		(INT32)nX, (INT32)nY, (INT32)nWidth, (INT32)nHeight,
		hParentHandle,
		(HMENU)nLongCtrlID,
		hInstanceHandle,
		NULL
	);

	assert(hWndHandle != NULL); // Fail if NULL
	return;
}

void ButtonWindowClass::SetFont(HFONT hNewFont) {
	SendMessage(hWndHandle, WM_SETFONT, (WPARAM)hNewFont, TRUE);
	return;
}

HFONT ButtonWindowClass::GetFont() {
	return (HFONT)SendMessage(hWndHandle, WM_GETFONT, NULL, NULL);
}

void ButtonWindowClass::EnableButton() {
	EnableWindow(hWndHandle, TRUE);
}

void ButtonWindowClass::DisableButton() {
	EnableWindow(hWndHandle, FALSE);
}

void ButtonWindowClass::DisplayWindow(INT nCmdShow) {
	// Return value ignored because it isn't really useful for the average programmer. See win32 documentation for more details on this function
	ShowWindow(hWndHandle, nCmdShow); // nCmdShow is not necessary for first call but still used for other potential circumstances
	return;
}

LPCWSTR& ButtonWindowClass::GetClassReg() {
	return lpszClassReg;
}

HWND& ButtonWindowClass::GetWndHandle() {
	return hWndHandle;
}

HWND& ButtonWindowClass::GetParentHandle() {
	return hParentHandle;
}

HINSTANCE& ButtonWindowClass::GetInstanceHandle() {
	return hInstanceHandle;
}