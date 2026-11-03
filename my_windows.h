
#include <stddef.h>
#include <stdint.h>

#pragma once

#define CALLBACK __stdcall
#define STDMETHODCALLTYPE __stdcall
#define WINAPI __stdcall
#define DECLSPEC_IMPORT __attribute__((dllimport))

typedef char *LPSTR, CHAR;
typedef const char *LPCSTR;
typedef uint8_t BYTE, *LPBYTE;
typedef wchar_t *LPWSTR, *BSTR;
typedef const wchar_t *LPCWSTR, *PCWSTR;
typedef int16_t SHORT;
typedef uint16_t ATOM, WORD, VARIANT_BOOL, USHORT;
typedef int32_t HRESULT, WINBOOL, BOOL, LONG, INT, SCODE;
typedef uint32_t UINT, ULONG, DWORD, *LPDWORD, REGSAM, UINT32;
typedef int64_t LPARAM, LRESULT, INT_PTR, LONGLONG;
typedef uint64_t WPARAM, ULONGLONG, UINT64, ULONG_PTR;
typedef void VOID, *LPVOID, *PVOID;

typedef struct {
  int _;
} *HWND;
typedef struct {
  int _;
} *HINSTANCE, *HMODULE;
typedef struct {
  int _;
} *HICON;
typedef struct {
  int _;
} *HCURSOR;
typedef struct {
  int _;
} *HBRUSH;
typedef struct {
  int _;
} *HMENU;
typedef struct {
  int _;
} *HKEY, **PHKEY;
typedef struct {
  int32_t left;
  int32_t top;
  int32_t right;
  int32_t bottom;
} RECT, *LPRECT;

#define E_NOINTERFACE (0x80004002)
#define E_POINTER (0x80004003)
#define E_FAIL (0x80004005)
#define S_OK (0)

#define ERROR_SUCCESS (0)
#define INVALID_FILE_ATTRIBUTES (-1)

#define WM_NULL (0)
#define WM_CREATE (1)
#define WM_DESTROY (2)
#define WM_MOVE (3)
#define WM_SIZE (5)
#define WM_ACTIVATE (6)

#define WS_OVERLAPPED (0x00000000)
#define WS_POPUP (0x80000000)
#define WS_CHILD (0x40000000)
#define WS_MINIMIZE (0x20000000)
#define WS_VISIBLE (0x10000000)
#define WS_DISABLED (0x08000000)
#define WS_CLIPSIBLINGS (0x04000000)
#define WS_CLIPCHILDREN (0x02000000)
#define WS_MAXIMIZE (0x01000000)
#define WS_BORDER (0x00800000)
#define WS_DLGFRAME (0x00400000)
#define WS_VSCROLL (0x00200000)
#define WS_HSCROLL (0x00100000)
#define WS_SYSMENU (0x00080000)
#define WS_THICKFRAME (0x00040000)
#define WS_GROUP (0x00020000)
#define WS_TABSTOP (0x00010000)
#define WS_MINIMIZEBOX (0x00020000)
#define WS_MAXIMIZEBOX (0x00010000)
#define WS_CAPTION (WS_BORDER | WS_DLGFRAME)
#define WS_TILED (WS_OVERLAPPED)
#define WS_ICONIC (WS_MINIMIZE)
#define WS_SIZEBOX (WS_THICKFRAME)
#define WS_OVERLAPPEDWINDOW                                                    \
  (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX |  \
   WS_MAXIMIZEBOX)
#define WS_TILEDWINDOW (WS_OVERLAPPEDWINDOW)
#define WS_POPUPWINDOW (WS_POPUP | WS_BORDER | WS_SYSMENU)
#define WS_CHILDWINDOW (WS_CHILD)

#define MAX_PATH (260)

#define HKEY_CLASSES_ROOT (0x80000000)
#define HKEY_CURRENT_USER (0x80000001)
#define HKEY_LOCAL_MACHINE (0x80000002)
#define HKEY_USERS (0x80000003)

#define DELETE (0x00010000)
#define READ_CONTROL (0x00020000)
#define WRITE_DAC (0x00040000)
#define WRITE_OWNER (0x00080000)
#define SYNCHRONIZE (0x00100000)

#define STANDARD_RIGHTS_READ (READ_CONTROL)
#define STANDARD_RIGHTS_WRITE (READ_CONTROL)
#define STANDARD_RIGHTS_EXECUTE (READ_CONTROL)

#define STANDARD_RIGHTS_ALL (0x001F0000)

#define KEY_QUERY_VALUE (0x0001)
#define KEY_SET_VALUE (0x0002)
#define KEY_CREATE_SUB_KEY (0x0004)
#define KEY_ENUMERATE_SUB_KEYS (0x0008)
#define KEY_NOTIFY (0x0010)
#define KEY_CREATE_LINK (0x0020)
#define KEY_WOW64_64KEY (0x0100)
#define KEY_WOW64_32KEY (0x0200)
#define KEY_WOW64_RES (0x0300)

#define KEY_READ                                                               \
  ((STANDARD_RIGHTS_READ | KEY_QUERY_VALUE | KEY_ENUMERATE_SUB_KEYS |          \
    KEY_NOTIFY) &                                                              \
   (~SYNCHRONIZE))
#define KEY_WRITE                                                              \
  ((STANDARD_RIGHTS_WRITE | KEY_SET_VALUE | KEY_CREATE_SUB_KEY) &              \
   (~SYNCHRONIZE))
#define KEY_EXECUTE ((KEY_READ) & (~SYNCHRONIZE))
#define KEY_ALL_ACCESS                                                         \
  ((STANDARD_RIGHTS_ALL | KEY_QUERY_VALUE | KEY_SET_VALUE |                    \
    KEY_CREATE_SUB_KEY | KEY_ENUMERATE_SUB_KEYS | KEY_NOTIFY |                 \
    KEY_CREATE_LINK) &                                                         \
   (~SYNCHRONIZE))

#define CW_USEDEFAULT ((int)0x80000000)

#define COINIT_APARTMENTTHREADED (2)
#define COINIT_MULTITHREADED (0)
#define COINIT_DISABLE_OLE1DDE (4)
#define COINIT_SPEED_OVER_MEMORY (8)

typedef LRESULT(CALLBACK *WNDPROC)(HWND, UINT, WPARAM, LPARAM);

typedef struct WNDCLASSW {
  UINT style;
  WNDPROC lpfnWndProc;
  int32_t cbClsExtra;
  int32_t cbWndExtra;
  HINSTANCE hInstance;
  HICON hIcon;
  HCURSOR hCursor;
  HBRUSH hbrBackground;
  LPCWSTR lpszMenuName;
  LPCWSTR lpszClassName;
} WNDCLASSW;

typedef struct POINT {
  int32_t x;
  int32_t y;
} POINT;

typedef struct MSG {
  HWND hwnd;
  UINT message;
  WPARAM wParam;
  LPARAM lParam;
  DWORD time;
  POINT pt;
} MSG, *LPMSG;

DECLSPEC_IMPORT VOID WINAPI PostQuitMessage(int32_t nExitCode);

DECLSPEC_IMPORT LRESULT WINAPI DefWindowProcW(HWND hWnd, UINT Msg,
                                              WPARAM wParam, LPARAM lParam);
DECLSPEC_IMPORT HRESULT WINAPI CoInitializeEx(LPVOID pvReserved,
                                              DWORD dwCoInit);
DECLSPEC_IMPORT ATOM WINAPI RegisterClassW(const WNDCLASSW *lpWndClass);

DECLSPEC_IMPORT HWND WINAPI CreateWindowExW(
    DWORD dwExStyle, LPCWSTR lpClassName, LPCWSTR lpWindowName, DWORD dwStyle,
    int32_t X, int32_t Y, int32_t nWidth, int32_t nHeight, HWND hWndParent,
    HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam);

DECLSPEC_IMPORT BOOL WINAPI ShowWindow(HWND hWnd, int32_t nCmdShow);

DECLSPEC_IMPORT HMODULE WINAPI LoadLibraryW(LPCWSTR lpLibFileName);
DECLSPEC_IMPORT BOOL WINAPI FreeLibrary(HMODULE hLibModule);
typedef INT_PTR(WINAPI *FARPROC)();
DECLSPEC_IMPORT FARPROC WINAPI GetProcAddress(HMODULE hModule,
                                              LPCSTR lpProcName);
DECLSPEC_IMPORT BOOL WINAPI GetMessageW(LPMSG lpMsg, HWND hWnd,
                                         UINT wMsgFilterMin, UINT wMsgFilterMax);

DECLSPEC_IMPORT BOOL WINAPI TranslateMessage(const MSG *lpMsg);
DECLSPEC_IMPORT LRESULT WINAPI DispatchMessageW(const MSG *lpMsg);
DECLSPEC_IMPORT void WINAPI CoUninitialize(void);
DECLSPEC_IMPORT BOOL WINAPI GetClientRect(HWND hWnd, LPRECT lpRect);

DECLSPEC_IMPORT LONG WINAPI RegOpenKeyExW(HKEY hKey, LPCWSTR lpSubKey,
                                          DWORD ulOptions, REGSAM samDesired,
                                          PHKEY phkResult);

DECLSPEC_IMPORT LONG WINAPI RegQueryValueExW(HKEY hKey, LPCWSTR lpValueName,
                                             LPDWORD lpReserved, LPDWORD lpType,
                                             LPBYTE lpData, LPDWORD lpcbData);

DECLSPEC_IMPORT LONG WINAPI RegCloseKey(HKEY hKey);
DECLSPEC_IMPORT DWORD WINAPI GetFileAttributesW(LPCWSTR lpFileName);
