class BasicFontClass {
private:
	HFONT hFont;
	UINT pxSizing;
	LPCWSTR lpszFontName;
	DWORD dwFontFamily;
public:
	BasicFontClass(UINT nSz = NULL, LPCWSTR lpszFName = NULL, DWORD dwFamily = FF_MODERN);
	~BasicFontClass();
	void RegisterFont(BOOL bItalic, BOOL bUnderline, BOOL bStrikeOut);
	void ReregisterFont(BOOL bItalic, BOOL bUnderline, BOOL bStrikeOut);
	HFONT& GetFontHandle();
	UINT& GetFontSizing();
	LPCWSTR& GetFontName();
};