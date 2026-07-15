#pragma once

class BasicFontClass {
private:
	HFONT hFont;
	UINT pxSizing;
	LPCWSTR lpszFontName;
public:
	BasicFontClass(UINT nSz = NULL, LPCWSTR lpszFName = NULL) : pxSizing{ nSz }, lpszFontName{ lpszFName }, hFont{ NULL } {
		return;
	}

	~BasicFontClass() {
		DeleteObject(hFont); // Font must be deleted to free resources and stop leaks
		return;
	}

	void RegisterFont(BOOL bItalic, BOOL bUnderline, BOOL bStrikeOut) {
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

	void ReregisterFont(BOOL bItalic, BOOL bUnderline, BOOL bStrikeOut) {
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

	HFONT& GetFontHandle() {
		return hFont;
	}

	UINT& GetFontSizing() {
		return pxSizing;
	}

	LPCWSTR& GetFontName() {
		return lpszFontName;
	}
};