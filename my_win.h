#ifndef MY_WIN_H
#define MY_WIN_H

#include "com.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define HANDLE_MACRO(y)                                                                                                                                        \
  typedef struct _tag_handle_##y {                                                                                                                             \
    int dummy;                                                                                                                                                 \
  } *y;

HANDLE_MACRO(Win_HINSTANCE);
HANDLE_MACRO(Win_HWND);
HANDLE_MACRO(Win_HMENU);
HANDLE_MACRO(Win_HICON);
HANDLE_MACRO(Win_HCURSOR);
HANDLE_MACRO(Win_HBRUSH);
HANDLE_MACRO(Win_HDC);
HANDLE_MACRO(Win_HANDLE);
HANDLE_MACRO(Win_HMONITOR);
typedef Win_HINSTANCE Win_HMODULE;
typedef uint16_t Win_WCHAR;
typedef int32_t Win_HRESULT;
typedef int64_t Win_LPARAM, Win_LRESULT;
typedef uint64_t Win_WPARAM;
typedef uint16_t Win_ATOM;
typedef uint32_t Win_COLORREF;

typedef struct {
  int32_t x;
  int32_t y;
} Win_POINT;

typedef struct {
  int32_t cx;
  int32_t cy;
} Win_SIZE;

typedef struct {
  Win_HWND hwnd;
  uint32_t message;
  Win_WPARAM wParam;
  Win_LPARAM lParam;
  uint32_t time;
  Win_POINT pt;
} Win_MSG;

typedef Win_LRESULT(STDCALL *Win_WNDPROC)(Win_HWND, uint32_t, Win_WPARAM, Win_LPARAM);

typedef struct {
  uint32_t style;
  Win_WNDPROC lpfnWndProc;
  int32_t cbClsExtra;
  int32_t cbWndExtra;
  Win_HINSTANCE hInstance;
  Win_HICON hIcon;
  Win_HCURSOR hCursor;
  Win_HBRUSH hbrBackground;
  const Win_WCHAR *lpszMenuName;
  const Win_WCHAR *lpszClassName;
} Win_WNDCLASSW;

typedef struct {
  int32_t left;
  int32_t top;
  int32_t right;
  int32_t bottom;
} Win_RECT;

typedef struct {
  Win_HDC hdc;
  int32_t fErase;
  Win_HDC rcPaint;
  int32_t fRestore;
  int32_t fIncUpdate;
  uint8_t rgbReserved[32];
} Win_PAINTSTRUCT;

typedef struct {
  uint32_t cb;
  Win_WCHAR *lpReserved;
  Win_WCHAR *lpDesktop;
  Win_WCHAR *lpTitle;
  uint32_t dwX;
  uint32_t dwY;
  uint32_t dwXSize;
  uint32_t dwYSize;
  uint32_t dwXCountChars;
  uint32_t dwYCountChars;
  uint32_t dwFillAttribute;
  uint32_t dwFlags;
  uint16_t wShowWindow;
  uint16_t cbReserved2;
  uint8_t *lpReserved2;
  Win_HANDLE hStdInput;
  Win_HANDLE hStdOutput;
  Win_HANDLE hStdError;
} Win_STARTUPINFOW;

typedef struct {
  uint32_t dwLowDateTime;
  uint32_t dwHighDateTime;
} Win_FILETIME;

enum { Win_LF_FACESIZE = 32 };

typedef struct {
  int32_t lfHeight;
  int32_t lfWidth;
  int32_t lfEscapement;
  int32_t lfOrientation;
  int32_t lfWeight;
  uint8_t lfItalic;
  uint8_t lfUnderline;
  uint8_t lfStrikeOut;
  uint8_t lfCharSet;
  uint8_t lfOutPrecision;
  uint8_t lfClipPrecision;
  uint8_t lfQuality;
  uint8_t lfPitchAndFamily;
  Win_WCHAR lfFaceName[Win_LF_FACESIZE];
} Win_LOGFONTW;

#ifdef GLOBAL_EXTERN_DEFINE
#define EXTERN
#else
#define EXTERN extern
#endif

EXTERN Win_HMODULE(STDCALL *Win_LoadLibraryW)(const Win_WCHAR *lpLibFileName);
EXTERN int32_t(STDCALL *Win_FreeLibrary)(Win_HMODULE hLibModule);
typedef int64_t(STDCALL *Win_FARPROC)();
EXTERN Win_FARPROC(STDCALL *Win_GetProcAddress)(Win_HMODULE hModule, const char *lpProcName);
EXTERN Win_WCHAR *(STDCALL *Win_GetCommandLineW)();

EXTERN void(STDCALL *Win_PostQuitMessage)(int32_t nExitCode);
EXTERN Win_LRESULT(STDCALL *Win_DefWindowProcW)(Win_HWND hWnd, uint32_t Msg, Win_WPARAM wParam, Win_LPARAM lParam);
EXTERN Win_ATOM(STDCALL *Win_RegisterClassW)(const Win_WNDCLASSW *lpWndClass);
EXTERN Win_HWND(STDCALL *Win_CreateWindowExW)(uint32_t dwExStyle, const Win_WCHAR *lpClassName, const Win_WCHAR *lpWindowName, uint32_t dwStyle, int32_t X,
                                              int32_t Y, int32_t nWidth, int32_t nHeight, Win_HWND hWndParent, Win_HMENU hMenu, Win_HINSTANCE hInstance,
                                              void *lpParam);
EXTERN int32_t(STDCALL *Win_ShowWindow)(Win_HWND hWnd, int32_t nCmdShow);
EXTERN int32_t(STDCALL *Win_GetMessageW)(Win_MSG *lpMsg, Win_HWND hWnd, uint32_t wMsgFilterMin, uint32_t wMsgFilterMax);
EXTERN int32_t(STDCALL *Win_TranslateMessage)(const Win_MSG *lpMsg);
EXTERN Win_LRESULT(STDCALL *Win_DispatchMessageW)(const Win_MSG *lpMsg);
EXTERN int32_t(STDCALL *Win_GetClientRect)(Win_HWND hWnd, Win_RECT *lpRect);
EXTERN Win_HCURSOR(STDCALL *Win_LoadCursorW)(Win_HINSTANCE hInstance, const Win_WCHAR *lpCursorName);

EXTERN Win_HRESULT(STDCALL *Win_CoInitializeEx)(void *pvReserved, uint32_t dwCoInit);
EXTERN void(STDCALL *Win_CoUninitialize)(void);
EXTERN Win_HDC(STDCALL *Win_BeginPaint)(Win_HWND hWnd, Win_PAINTSTRUCT *lpPaint);
EXTERN int32_t(STDCALL *Win_EndPaint)(Win_HWND hWnd, const Win_PAINTSTRUCT *lpPaint);

EXTERN int32_t(STDCALL *Win_GetClientRect)(Win_HWND hWnd, Win_RECT *lpRect);

EXTERN void(STDCALL *Win_PostQuitMessage)(int32_t nExitCode);

EXTERN Win_HMODULE(STDCALL *Win_GetModuleHandleW)(Win_WCHAR *lpModuleName);
EXTERN void(STDCALL *Win_GetStartupInfoW)(Win_STARTUPINFOW *lpStartupInfo);

// mouse cursor
#define Win_IDC_ARROW       ((void *)32512)
#define Win_IDC_IBEAM       ((void *)32513)
#define Win_IDC_WAIT        ((void *)32514)
#define Win_IDC_CROSS       ((void *)32515)
#define Win_IDC_UPARROW     ((void *)32516)
#define Win_IDC_SIZE        ((void *)32640)
#define Win_IDC_ICON        ((void *)32641)
#define Win_IDC_SIZENWSE    ((void *)32642)
#define Win_IDC_SIZENESW    ((void *)32643)
#define Win_IDC_SIZEWE      ((void *)32644)
#define Win_IDC_SIZENS      ((void *)32645)
#define Win_IDC_SIZEALL     ((void *)32646)
#define Win_IDC_NO          ((void *)32648)
#define Win_IDC_HAND        ((void *)32649)
#define Win_IDC_APPSTARTING ((void *)32650)
#define Win_IDC_HELP        ((void *)32651)

#define Win_WS_OVERLAPPED   (0x00000000)
#define Win_WS_POPUP        (0x80000000)
#define Win_WS_CHILD        (0x40000000)
#define Win_WS_MINIMIZE     (0x20000000)
#define Win_WS_VISIBLE      (0x10000000)
#define Win_WS_DISABLED     (0x08000000)
#define Win_WS_CLIPSIBLINGS (0x04000000)
#define Win_WS_CLIPCHILDREN (0x02000000)
#define Win_WS_MAXIMIZE     (0x01000000)
#define Win_WS_CAPTION      (0x00C00000)
#define Win_WS_BORDER       (0x00800000)
#define Win_WS_DLGFRAME     (0x00400000)
#define Win_WS_VSCROLL      (0x00200000)
#define Win_WS_HSCROLL      (0x00100000)
#define Win_WS_SYSMENU      (0x00080000)
#define Win_WS_THICKFRAME   (0x00040000)
#define Win_WS_GROUP        (0x00020000)
#define Win_WS_TABSTOP      (0x00010000)
#define Win_WS_MINIMIZEBOX  (0x00020000)
#define Win_WS_MAXIMIZEBOX  (0x00010000)
#define Win_WS_TILED        Win_WS_OVERLAPPED
#define Win_WS_ICONIC       Win_WS_MINIMIZE
#define Win_WS_SIZEBOX      Win_WS_THICKFRAME
#define Win_WS_TILEDWINDOW  Win_WS_OVERLAPPEDWINDOW

#define Win_WS_OVERLAPPEDWINDOW (Win_WS_OVERLAPPED | Win_WS_CAPTION | Win_WS_SYSMENU | Win_WS_THICKFRAME | Win_WS_MINIMIZEBOX | Win_WS_MAXIMIZEBOX)
#define Win_WS_POPUPWINDOW      (Win_WS_POPUP | Win_WS_BORDER | Win_WS_SYSMENU)
#define Win_WS_CHILDWINDOW      (Win_WS_CHILD)

#define Win_CW_USEDEFAULT ((int)0x80000000)

#define Win_WM_NULL           0x0000
#define Win_WM_CREATE         0x0001
#define Win_WM_DESTROY        0x0002
#define Win_WM_MOVE           0x0003
#define Win_WM_SIZE           0x0005
#define Win_WM_ACTIVATE       0x0006
#define Win_WA_INACTIVE       0
#define Win_WA_ACTIVE         1
#define Win_WA_CLICKACTIVE    2
#define Win_WM_SETFOCUS       0x0007
#define Win_WM_KILLFOCUS      0x0008
#define Win_WM_ENABLE         0x000A
#define Win_WM_SETREDRAW      0x000B
#define Win_WM_SETTEXT        0x000C
#define Win_WM_GETTEXT        0x000D
#define Win_WM_GETTEXTLENGTH  0x000E
#define Win_WM_PAINT          0x000F
#define Win_WM_CLOSE          0x0010
#define Win_WM_QUIT           0x0012
#define Win_WM_ERASEBKGND     0x0014
#define Win_WM_SYSCOLORCHANGE 0x0015
#define Win_WM_SHOWWINDOW     0x0018
#define Win_WM_WININICHANGE   0x001A
#define Win_WM_SETTINGCHANGE  Win_WM_WININICHANGE
#define Win_WM_DEVMODECHANGE  0x001B
#define Win_WM_ACTIVATEAPP    0x001C
#define Win_WM_FONTCHANGE     0x001D
#define Win_WM_TIMECHANGE     0x001E
#define Win_WM_CANCELMODE     0x001F
#define Win_WM_SETCURSOR      0x0020
#define Win_WM_MOUSEACTIVATE  0x0021
#define Win_WM_CHILDACTIVATE  0x0022
#define Win_WM_QUEUESYNC      0x0023
#define Win_WM_GETMINMAXINFO  0x0024

#define Win_STARTF_USESHOWWINDOW 0x00000001

#define Win_SW_HIDE            0
#define Win_SW_SHOWNORMAL      1
#define Win_SW_NORMAL          1
#define Win_SW_SHOWMINIMIZED   2
#define Win_SW_SHOWMAXIMIZED   3
#define Win_SW_MAXIMIZE        3
#define Win_SW_SHOWNOACTIVATE  4
#define Win_SW_SHOW            5
#define Win_SW_MINIMIZE        6
#define Win_SW_SHOWMINNOACTIVE 7
#define Win_SW_SHOWNA          8
#define Win_SW_RESTORE         9
#define Win_SW_SHOWDEFAULT     10
#define Win_SW_FORCEMINIMIZE   11
#define Win_SW_MAX             11

#define Win_D2DERR_RECREATE_TARGET ((Win_HRESULT)0x8899000C)

#define Win_FAILED(hr) (((Win_HRESULT)(hr)) < 0)

#define Win_S_OK    ((Win_HRESULT)0)
#define Win_S_FALSE ((Win_HRESULT)1)

#define Win_LOWORD(x) ((uint16_t)(((uint64_t)(x)) & 0xffff))
#define Win_HIWORD(x) ((uint16_t)((((uint64_t)(x)) >> 16) & 0xffff))

DECLARE_INTERFACE_BASE(Win_IUnknown, 0x0000000000000000, 0xC000000000000046);
struct {
  Win_HRESULT(COMCALL *QueryInterface)(Win_IUnknown *self, Uuid *iid, void **obj);
  uint32_t(COMCALL *AddRef)(Win_IUnknown *self);
  uint32_t(COMCALL *Release)(Win_IUnknown *self);
};
DECLARE_INTERFACE_END;

static Win_HRESULT com_query_interface(void *self, Uuid *iid, void **obj) {
  if (self) {
    Win_IUnknown *unknwn = (Win_IUnknown *)self;
    return unknwn->vtable->QueryInterface(unknwn, iid, obj);
  }
  return Win_S_FALSE;
}

static uint32_t com_query_add_ref(void *self) {
  if (self) {
    Win_IUnknown *unknwn = (Win_IUnknown *)self;
    return unknwn->vtable->AddRef(unknwn);
  }
  return 0;
}

static uint32_t com_release(void **self) {
  if (*self) {
    Win_IUnknown *unknwn = (Win_IUnknown *)*self;
    uint32_t count       = unknwn->vtable->Release(unknwn);
    if (count == 0) {
      *self = NULL;
    }
    return count;
  }
  return 0;
}

int InitWinAPI(Win_HINSTANCE *instance, Win_WCHAR **command_line, uint32_t *show_command);

#endif