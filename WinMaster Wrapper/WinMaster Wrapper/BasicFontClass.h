#pragma once

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