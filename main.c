#include "com.h"
#include "my_d2d1.h"
#include "my_dwrite.h"
#include "my_win.h"
#include <stdint.h>

#include <stdio.h>

ID2D1Factory *g_d2_factory;
ID2D1HwndRenderTarget *g_target;
ID2D1SolidColorBrush *g_brush;
ID2D1StrokeStyle *g_stroke_style;

IDWriteFactory *g_dw_factory;
IDWriteTextFormat *g_text_format;

static void zero_mem(void *mem, size_t count) {
  char *buf = mem;
  for (int i = 0; i < count; i++) {
    buf[i] = 0;
  }
}

static void ReleaseRenderTarget(void) {
  com_release((void **)&g_brush);
  com_release((void **)&g_target);
}

static Win_HRESULT CreateRenderTarget(Win_HWND hwnd) {
  Win_HRESULT hr;
  Win_RECT rc;

  D2D1_RENDER_TARGET_PROPERTIES rt_props;
  D2D1_HWND_RENDER_TARGET_PROPERTIES hwnd_props;
  D2D1_COLOR_F color;

  ID2D1RenderTarget *rt;

  if (g_target) {
    return Win_S_OK;
  }

  Win_GetClientRect(hwnd, &rc);

  zero_mem(&rt_props, sizeof(rt_props));
  rt_props.type                  = D2D1_RENDER_TARGET_TYPE_DEFAULT;
  rt_props.pixelFormat.format    = DXGI_FORMAT_UNKNOWN;
  rt_props.pixelFormat.alphaMode = D2D1_ALPHA_MODE_UNKNOWN;
  rt_props.dpiX                  = 0.0f;
  rt_props.dpiY                  = 0.0f;
  rt_props.usage                 = D2D1_RENDER_TARGET_USAGE_NONE;
  rt_props.minLevel              = D2D1_FEATURE_LEVEL_DEFAULT;

  zero_mem(&hwnd_props, sizeof(hwnd_props));
  hwnd_props.hwnd             = hwnd;
  hwnd_props.pixelSize.width  = (uint32_t)(rc.right - rc.left);
  hwnd_props.pixelSize.height = (uint32_t)(rc.bottom - rc.top);
  hwnd_props.presentOptions   = D2D1_PRESENT_OPTIONS_NONE;

  hr = g_d2_factory->vtable->CreateHwndRenderTarget(g_d2_factory, &rt_props, &hwnd_props, &g_target);

  if (Win_FAILED(hr)) {
    return hr;
  }
  D2D1_STROKE_STYLE_PROPERTIES stroke_style_properties;
  stroke_style_properties.startCap   = D2D1_CAP_STYLE_ROUND;
  stroke_style_properties.endCap     = D2D1_CAP_STYLE_ROUND;
  stroke_style_properties.dashCap    = D2D1_CAP_STYLE_ROUND;
  stroke_style_properties.lineJoin   = D2D1_LINE_JOIN_ROUND;
  stroke_style_properties.miterLimit = 1.0f;
  stroke_style_properties.dashStyle  = D2D1_DASH_STYLE_SOLID;
  stroke_style_properties.dashOffset = 0.0f;

  hr = g_d2_factory->vtable->CreateStrokeStyle(g_d2_factory, &stroke_style_properties, NULL, 0, &g_stroke_style);
  if (Win_FAILED(hr)) {
    return hr;
  }

  rt = (ID2D1RenderTarget *)g_target;

  color.r = 0.39f;
  color.g = 0.58f;
  color.b = 0.93f;
  color.a = 1.0f;

  hr = rt->vtable->CreateSolidColorBrush(rt, &color, NULL, &g_brush);

  return hr;
}

static void Render(Win_HWND hwnd) {
  Win_HRESULT hr;

  D2D1_COLOR_F background;
  D2D1_RECT_F rect;

  ID2D1RenderTarget *rt;

  if (Win_FAILED(CreateRenderTarget(hwnd))) {
    return;
  }

  rt = (ID2D1RenderTarget *)g_target;

  background.r = 1.0f;
  background.g = 1.0f;
  background.b = 1.0f;
  background.a = 1.0f;

  rect.left   = 50.0f;
  rect.top    = 50.0f;
  rect.right  = 250.0f;
  rect.bottom = 150.0f;

  D2D1_POINT_2F start, end;
  start.x = 60;
  start.y = 200;
  end.x   = 400;
  end.y   = 300;

  rt->vtable->BeginDraw(rt);
  rt->vtable->Clear(rt, &background);
  rt->vtable->DrawLine(rt, start, end, (ID2D1Brush *)g_brush, 5, g_stroke_style);
  rt->vtable->FillRectangle(rt, &rect, (ID2D1Brush *)g_brush);

  static const Win_WCHAR str[] = L"Hello, DirectWrite! こんにちは";
  D2D1_RECT_F rect2            = {70, 350, 800, 600};
  rt->vtable->DrawText(rt, str, (sizeof(str) / sizeof(str[0]) - 1), g_text_format, &rect2, (ID2D1Brush *)g_brush, D2D1_DRAW_TEXT_OPTIONS_NONE,
                       DWRITE_MEASURING_MODE_NATURAL);
  hr = rt->vtable->EndDraw(rt, NULL, NULL);

  if (hr == Win_D2DERR_RECREATE_TARGET) {
    ReleaseRenderTarget();
  }
}

static Win_HRESULT init_d2d_dwrite() {
  Win_HRESULT hr;
  hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &INTERFACE_UUID(ID2D1Factory), NULL, (void **)&g_d2_factory);
  if (Win_FAILED(hr)) {
    return hr;
  }
  hr = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, &INTERFACE_UUID(IDWriteFactory), (void **)&g_dw_factory);

  if (Win_FAILED(hr)) {
    return hr;
  }

  hr = g_dw_factory->vtable->CreateTextFormat(g_dw_factory, L"Meiryo", NULL, DWRITE_FONT_WEIGHT_NORMAL, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL,
                                              32.0f, L"ja-jp", &g_text_format);
  if (Win_FAILED(hr)) {
    return hr;
  }
  return hr;
}

static Win_LRESULT __stdcall WndProc(Win_HWND hwnd, uint32_t msg, Win_WPARAM w_param, Win_LPARAM l_param) {
  switch (msg) {
  case Win_WM_PAINT:
    Win_PAINTSTRUCT ps;
    Win_BeginPaint(hwnd, &ps);
    Render(hwnd);
    Win_EndPaint(hwnd, &ps);
    return 0;

  case Win_WM_SIZE:
    if (g_target) {
      D2D1_SIZE_U size;
      size.width  = Win_LOWORD(l_param);
      size.height = Win_HIWORD(l_param);
      g_target->vtable->Resize(g_target, &size);
    }
    return 0;
  case Win_WM_DESTROY:
    ReleaseRenderTarget();
    com_release((void **)&g_d2_factory);
    Win_PostQuitMessage(0);
    return 0;
  default:
    break;
  }
  return Win_DefWindowProcW(hwnd, msg, w_param, l_param);
}

const Win_WCHAR class_name[] = L"Direct2DWindow";

int main() {
  Win_HINSTANCE instance;
  uint32_t show_command;
  if (!InitWinAPI(&instance, NULL, &show_command)) {
    return 1;
  }

  if (init_d2d_dwrite()) {
    return 1;
  }

  Win_WNDCLASSW wc = {0};

  wc.lpfnWndProc   = WndProc;
  wc.hInstance     = instance;
  wc.lpszClassName = class_name;
  wc.hCursor       = Win_LoadCursorW(NULL, Win_IDC_ARROW);

  if (!Win_RegisterClassW(&wc)) {
    return 1;
  }

  Win_HWND hwnd =
      Win_CreateWindowExW(0, class_name, L"title", Win_WS_OVERLAPPEDWINDOW, Win_CW_USEDEFAULT, Win_CW_USEDEFAULT, 800, 600, NULL, NULL, instance, NULL);
  if (!hwnd) {
    return 1;
  }

  Win_ShowWindow(hwnd, show_command);

  Win_MSG msg;
  while (Win_GetMessageW(&msg, NULL, 0, 0) > 0) {
    Win_TranslateMessage(&msg);
    Win_DispatchMessageW(&msg);
  }

  return 0;
}