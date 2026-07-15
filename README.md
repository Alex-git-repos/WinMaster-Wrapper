# WinMaster-Wrapper
Build simple apps with ease and swagger using this C++ library! Includes a test app for showcase.

## __.vs__ not included in the main branch. Visit the releases page for the corresponding __.vs__ folder.

<img width="285" height="190" alt="Demo" src="https://github.com/user-attachments/assets/5f75b182-f47d-4869-8d33-2c0cebe1f9d2" />

## Simplicity
Use OOP to streamline your project.
```cpp
MainWindowClass MainWnd(hInstance, L"ClassReg", WndProc);

ULONG64 Coords{ MainWnd.CombinePosArgs(cpaUseDefault, cpaUseDefault, 300, 200) };
ULONG64 Styles{ MainWnd.CombineStyleArgs(WS_OVERLAPPEDWINDOW, 0) };

MainWnd.RegisterWindowClass();
MainWnd.GenerateWindow(Styles, Coords, L"Title", (HMENU)NULL, &AppStateData);
MainWnd.DisplayWindow(nCmdShow);
```
## Old School __or__ New Gen
Have fun with the old-school Win32 styles, or go modern using different style combos.

## Control
Write your own window procedure and message loop, and let the library take care of the rest.

## Fonts
Use your own fonts and font sizes using using the BasicFontClass object:
```cpp
BasicFontClass Font(16, L"Consolas");
Font.RegisterFont(FALSE, FALSE, FALSE);
HFONT hSetFont{ Font.GetFontHandle() };
```
Use your font with the *SetFont()* method.

## Open to Contributions
I'm a really bad programmer, so contributions are much needed.

### Some style guidelines
<bl>
  <li>Use Upper Camel Case (Pascal Case).</li>
  <li>Prefix variable names with the type if working in a member function or constexpr (e.g. hHandle for HWND, lpszString for LPCWSTR, or nInt for INT).</li>
  <li>Use Win32 typedefs when possible.</li>
  <li>Use macros for backend symbols, and constexpr for user-facing symbols (like cpaUseDefault or dwCenterAlign).</li>
  <li>All internal class variables must be private and have individual methods to return a reference to them.</li>
  <li>All classes must have custom constructors and destructors, never default ones</li>
  <li>Of course, all allocated heap memory must be freed by the end of an object's lifetime (like in the destructor or end of method).</li>
</bl>

## Important note!
Many of the methods are untested. Do not use for production applications without thorough consideration.
