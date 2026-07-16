# WinMaster-Wrapper
Build simple apps with ease and swagger using this x64 C++ library! Includes a test app for showcase. [For more info beyond this, like building and running, refer to the wiki]

<img width="285" height="190" src="https://github.com/user-attachments/assets/5f75b182-f47d-4869-8d33-2c0cebe1f9d2" />

## Simplicity
Use OOP to streamline your project:
```cpp
MainWindowClass MainWnd(hInstance, L"ClassReg", WndProc);

ULONG64 Coords{ MainWnd.CombinePosArgs(cpaUseDefault, cpaUseDefault, 300, 200) };
ULONG64 Styles{ MainWnd.CombineStyleArgs(WS_OVERLAPPEDWINDOW, 0) };

MainWnd.RegisterWindowClass();
MainWnd.GenerateWindow(Styles, Coords, L"Title", (HMENU)NULL, &AppStateData);
MainWnd.DisplayWindow(nCmdShow);
```
*Creates a window*

## Both Old School and New Gen
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

-  Use Upper Camel Case (Pascal Case).
-  Prefix variable names with the type if working in a member function or constexpr (e.g. hHandle for HWND, lpszString for LPCWSTR, or nInt for INT).
-  Use Win32 typedefs when possible.
-  Use macros for backend symbols, and constexpr for user-facing symbols (like cpaUseDefault or dwCenterAlign).
-  All internal class variables must be private and have individual methods to return a reference to them.
-  All classes must have custom constructors and destructors, never default ones.
-  Of course, all allocated heap memory must be freed by the end of an object's lifetime (like in the destructor or end of method), with the exception of memory handled by smart pointers.

## Important note!
Many of the methods are untested. Do not use for production applications without thorough consideration.

### Branches
There are three branches: main, testing_development, and alpha_development. To make a contribution, fetch alpha_development. When done, PR to testing_development. You can fetch and run testing on the testing_development branch. When all code is verified, correct, and stylized properly, PR to main and I will review.
