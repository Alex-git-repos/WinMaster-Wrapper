#include "pch.h"
#include "BasicFontClass.h"

BasicFontClass::BasicFontClass(UINT nSz, LPCWSTR lpszFName) : pxSizing{ nSz }, lpszFontName{ lpszFName }, hFont{ NULL } {
	return;
}

BasicFontClass::~BasicFontClass() {
	DeleteObject(hFont); // Font must be deleted to free resources and stop leaks
	return;
}

void BasicFontClass::RegisterFont(BOOL bItalic, BOOL bUnderline, BOOL bStrikeOut) {
	hFont = CreateFont(
		pxSizing, // User-chosen size
		0, // Default width
		0, // No escapement
		0, // Default orientation
		FW_NORMAL, // Normal font weight
		bItalic, // No italics
		bUnderline, // No underline
		bStrikeOut, // No strikeout
		ANSI_CHARSET,
		OUT_TT_PRECIS,
		CLIP_DEFAULT_PRECIS,
		CLEARTYPE_QUALITY,
		FIXED_PITCH | FF_MODERN, // Use "Modern" font family
		lpszFontName);
	return;
}

void BasicFontClass::ReregisterFont(BOOL bItalic, BOOL bUnderline, BOOL bStrikeOut) {
	DeleteObject(hFont);
	hFont = CreateFont(
		pxSizing, // User-chosen size
		0, // Default width
		0, // No escapement
		0, // Default orientation
		FW_NORMAL, // Normal font weight
		bItalic, // No italics
		bUnderline, // No underline
		bStrikeOut, // No strikeout
		ANSI_CHARSET,
		OUT_TT_PRECIS,
		CLIP_DEFAULT_PRECIS,
		CLEARTYPE_QUALITY,
		FIXED_PITCH | FF_MODERN, // Use "Modern" font family
		lpszFontName);
	return;
}

HFONT& BasicFontClass::GetFontHandle() {
	return hFont;
}

UINT& BasicFontClass::GetFontSizing() {
	return pxSizing;
}

LPCWSTR& BasicFontClass::GetFontName() {
	return lpszFontName;
}