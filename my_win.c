#define GLOBAL_EXTERN_DEFINE
#include "my_win.h"

#include "my_d2d1.h"
#include "my_dwrite.h"

__declspec(dllimport) Win_HMODULE __stdcall LoadLibraryW(const Win_WCHAR *lpLibFileName);
__declspec(dllimport) int32_t __stdcall FreeLibrary(Win_HMODULE hLibModule);
__declspec(dllimport) Win_FARPROC __stdcall GetProcAddress(Win_HMODULE hModule, const char *lpProcName);
__declspec(dllimport) void __stdcall ExitProcess(uint32_t uExitCode);

#define CORY_FUNC_PTR(a, b) ((a) = (void *)(b))

#define LOAD_DLL(a, b)                                                                                                                                         \
  Win_HMODULE a = Win_LoadLibraryW(L##b);                                                                                                                      \
  if ((a) == NULL) {                                                                                                                                           \
    return 0;                                                                                                                                                  \
  }

#define CORY_FUNC_PTR2(a, b, c)                                                                                                                                \
  do {                                                                                                                                                         \
    b = (void *)Win_GetProcAddress((a), #c);                                                                                                                   \
    if (b == NULL) {                                                                                                                                           \
      return 0;                                                                                                                                                \
    }                                                                                                                                                          \
  } while (0)

int InitWinAPI(Win_HINSTANCE *instance, Win_WCHAR **command_line, uint32_t *show_command) {

  CORY_FUNC_PTR(Win_LoadLibraryW, LoadLibraryW);
  CORY_FUNC_PTR(Win_FreeLibrary, FreeLibrary);
  CORY_FUNC_PTR(Win_GetProcAddress, GetProcAddress);
  CORY_FUNC_PTR(Win_ExitProcess, ExitProcess);

  LOAD_DLL(kernel32, "Kernel32.dll");
  CORY_FUNC_PTR2(kernel32, Win_GetModuleHandleW, GetModuleHandleW);
  CORY_FUNC_PTR2(kernel32, Win_GetStartupInfoW, GetStartupInfoW);
  CORY_FUNC_PTR2(kernel32, Win_GetCommandLineW, GetCommandLineW);

  if (instance) {
    *instance = Win_GetModuleHandleW(NULL);
  }
  if (command_line) {
    *command_line = Win_GetCommandLineW();
  }
  if (show_command) {
    Win_STARTUPINFOW si = {0};
    si.cb               = sizeof(si);
    Win_GetStartupInfoW(&si);
    if (si.dwFlags & Win_STARTF_USESHOWWINDOW) {
      *show_command = si.wShowWindow;
    } else {
      *show_command = Win_SW_SHOWDEFAULT;
    }
  }

  LOAD_DLL(user32, "User32.dll");
  CORY_FUNC_PTR2(user32, Win_GetMessageW, GetMessageW);
  CORY_FUNC_PTR2(user32, Win_TranslateMessage, TranslateMessage);
  CORY_FUNC_PTR2(user32, Win_DispatchMessageW, DispatchMessageW);
  CORY_FUNC_PTR2(user32, Win_GetClientRect, GetClientRect);
  CORY_FUNC_PTR2(user32, Win_LoadCursorW, LoadCursorW);
  CORY_FUNC_PTR2(user32, Win_PostQuitMessage, PostQuitMessage);
  CORY_FUNC_PTR2(user32, Win_DefWindowProcW, DefWindowProcW);
  CORY_FUNC_PTR2(user32, Win_RegisterClassW, RegisterClassW);
  CORY_FUNC_PTR2(user32, Win_CreateWindowExW, CreateWindowExW);
  CORY_FUNC_PTR2(user32, Win_ShowWindow, ShowWindow);
  CORY_FUNC_PTR2(user32, Win_BeginPaint, BeginPaint);
  CORY_FUNC_PTR2(user32, Win_EndPaint, EndPaint);
  CORY_FUNC_PTR2(user32, Win_GetClientRect, GetClientRect);
  CORY_FUNC_PTR2(user32, Win_PostQuitMessage, PostQuitMessage);
  CORY_FUNC_PTR2(user32, Win_InvalidateRect, InvalidateRect);

  LOAD_DLL(ole32, "Ole32.dll");
  CORY_FUNC_PTR2(ole32, Win_CoInitializeEx, CoInitializeEx);
  CORY_FUNC_PTR2(ole32, Win_CoUninitialize, CoUninitialize);

  LOAD_DLL(d2d1, "D2d1.dll");
  CORY_FUNC_PTR2(d2d1, D2D1CreateFactory, D2D1CreateFactory);

  LOAD_DLL(dwrite, "Dwrite.dll");
  CORY_FUNC_PTR2(dwrite, DWriteCreateFactory, DWriteCreateFactory);

  return 1;
}

int __main() {
  return 0;
}
