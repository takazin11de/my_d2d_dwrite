#ifndef MY_D2D1_H
#define MY_D2D1_H

#include "com.h"
#include "my_dcommon.h"
#include "my_win.h"

#include <stddef.h>
#include <stdint.h>
///////////////////////////////////////////////
typedef uint32_t D2D1_FACTORY_TYPE;
enum {
  D2D1_FACTORY_TYPE_SINGLE_THREADED = 0,
  D2D1_FACTORY_TYPE_MULTI_THREADED  = 1,
  D2D1_FACTORY_TYPE_FORCE_DWORD     = 0xffffffff,
};

typedef uint32_t D2D1_GEOMETRY_RELATION;
enum {
  D2D1_GEOMETRY_RELATION_UNKNOWN      = 0,
  D2D1_GEOMETRY_RELATION_DISJOINT     = 1,
  D2D1_GEOMETRY_RELATION_IS_CONTAINED = 2,
  D2D1_GEOMETRY_RELATION_CONTAINS     = 3,
  D2D1_GEOMETRY_RELATION_OVERLAP      = 4,
  D2D1_GEOMETRY_RELATION_FORCE_DWORD  = 0xffffffff,
};

typedef uint32_t D2D1_GEOMETRY_SIMPLIFICATION_OPTION;
enum {
  D2D1_GEOMETRY_SIMPLIFICATION_OPTION_CUBICS_AND_LINES = 0,
  D2D1_GEOMETRY_SIMPLIFICATION_OPTION_LINES            = 1,
  D2D1_GEOMETRY_SIMPLIFICATION_OPTION_FORCE_DWORD      = 0xffffffff,
};

typedef uint32_t D2D1_FILL_MODE;
enum {
  D2D1_FILL_MODE_ALTERNATE   = 0,
  D2D1_FILL_MODE_WINDING     = 1,
  D2D1_FILL_MODE_FORCE_DWORD = 0xffffffff,
};

typedef uint32_t D2D1_RENDER_TARGET_TYPE;
enum {
  D2D1_RENDER_TARGET_TYPE_DEFAULT     = 0,
  D2D1_RENDER_TARGET_TYPE_SOFTWARE    = 1,
  D2D1_RENDER_TARGET_TYPE_HARDWARE    = 2,
  D2D1_RENDER_TARGET_TYPE_FORCE_DWORD = 0xffffffff,
};

typedef uint32_t D2D1_RENDER_TARGET_USAGE;
enum {
  D2D1_RENDER_TARGET_USAGE_NONE                  = 0x00000000,
  D2D1_RENDER_TARGET_USAGE_FORCE_BITMAP_REMOTING = 0x00000001,
  D2D1_RENDER_TARGET_USAGE_GDI_COMPATIBLE        = 0x00000002,
  D2D1_RENDER_TARGET_USAGE_FORCE_DWORD           = 0xffffffff,
};

typedef uint32_t D3D_FEATURE_LEVEL;
enum {
  D3D_FEATURE_LEVEL_1_0_GENERIC = 0x100,
  D3D_FEATURE_LEVEL_1_0_CORE    = 0x1000,
  D3D_FEATURE_LEVEL_9_1         = 0x9100,
  D3D_FEATURE_LEVEL_9_2         = 0x9200,
  D3D_FEATURE_LEVEL_9_3         = 0x9300,
  D3D_FEATURE_LEVEL_10_0        = 0xa000,
  D3D_FEATURE_LEVEL_10_1        = 0xa100,
  D3D_FEATURE_LEVEL_11_0        = 0xb000,
  D3D_FEATURE_LEVEL_11_1        = 0xb100,
  D3D_FEATURE_LEVEL_12_0        = 0xc000,
  D3D_FEATURE_LEVEL_12_1        = 0xc100,
  D3D_FEATURE_LEVEL_12_2        = 0xc200,
};

typedef uint32_t D2D1_FEATURE_LEVEL;
enum {
  D2D1_FEATURE_LEVEL_DEFAULT     = 0,
  D2D1_FEATURE_LEVEL_9           = D3D_FEATURE_LEVEL_9_1,
  D2D1_FEATURE_LEVEL_10          = D3D_FEATURE_LEVEL_10_0,
  D2D1_FEATURE_LEVEL_FORCE_DWORD = 0xffffffff,
};

typedef uint32_t DXGI_FORMAT;
enum {
  DXGI_FORMAT_UNKNOWN                                 = 0,
  DXGI_FORMAT_R32G32B32A32_TYPELESS                   = 1,
  DXGI_FORMAT_R32G32B32A32_FLOAT                      = 2,
  DXGI_FORMAT_R32G32B32A32_UINT                       = 3,
  DXGI_FORMAT_R32G32B32A32_SINT                       = 4,
  DXGI_FORMAT_R32G32B32_TYPELESS                      = 5,
  DXGI_FORMAT_R32G32B32_FLOAT                         = 6,
  DXGI_FORMAT_R32G32B32_UINT                          = 7,
  DXGI_FORMAT_R32G32B32_SINT                          = 8,
  DXGI_FORMAT_R16G16B16A16_TYPELESS                   = 9,
  DXGI_FORMAT_R16G16B16A16_FLOAT                      = 10,
  DXGI_FORMAT_R16G16B16A16_UNORM                      = 11,
  DXGI_FORMAT_R16G16B16A16_UINT                       = 12,
  DXGI_FORMAT_R16G16B16A16_SNORM                      = 13,
  DXGI_FORMAT_R16G16B16A16_SINT                       = 14,
  DXGI_FORMAT_R32G32_TYPELESS                         = 15,
  DXGI_FORMAT_R32G32_FLOAT                            = 16,
  DXGI_FORMAT_R32G32_UINT                             = 17,
  DXGI_FORMAT_R32G32_SINT                             = 18,
  DXGI_FORMAT_R32G8X24_TYPELESS                       = 19,
  DXGI_FORMAT_D32_FLOAT_S8X24_UINT                    = 20,
  DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS                = 21,
  DXGI_FORMAT_X32_TYPELESS_G8X24_UINT                 = 22,
  DXGI_FORMAT_R10G10B10A2_TYPELESS                    = 23,
  DXGI_FORMAT_R10G10B10A2_UNORM                       = 24,
  DXGI_FORMAT_R10G10B10A2_UINT                        = 25,
  DXGI_FORMAT_R11G11B10_FLOAT                         = 26,
  DXGI_FORMAT_R8G8B8A8_TYPELESS                       = 27,
  DXGI_FORMAT_R8G8B8A8_UNORM                          = 28,
  DXGI_FORMAT_R8G8B8A8_UNORM_SRGB                     = 29,
  DXGI_FORMAT_R8G8B8A8_UINT                           = 30,
  DXGI_FORMAT_R8G8B8A8_SNORM                          = 31,
  DXGI_FORMAT_R8G8B8A8_SINT                           = 32,
  DXGI_FORMAT_R16G16_TYPELESS                         = 33,
  DXGI_FORMAT_R16G16_FLOAT                            = 34,
  DXGI_FORMAT_R16G16_UNORM                            = 35,
  DXGI_FORMAT_R16G16_UINT                             = 36,
  DXGI_FORMAT_R16G16_SNORM                            = 37,
  DXGI_FORMAT_R16G16_SINT                             = 38,
  DXGI_FORMAT_R32_TYPELESS                            = 39,
  DXGI_FORMAT_D32_FLOAT                               = 40,
  DXGI_FORMAT_R32_FLOAT                               = 41,
  DXGI_FORMAT_R32_UINT                                = 42,
  DXGI_FORMAT_R32_SINT                                = 43,
  DXGI_FORMAT_R24G8_TYPELESS                          = 44,
  DXGI_FORMAT_D24_UNORM_S8_UINT                       = 45,
  DXGI_FORMAT_R24_UNORM_X8_TYPELESS                   = 46,
  DXGI_FORMAT_X24_TYPELESS_G8_UINT                    = 47,
  DXGI_FORMAT_R8G8_TYPELESS                           = 48,
  DXGI_FORMAT_R8G8_UNORM                              = 49,
  DXGI_FORMAT_R8G8_UINT                               = 50,
  DXGI_FORMAT_R8G8_SNORM                              = 51,
  DXGI_FORMAT_R8G8_SINT                               = 52,
  DXGI_FORMAT_R16_TYPELESS                            = 53,
  DXGI_FORMAT_R16_FLOAT                               = 54,
  DXGI_FORMAT_D16_UNORM                               = 55,
  DXGI_FORMAT_R16_UNORM                               = 56,
  DXGI_FORMAT_R16_UINT                                = 57,
  DXGI_FORMAT_R16_SNORM                               = 58,
  DXGI_FORMAT_R16_SINT                                = 59,
  DXGI_FORMAT_R8_TYPELESS                             = 60,
  DXGI_FORMAT_R8_UNORM                                = 61,
  DXGI_FORMAT_R8_UINT                                 = 62,
  DXGI_FORMAT_R8_SNORM                                = 63,
  DXGI_FORMAT_R8_SINT                                 = 64,
  DXGI_FORMAT_A8_UNORM                                = 65,
  DXGI_FORMAT_R1_UNORM                                = 66,
  DXGI_FORMAT_R9G9B9E5_SHAREDEXP                      = 67,
  DXGI_FORMAT_R8G8_B8G8_UNORM                         = 68,
  DXGI_FORMAT_G8R8_G8B8_UNORM                         = 69,
  DXGI_FORMAT_BC1_TYPELESS                            = 70,
  DXGI_FORMAT_BC1_UNORM                               = 71,
  DXGI_FORMAT_BC1_UNORM_SRGB                          = 72,
  DXGI_FORMAT_BC2_TYPELESS                            = 73,
  DXGI_FORMAT_BC2_UNORM                               = 74,
  DXGI_FORMAT_BC2_UNORM_SRGB                          = 75,
  DXGI_FORMAT_BC3_TYPELESS                            = 76,
  DXGI_FORMAT_BC3_UNORM                               = 77,
  DXGI_FORMAT_BC3_UNORM_SRGB                          = 78,
  DXGI_FORMAT_BC4_TYPELESS                            = 79,
  DXGI_FORMAT_BC4_UNORM                               = 80,
  DXGI_FORMAT_BC4_SNORM                               = 81,
  DXGI_FORMAT_BC5_TYPELESS                            = 82,
  DXGI_FORMAT_BC5_UNORM                               = 83,
  DXGI_FORMAT_BC5_SNORM                               = 84,
  DXGI_FORMAT_B5G6R5_UNORM                            = 85,
  DXGI_FORMAT_B5G5R5A1_UNORM                          = 86,
  DXGI_FORMAT_B8G8R8A8_UNORM                          = 87,
  DXGI_FORMAT_B8G8R8X8_UNORM                          = 88,
  DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM              = 89,
  DXGI_FORMAT_B8G8R8A8_TYPELESS                       = 90,
  DXGI_FORMAT_B8G8R8A8_UNORM_SRGB                     = 91,
  DXGI_FORMAT_B8G8R8X8_TYPELESS                       = 92,
  DXGI_FORMAT_B8G8R8X8_UNORM_SRGB                     = 93,
  DXGI_FORMAT_BC6H_TYPELESS                           = 94,
  DXGI_FORMAT_BC6H_UF16                               = 95,
  DXGI_FORMAT_BC6H_SF16                               = 96,
  DXGI_FORMAT_BC7_TYPELESS                            = 97,
  DXGI_FORMAT_BC7_UNORM                               = 98,
  DXGI_FORMAT_BC7_UNORM_SRGB                          = 99,
  DXGI_FORMAT_AYUV                                    = 100,
  DXGI_FORMAT_Y410                                    = 101,
  DXGI_FORMAT_Y416                                    = 102,
  DXGI_FORMAT_NV12                                    = 103,
  DXGI_FORMAT_P010                                    = 104,
  DXGI_FORMAT_P016                                    = 105,
  DXGI_FORMAT_420_OPAQUE                              = 106,
  DXGI_FORMAT_YUY2                                    = 107,
  DXGI_FORMAT_Y210                                    = 108,
  DXGI_FORMAT_Y216                                    = 109,
  DXGI_FORMAT_NV11                                    = 110,
  DXGI_FORMAT_AI44                                    = 111,
  DXGI_FORMAT_IA44                                    = 112,
  DXGI_FORMAT_P8                                      = 113,
  DXGI_FORMAT_A8P8                                    = 114,
  DXGI_FORMAT_B4G4R4A4_UNORM                          = 115,
  DXGI_FORMAT_P208                                    = 130,
  DXGI_FORMAT_V208                                    = 131,
  DXGI_FORMAT_V408                                    = 132,
  DXGI_FORMAT_SAMPLER_FEEDBACK_MIN_MIP_OPAQUE         = 189,
  DXGI_FORMAT_SAMPLER_FEEDBACK_MIP_REGION_USED_OPAQUE = 190,
  DXGI_FORMAT_A4B4G4R4_UNORM                          = 191,
  DXGI_FORMAT_FORCE_UINT                              = 0xffffffff,
};

typedef uint32_t D2D1_ALPHA_MODE;
enum {
  D2D1_ALPHA_MODE_UNKNOWN       = 0,
  D2D1_ALPHA_MODE_PREMULTIPLIED = 1,
  D2D1_ALPHA_MODE_STRAIGHT      = 2,
  D2D1_ALPHA_MODE_IGNORE        = 3,
  D2D1_ALPHA_MODE_FORCE_DWORD   = 0xffffffff,
};

typedef uint32_t D2D1_PRESENT_OPTIONS;
enum {
  D2D1_PRESENT_OPTIONS_NONE            = 0x00000000,
  D2D1_PRESENT_OPTIONS_RETAIN_CONTENTS = 0x00000001,
  D2D1_PRESENT_OPTIONS_IMMEDIATELY     = 0x00000002,
  D2D1_PRESENT_OPTIONS_FORCE_DWORD     = 0xffffffff,
};

typedef uint32_t D2D1_WINDOW_STATE;
enum {
  D2D1_WINDOW_STATE_NONE        = 0x0000000,
  D2D1_WINDOW_STATE_OCCLUDED    = 0x0000001,
  D2D1_WINDOW_STATE_FORCE_DWORD = 0xffffffff,
};

typedef uint32_t D2D1_EXTEND_MODE;
enum {
  D2D1_EXTEND_MODE_CLAMP       = 0,
  D2D1_EXTEND_MODE_WRAP        = 1,
  D2D1_EXTEND_MODE_MIRROR      = 2,
  D2D1_EXTEND_MODE_FORCE_DWORD = 0xffffffff,
};

enum {
  D2D1_INTERPOLATION_MODE_DEFINITION_NEAREST_NEIGHBOR    = 0,
  D2D1_INTERPOLATION_MODE_DEFINITION_LINEAR              = 1,
  D2D1_INTERPOLATION_MODE_DEFINITION_CUBIC               = 2,
  D2D1_INTERPOLATION_MODE_DEFINITION_MULTI_SAMPLE_LINEAR = 3,
  D2D1_INTERPOLATION_MODE_DEFINITION_ANISOTROPIC         = 4,
  D2D1_INTERPOLATION_MODE_DEFINITION_HIGH_QUALITY_CUBIC  = 5,
  D2D1_INTERPOLATION_MODE_DEFINITION_FANT                = 6,
  D2D1_INTERPOLATION_MODE_DEFINITION_MIPMAP_LINEAR       = 7

};
typedef uint32_t D2D1_BITMAP_INTERPOLATION_MODE;
enum {
  D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR = D2D1_INTERPOLATION_MODE_DEFINITION_NEAREST_NEIGHBOR,
  D2D1_BITMAP_INTERPOLATION_MODE_LINEAR           = D2D1_INTERPOLATION_MODE_DEFINITION_LINEAR,
  D2D1_BITMAP_INTERPOLATION_MODE_FORCE_DWORD      = 0xffffffff,
};

typedef uint32_t D2D1_GAMMA;
enum {
  D2D1_GAMMA_2_2         = 0,
  D2D1_GAMMA_1_0         = 1,
  D2D1_GAMMA_FORCE_DWORD = 0xffffffff,
};

typedef uint32_t D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS;
enum {
  D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_NONE           = 0x00000000,
  D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_GDI_COMPATIBLE = 0x00000001,
  D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_FORCE_DWORD    = 0xffffffff,
};

typedef uint32_t D2D1_OPACITY_MASK_CONTENT;
enum {
  D2D1_OPACITY_MASK_CONTENT_GRAPHICS            = 0,
  D2D1_OPACITY_MASK_CONTENT_TEXT_NATURAL        = 1,
  D2D1_OPACITY_MASK_CONTENT_TEXT_GDI_COMPATIBLE = 2,
  D2D1_OPACITY_MASK_CONTENT_FORCE_DWORD         = 0xffffffff,
};

typedef uint32_t D2D1_DRAW_TEXT_OPTIONS;
enum {
  D2D1_DRAW_TEXT_OPTIONS_NO_SNAP                       = 0x00000001,
  D2D1_DRAW_TEXT_OPTIONS_CLIP                          = 0x00000002,
  D2D1_DRAW_TEXT_OPTIONS_ENABLE_COLOR_FONT             = 0x00000004,
  D2D1_DRAW_TEXT_OPTIONS_DISABLE_COLOR_BITMAP_SNAPPING = 0x00000008,
  D2D1_DRAW_TEXT_OPTIONS_NONE                          = 0x00000000,
  D2D1_DRAW_TEXT_OPTIONS_FORCE_DWORD                   = 0xffffffff,
};

typedef uint32_t D2D1_ANTIALIAS_MODE;
enum {
  D2D1_ANTIALIAS_MODE_PER_PRIMITIVE = 0,
  D2D1_ANTIALIAS_MODE_ALIASED       = 1,
  D2D1_ANTIALIAS_MODE_FORCE_DWORD   = 0xffffffff,
};

typedef uint32_t D2D1_TEXT_ANTIALIAS_MODE;
enum {
  D2D1_TEXT_ANTIALIAS_MODE_DEFAULT     = 0,
  D2D1_TEXT_ANTIALIAS_MODE_CLEARTYPE   = 1,
  D2D1_TEXT_ANTIALIAS_MODE_GRAYSCALE   = 2,
  D2D1_TEXT_ANTIALIAS_MODE_ALIASED     = 3,
  D2D1_TEXT_ANTIALIAS_MODE_FORCE_DWORD = 0xffffffff,
};

typedef uint32_t D2D1_LAYER_OPTIONS;
enum {
  D2D1_LAYER_OPTIONS_NONE                     = 0x00000000,
  D2D1_LAYER_OPTIONS_INITIALIZE_FOR_CLEARTYPE = 0x00000001,
  D2D1_LAYER_OPTIONS_FORCE_DWORD              = 0xffffffff,
};

typedef uint32_t D2D1_SWEEP_DIRECTION;
enum {
  D2D1_SWEEP_DIRECTION_COUNTER_CLOCKWISE = 0,
  D2D1_SWEEP_DIRECTION_CLOCKWISE         = 1,
  D2D1_SWEEP_DIRECTION_FORCE_DWORD       = 0xffffffff,
};

typedef uint32_t D2D1_ARC_SIZE;
enum {
  D2D1_ARC_SIZE_SMALL       = 0,
  D2D1_ARC_SIZE_LARGE       = 1,
  D2D1_ARC_SIZE_FORCE_DWORD = 0xffffffff,
};

typedef uint32_t D2D1_PATH_SEGMENT;
enum {
  D2D1_PATH_SEGMENT_NONE                  = 0x00000000,
  D2D1_PATH_SEGMENT_FORCE_UNSTROKED       = 0x00000001,
  D2D1_PATH_SEGMENT_FORCE_ROUND_LINE_JOIN = 0x00000002,
  D2D1_PATH_SEGMENT_FORCE_DWORD           = 0xffffffff,
};

typedef uint32_t D2D1_FIGURE_BEGIN;
enum {
  D2D1_FIGURE_BEGIN_FILLED      = 0,
  D2D1_FIGURE_BEGIN_HOLLOW      = 1,
  D2D1_FIGURE_BEGIN_FORCE_DWORD = 0xffffffff,
};

typedef uint32_t D2D1_FIGURE_END;
enum {
  D2D1_FIGURE_END_OPEN        = 0,
  D2D1_FIGURE_END_CLOSED      = 1,
  D2D1_FIGURE_END_FORCE_DWORD = 0xffffffff,
};

typedef uint32_t D2D1_COMBINE_MODE;
enum {
  D2D1_COMBINE_MODE_UNION       = 0,
  D2D1_COMBINE_MODE_INTERSECT   = 1,
  D2D1_COMBINE_MODE_XOR         = 2,
  D2D1_COMBINE_MODE_EXCLUDE     = 3,
  D2D1_COMBINE_MODE_FORCE_DWORD = 0xffffffff,
};

typedef uint32_t D2D1_CAP_STYLE;
enum {
  D2D1_CAP_STYLE_FLAT        = 0,
  D2D1_CAP_STYLE_SQUARE      = 1,
  D2D1_CAP_STYLE_ROUND       = 2,
  D2D1_CAP_STYLE_TRIANGLE    = 3,
  D2D1_CAP_STYLE_FORCE_DWORD = 0xffffffff,
};

typedef uint32_t D2D1_LINE_JOIN;
enum {
  D2D1_LINE_JOIN_MITER          = 0,
  D2D1_LINE_JOIN_BEVEL          = 1,
  D2D1_LINE_JOIN_ROUND          = 2,
  D2D1_LINE_JOIN_MITER_OR_BEVEL = 3,
  D2D1_LINE_JOIN_FORCE_DWORD    = 0xffffffff,
};

typedef uint32_t D2D1_DASH_STYLE;
enum {
  D2D1_DASH_STYLE_SOLID        = 0,
  D2D1_DASH_STYLE_DASH         = 1,
  D2D1_DASH_STYLE_DOT          = 2,
  D2D1_DASH_STYLE_DASH_DOT     = 3,
  D2D1_DASH_STYLE_DASH_DOT_DOT = 4,
  D2D1_DASH_STYLE_CUSTOM       = 5,
  D2D1_DASH_STYLE_FORCE_DWORD  = 0xffffffff,
};

typedef uint32_t D2D1_DEBUG_LEVEL;
enum {
  D2D1_DEBUG_LEVEL_NONE        = 0,
  D2D1_DEBUG_LEVEL_ERROR       = 1,
  D2D1_DEBUG_LEVEL_WARNING     = 2,
  D2D1_DEBUG_LEVEL_INFORMATION = 3,
  D2D1_DEBUG_LEVEL_FORCE_DWORD = 0xffffffff,
};

///////////////////////////////////////////////

typedef uint64_t D2D1_TAG;

typedef struct {
  float left;
  float top;
  float right;
  float bottom;
} D2D1_RECT_F;

typedef struct {
  union {
    struct {
      float m11;
      float m12;
      float m21;
      float m22;
      float dx;
      float dy;
    };
    struct {
      float _11, _12;
      float _21, _22;
      float _31, _32;
    };
    float m[3][2];
  };
} D2D1_MATRIX_3X2_F;

typedef struct {
  float x;
  float y;
} D2D1_POINT_2F;

typedef struct {
  D2D1_RECT_F rect;
  float radiusX;
  float radiusY;
} D2D1_ROUNDED_RECT;

typedef struct {
  D2D1_POINT_2F point;
  float radiusX;
  float radiusY;
} D2D1_ELLIPSE;

typedef struct {
  D2D1_CAP_STYLE startCap;
  D2D1_CAP_STYLE endCap;
  D2D1_CAP_STYLE dashCap;
  D2D1_LINE_JOIN lineJoin;
  float miterLimit;
  D2D1_DASH_STYLE dashStyle;
  float dashOffset;
} D2D1_STROKE_STYLE_PROPERTIES;

typedef struct {
  D2D1_ANTIALIAS_MODE antialiasMode;
  D2D1_TEXT_ANTIALIAS_MODE textAntialiasMode;
  D2D1_TAG tag1;
  D2D1_TAG tag2;
  D2D1_MATRIX_3X2_F transform;
} D2D1_DRAWING_STATE_DESCRIPTION;

typedef struct {
  DXGI_FORMAT format;
  D2D1_ALPHA_MODE alphaMode;
} D2D1_PIXEL_FORMAT;

typedef struct {
  D2D1_RENDER_TARGET_TYPE type;
  D2D1_PIXEL_FORMAT pixelFormat;
  float dpiX;
  float dpiY;
  D2D1_RENDER_TARGET_USAGE usage;
  D2D1_FEATURE_LEVEL minLevel;
} D2D1_RENDER_TARGET_PROPERTIES;

typedef struct {
  uint32_t width;
  uint32_t height;
} D2D1_SIZE_U;

typedef struct {
  Win_HWND hwnd;
  D2D1_SIZE_U pixelSize;
  D2D1_PRESENT_OPTIONS presentOptions;
} D2D1_HWND_RENDER_TARGET_PROPERTIES;

typedef struct {
  D2D1_DEBUG_LEVEL debugLevel;
} D2D1_FACTORY_OPTIONS;

typedef struct {
  D2D1_PIXEL_FORMAT pixelFormat;
  float dpiX;
  float dpiY;
} D2D1_BITMAP_PROPERTIES;

typedef struct {
  D2D1_EXTEND_MODE extendModeX;
  D2D1_EXTEND_MODE extendModeY;
  D2D1_BITMAP_INTERPOLATION_MODE interpolationMode;
} D2D1_BITMAP_BRUSH_PROPERTIES;

typedef struct {
  float opacity;
  D2D1_MATRIX_3X2_F transform;
} D2D1_BRUSH_PROPERTIES;

typedef struct {
  float r;
  float g;
  float b;
  float a;
} D3DCOLORVALUE;

typedef D3DCOLORVALUE D2D1_COLOR_F;

typedef struct {
  float position;
  D2D1_COLOR_F color;
} D2D1_GRADIENT_STOP;

typedef struct {
  D2D1_POINT_2F startPoint;
  D2D1_POINT_2F endPoint;
} D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES;

typedef struct {
  D2D1_POINT_2F center;
  D2D1_POINT_2F gradientOriginOffset;
  float radiusX;
  float radiusY;
} D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES;

typedef struct {
  float width;
  float height;
} D2D1_SIZE_F;

typedef struct {
  D2D1_POINT_2F point1;
  D2D1_POINT_2F point2;
  D2D1_POINT_2F point3;
} D2D1_TRIANGLE;

typedef struct ID2D1Geometry ID2D1Geometry;
typedef struct ID2D1Brush ID2D1Brush;

typedef struct {
  D2D1_RECT_F contentBounds;
  ID2D1Geometry *geometricMask;
  D2D1_ANTIALIAS_MODE maskAntialiasMode;
  D2D1_MATRIX_3X2_F maskTransform;
  float opacity;
  ID2D1Brush *opacityBrush;
  D2D1_LAYER_OPTIONS layerOptions;
} D2D1_LAYER_PARAMETERS;

typedef struct {
  uint32_t Count;
  uint32_t Quality;
} DXGI_SAMPLE_DESC;

typedef struct {
  uint32_t Width;
  uint32_t Height;
  DXGI_FORMAT Format;
  DXGI_SAMPLE_DESC SampleDesc;
} DXGI_SURFACE_DESC;

typedef struct {
  int32_t Pitch;
  uint8_t *pBits;
} DXGI_MAPPED_RECT;

typedef struct {
  uint32_t x;
  uint32_t y;
} D2D1_POINT_2U;

typedef struct {
  uint32_t left;
  uint32_t top;
  uint32_t right;
  uint32_t bottom;
} D2D1_RECT_U;

typedef struct {
  D2D1_POINT_2F point1;
  D2D1_POINT_2F point2;
  D2D1_POINT_2F point3;
} D2D1_BEZIER_SEGMENT;

typedef struct {
  D2D1_POINT_2F point1;
  D2D1_POINT_2F point2;
} D2D1_QUADRATIC_BEZIER_SEGMENT;

typedef struct {
  D2D1_POINT_2F point;
  D2D1_SIZE_F size;
  float rotationAngle;
  D2D1_SWEEP_DIRECTION sweepDirection;
  D2D1_ARC_SIZE arcSize;
} D2D1_ARC_SEGMENT;

///////////////////////////////////////////////

typedef struct ID2D1Factory ID2D1Factory;

DECLARE_INTERFACE(ID2D1Resource, 0x2cd9069112e211dc, 0x9fed001143a055f9, Win_IUnknown);
struct {
  void(COMCALL *GetFactory)(ID2D1Resource *self, ID2D1Factory **factory);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(ID2D1StrokeStyle, 0x2cd9069d12e211dc, 0x9fed001143a055f9, ID2D1Resource);
struct {
  D2D1_CAP_STYLE(COMCALL *GetStartCap)(ID2D1StrokeStyle *self);
  D2D1_CAP_STYLE(COMCALL *GetEndCap)(ID2D1StrokeStyle *self);
  D2D1_CAP_STYLE(COMCALL *GetDashCap)(ID2D1StrokeStyle *self);
  float(COMCALL *GetMiterLimit)(ID2D1StrokeStyle *self);
  D2D1_LINE_JOIN(COMCALL *GetLineJoin)(ID2D1StrokeStyle *self);
  float(COMCALL *GetDashOffset)(ID2D1StrokeStyle *self);
  D2D1_DASH_STYLE(COMCALL *GetDashStyle)(ID2D1StrokeStyle *self);
  uint32_t(COMCALL *GetDashesCount)(ID2D1StrokeStyle *self);
  void(COMCALL *GetDashes)(ID2D1StrokeStyle *self, float *dashes, uint32_t dashesCount);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(ID2D1SimplifiedGeometrySink, 0x2cd9069e12e211dc, 0x9fed001143a055f9, Win_IUnknown);
struct {
  void(COMCALL *SetFillMode)(ID2D1SimplifiedGeometrySink *self, D2D1_FILL_MODE fillMode);
  void(COMCALL *SetSegmentFlags)(ID2D1SimplifiedGeometrySink *self, D2D1_PATH_SEGMENT vertexFlags);
  void(COMCALL *BeginFigure)(ID2D1SimplifiedGeometrySink *self, D2D1_POINT_2F startPoint, D2D1_FIGURE_BEGIN figureBegin);
  void(COMCALL *AddLines)(ID2D1SimplifiedGeometrySink *self, const D2D1_POINT_2F *points, uint32_t pointsCount);
  void(COMCALL *AddBeziers)(ID2D1SimplifiedGeometrySink *self, const D2D1_BEZIER_SEGMENT *beziers, uint32_t beziersCount);
  void(COMCALL *EndFigure)(ID2D1SimplifiedGeometrySink *self, D2D1_FIGURE_END figureEnd);
  Win_HRESULT(COMCALL *Close)(ID2D1SimplifiedGeometrySink *self);
};
DECLARE_INTERFACE_END;

typedef struct ID2D1TessellationSink ID2D1TessellationSink;

DECLARE_INTERFACE(ID2D1Geometry, 0x2cd906a112e211dc, 0x9fed001143a055f9, ID2D1Resource);
struct {
  Win_HRESULT(COMCALL *GetBounds)(ID2D1Geometry *self, const D2D1_MATRIX_3X2_F *worldTransform, D2D1_RECT_F *bounds);
  Win_HRESULT(COMCALL *GetWidenedBounds)(ID2D1Geometry *self, float strokeWidth, ID2D1StrokeStyle *strokeStyle, const D2D1_MATRIX_3X2_F *worldTransform,
                                         float flatteningTolerance, D2D1_RECT_F *bounds);
  Win_HRESULT(COMCALL *StrokeContainsPoint)(ID2D1Geometry *self, D2D1_POINT_2F point, float strokeWidth, ID2D1StrokeStyle *strokeStyle,
                                            const D2D1_MATRIX_3X2_F *worldTransform, float flatteningTolerance, int32_t *contains);
  Win_HRESULT(COMCALL *FillContainsPoint)(ID2D1Geometry *self, D2D1_POINT_2F point, const D2D1_MATRIX_3X2_F *worldTransform, float flatteningTolerance,
                                          int32_t *contains);
  Win_HRESULT(COMCALL *CompareWithGeometry)(ID2D1Geometry *self, ID2D1Geometry *inputGeometry, const D2D1_MATRIX_3X2_F *inputGeometryTransform,
                                            float flatteningTolerance, D2D1_GEOMETRY_RELATION *relation);
  Win_HRESULT(COMCALL *Simplify)(ID2D1Geometry *self, D2D1_GEOMETRY_SIMPLIFICATION_OPTION simplificationOption, const D2D1_MATRIX_3X2_F *worldTransform,
                                 float flatteningTolerance, ID2D1SimplifiedGeometrySink *geometrySink);
  Win_HRESULT(COMCALL *Tessellate)(ID2D1Geometry *self, const D2D1_MATRIX_3X2_F *worldTransform, float flatteningTolerance,
                                   struct ID2D1TessellationSink *tessellationSink);
  Win_HRESULT(COMCALL *CombineWithGeometry)(ID2D1Geometry *self, ID2D1Geometry *inputGeometry, D2D1_COMBINE_MODE combineMode,
                                            const D2D1_MATRIX_3X2_F *inputGeometryTransform, float flatteningTolerance,
                                            ID2D1SimplifiedGeometrySink *geometrySink);
  Win_HRESULT(COMCALL *Outline)(ID2D1Geometry *self, const D2D1_MATRIX_3X2_F *worldTransform, float flatteningTolerance,
                                ID2D1SimplifiedGeometrySink *geometrySink);
  Win_HRESULT(COMCALL *ComputeArea)(ID2D1Geometry *self, const D2D1_MATRIX_3X2_F *worldTransform, float flatteningTolerance, float *area);
  Win_HRESULT(COMCALL *ComputeLength)(ID2D1Geometry *self, const D2D1_MATRIX_3X2_F *worldTransform, float flatteningTolerance, float *length);
  Win_HRESULT(COMCALL *ComputePointAtLength)(ID2D1Geometry *self, float length, const D2D1_MATRIX_3X2_F *worldTransform, float flatteningTolerance,
                                             D2D1_POINT_2F *point, D2D1_POINT_2F *unitTangentVector);
  Win_HRESULT(COMCALL *Widen)(ID2D1Geometry *self, float strokeWidth, ID2D1StrokeStyle *strokeStyle, const D2D1_MATRIX_3X2_F *worldTransform,
                              float flatteningTolerance, ID2D1SimplifiedGeometrySink *geometrySink);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(ID2D1RectangleGeometry, 0x2cd906a212e211dc, 0x9fed001143a055f9, ID2D1Geometry);
struct {
  void(COMCALL *GetRect)(ID2D1RectangleGeometry *self, D2D1_RECT_F *rect);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(ID2D1RoundedRectangleGeometry, 0x2cd906a312e211dc, 0x9fed001143a055f9, ID2D1Geometry);
struct {
  void(COMCALL *GetRoundedRect)(ID2D1RoundedRectangleGeometry *self, D2D1_ROUNDED_RECT *roundedRect);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(ID2D1EllipseGeometry, 0x2cd906a412e211dc, 0x9fed001143a055f9, ID2D1Geometry);
struct {
  void(COMCALL *GetEllipse)(ID2D1EllipseGeometry *self, D2D1_ELLIPSE *ellipse);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(ID2D1GeometryGroup, 0x2cd906a612e211dc, 0x9fed001143a055f9, ID2D1Geometry);
struct {
  D2D1_FILL_MODE(COMCALL *GetFillMode)(ID2D1GeometryGroup *self);
  uint32_t(COMCALL *GetSourceGeometryCount)(ID2D1GeometryGroup *self);
  void(COMCALL *GetSourceGeometries)(ID2D1GeometryGroup *self, ID2D1Geometry **geometries, uint32_t geometriesCount);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(ID2D1TransformedGeometry, 0x2cd906bb12e211dc, 0x9fed001143a055f9, ID2D1Geometry);
struct {
  void(COMCALL *GetSourceGeometry)(ID2D1TransformedGeometry *self, ID2D1Geometry **sourceGeometry);
  void(COMCALL *GetTransform)(ID2D1TransformedGeometry *self, D2D1_MATRIX_3X2_F *transform);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(ID2D1GeometrySink, 0x2cd9069f12e211dc, 0x9fed001143a055f9, ID2D1SimplifiedGeometrySink);
struct {
  void(COMCALL *AddLine)(ID2D1GeometrySink *self, D2D1_POINT_2F point);
  void(COMCALL *AddBezier)(ID2D1GeometrySink *self, const D2D1_BEZIER_SEGMENT *bezier);
  void(COMCALL *AddQuadraticBezier)(ID2D1GeometrySink *self, const D2D1_QUADRATIC_BEZIER_SEGMENT *bezier);
  void(COMCALL *AddQuadraticBeziers)(ID2D1GeometrySink *self, const D2D1_QUADRATIC_BEZIER_SEGMENT *beziers, uint32_t beziersCount);
  void(COMCALL *AddArc)(ID2D1GeometrySink *self, const D2D1_ARC_SEGMENT *arc);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(ID2D1PathGeometry, 0x2cd906a512e211dc, 0x9fed001143a055f9, ID2D1Geometry);
struct {
  Win_HRESULT(COMCALL *Open)(ID2D1PathGeometry *self, ID2D1GeometrySink **geometrySink);
  Win_HRESULT(COMCALL *Stream)(ID2D1PathGeometry *self, ID2D1GeometrySink *geometrySink);
  Win_HRESULT(COMCALL *GetSegmentCount)(ID2D1PathGeometry *self, uint32_t *count);
  Win_HRESULT(COMCALL *GetFigureCount)(ID2D1PathGeometry *self, uint32_t *count);
};
DECLARE_INTERFACE_END;

typedef struct IDWriteRenderingParams IDWriteRenderingParams;

DECLARE_INTERFACE(ID2D1DrawingStateBlock, 0x28506e39ebf646a1, 0xbb47fd85565ab957, ID2D1Resource);
struct {
  void(COMCALL *GetDescription)(ID2D1DrawingStateBlock *self, D2D1_DRAWING_STATE_DESCRIPTION *stateDescription);
  void(COMCALL *SetDescription)(ID2D1DrawingStateBlock *self, const D2D1_DRAWING_STATE_DESCRIPTION *stateDescription);
  void(COMCALL *SetTextRenderingParams)(ID2D1DrawingStateBlock *self, IDWriteRenderingParams *textRenderingParams);
  void(COMCALL *GetTextRenderingParams)(ID2D1DrawingStateBlock *self, IDWriteRenderingParams **textRenderingParams);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(IWICBitmap, 0, 0, Win_IUnknown);
struct {
  int dummy;
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(ID2D1Image, 0x65019f758da2497c, 0xb32cdfa34e48ede6, ID2D1Resource);
DECLARE_INTERFACE_END;

typedef struct ID2D1RenderTarget ID2D1RenderTarget;

DECLARE_INTERFACE(ID2D1Bitmap, 0xa2296057ea424099, 0x983b539fb6505426, ID2D1Image);
struct {
  D2D1_SIZE_F(COMCALL *GetSize)(ID2D1Bitmap *self);
  D2D1_SIZE_U(COMCALL *GetPixelSize)(ID2D1Bitmap *self);
  D2D1_PIXEL_FORMAT(COMCALL *GetPixelFormat)(ID2D1Bitmap *self);
  void(COMCALL *GetDpi)(ID2D1Bitmap *self, float *dpiX, float *dpiY);
  Win_HRESULT(COMCALL *CopyFromBitmap)(ID2D1Bitmap *self, const D2D1_POINT_2U *destPoint, ID2D1Bitmap *bitmap, const D2D1_RECT_U *srcRect);
  Win_HRESULT(COMCALL *CopyFromRenderTarget)(ID2D1Bitmap *self, const D2D1_POINT_2U *destPoint, ID2D1RenderTarget *renderTarget, const D2D1_RECT_U *srcRect);
  Win_HRESULT(COMCALL *CopyFromMemory)(ID2D1Bitmap *self, const D2D1_RECT_U *dstRect, const void *srcData, uint32_t pitch);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(IWICBitmapSource, 0, 0, Win_IUnknown);
struct {
  int dummy;
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(ID2D1Brush, 0x2cd906a812e211dc, 0x9fed001143a055f9, ID2D1Resource);
struct {
  void(COMCALL *SetOpacity)(ID2D1Brush *self, float opacity);
  void(COMCALL *SetTransform)(ID2D1Brush *self, const D2D1_MATRIX_3X2_F *transform);
  float(COMCALL *GetOpacity)(ID2D1Brush *self);
  void(COMCALL *GetTransform)(ID2D1Brush *self, D2D1_MATRIX_3X2_F *transform);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(ID2D1BitmapBrush, 0x2cd906aa12e211dc, 0x9fed001143a055f9, ID2D1Brush);
struct {
  void(COMCALL *SetExtendModeX)(ID2D1BitmapBrush *self, D2D1_EXTEND_MODE extendModeX);
  void(COMCALL *SetExtendModeY)(ID2D1BitmapBrush *self, D2D1_EXTEND_MODE extendModeY);
  void(COMCALL *SetInterpolationMode)(ID2D1BitmapBrush *self, D2D1_BITMAP_INTERPOLATION_MODE interpolationMode);
  void(COMCALL *SetBitmap)(ID2D1BitmapBrush *self, ID2D1Bitmap *bitmap);
  D2D1_EXTEND_MODE(COMCALL *GetExtendModeX)(ID2D1BitmapBrush *self);
  D2D1_EXTEND_MODE(COMCALL *GetExtendModeY)(ID2D1BitmapBrush *self);
  D2D1_BITMAP_INTERPOLATION_MODE(COMCALL *GetInterpolationMode)(ID2D1BitmapBrush *self);
  void(COMCALL *GetBitmap)(ID2D1BitmapBrush *self, ID2D1Bitmap **bitmap);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(ID2D1SolidColorBrush, 0x2cd906a912e211dc, 0x9fed001143a055f9, ID2D1Brush);
struct {
  void(COMCALL *SetColor)(ID2D1SolidColorBrush *self, const D2D1_COLOR_F *color);
  D2D1_COLOR_F(COMCALL *GetColor)(ID2D1SolidColorBrush *self);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(ID2D1GradientStopCollection, 0x2cd906a712e211dc, 0x9fed001143a055f9, ID2D1Resource);
struct {
  uint32_t(COMCALL *GetGradientStopCount)(ID2D1GradientStopCollection *self);
  void(COMCALL *GetGradientStops)(ID2D1GradientStopCollection *self, D2D1_GRADIENT_STOP *gradientStops, uint32_t gradientStopsCount);
  D2D1_GAMMA(COMCALL *GetColorInterpolationGamma)(ID2D1GradientStopCollection *self);
  D2D1_EXTEND_MODE(COMCALL *GetExtendMode)(ID2D1GradientStopCollection *self);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(ID2D1LinearGradientBrush, 0x2cd906ab12e211dc, 0x9fed001143a055f9, ID2D1Brush);
struct {
  void(COMCALL *SetStartPoint)(ID2D1LinearGradientBrush *self, D2D1_POINT_2F startPoint);
  void(COMCALL *SetEndPoint)(ID2D1LinearGradientBrush *self, D2D1_POINT_2F endPoint);
  D2D1_POINT_2F(COMCALL *GetStartPoint)(ID2D1LinearGradientBrush *self);
  D2D1_POINT_2F(COMCALL *GetEndPoint)(ID2D1LinearGradientBrush *self);
  void(COMCALL *GetGradientStopCollection)(ID2D1LinearGradientBrush *self, ID2D1GradientStopCollection **gradientStopCollection);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(ID2D1RadialGradientBrush, 0x2cd906ac12e211dc, 0x9fed001143a055f9, ID2D1Brush);
struct {
  void(COMCALL *SetCenter)(ID2D1RadialGradientBrush *self, D2D1_POINT_2F center);
  void(COMCALL *SetGradientOriginOffset)(ID2D1RadialGradientBrush *self, D2D1_POINT_2F gradientOriginOffset);
  void(COMCALL *SetRadiusX)(ID2D1RadialGradientBrush *self, float radiusX);
  void(COMCALL *SetRadiusY)(ID2D1RadialGradientBrush *self, float radiusY);
  D2D1_POINT_2F(COMCALL *GetCenter)(ID2D1RadialGradientBrush *self);
  D2D1_POINT_2F(COMCALL *GetGradientOriginOffset)(ID2D1RadialGradientBrush *self);
  float(COMCALL *GetRadiusX)(ID2D1RadialGradientBrush *self);
  float(COMCALL *GetRadiusY)(ID2D1RadialGradientBrush *self);
  void(COMCALL *GetGradientStopCollection)(ID2D1RadialGradientBrush *self, ID2D1GradientStopCollection **gradientStopCollection);
};
DECLARE_INTERFACE_END;

typedef struct ID2D1BitmapRenderTarget ID2D1BitmapRenderTarget;

DECLARE_INTERFACE(ID2D1Layer, 0x2cd9069b12e211dc, 0x9fed001143a055f9, ID2D1Resource);
struct {
  D2D1_SIZE_F(COMCALL *GetSize)(ID2D1Layer *self);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(ID2D1TessellationSink, 0x2cd906c112e211dc, 0x9fed001143a055f9, Win_IUnknown);
struct {
  void(COMCALL *AddTriangles)(ID2D1TessellationSink *self, const D2D1_TRIANGLE *triangles, uint32_t trianglesCount);
  Win_HRESULT(COMCALL *Close)(ID2D1TessellationSink *self);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(ID2D1Mesh, 0x2cd906c212e211dc, 0x9fed001143a055f9, ID2D1Resource);
struct {
  Win_HRESULT(COMCALL *Open)(ID2D1Mesh *self, ID2D1TessellationSink **tessellationSink);
};
DECLARE_INTERFACE_END;

typedef struct IDWriteTextLayout IDWriteTextLayout;
typedef struct IDWriteTextFormat IDWriteTextFormat;

typedef struct DWRITE_GLYPH_RUN DWRITE_GLYPH_RUN;

DECLARE_INTERFACE(ID2D1RenderTarget, 0x2cd9069412e211dc, 0x9fed001143a055f9, ID2D1Resource);
struct {
  Win_HRESULT(COMCALL *CreateBitmap)(ID2D1RenderTarget *self, D2D1_SIZE_U size, const void *srcData, uint32_t pitch,
                                     const D2D1_BITMAP_PROPERTIES *bitmapProperties, ID2D1Bitmap **bitmap);
  Win_HRESULT(COMCALL *CreateBitmapFromWicBitmap)(ID2D1RenderTarget *self, IWICBitmapSource *wicBitmapSource, const D2D1_BITMAP_PROPERTIES *bitmapProperties,
                                                  ID2D1Bitmap **bitmap);
  Win_HRESULT(COMCALL *CreateSharedBitmap)(ID2D1RenderTarget *self, Uuid *riid, void *data, const D2D1_BITMAP_PROPERTIES *bitmapProperties,
                                           ID2D1Bitmap **bitmap);
  Win_HRESULT(COMCALL *CreateBitmapBrush)(ID2D1RenderTarget *self, ID2D1Bitmap *bitmap, const D2D1_BITMAP_BRUSH_PROPERTIES *bitmapBrushProperties,
                                          const D2D1_BRUSH_PROPERTIES *brushProperties, ID2D1BitmapBrush **bitmapBrush);
  Win_HRESULT(COMCALL *CreateSolidColorBrush)(ID2D1RenderTarget *self, const D2D1_COLOR_F *color, const D2D1_BRUSH_PROPERTIES *brushProperties,
                                              ID2D1SolidColorBrush **solidColorBrush);
  Win_HRESULT(COMCALL *CreateGradientStopCollection)(ID2D1RenderTarget *self, const D2D1_GRADIENT_STOP *gradientStops, uint32_t gradientStopsCount,
                                                     D2D1_GAMMA colorInterpolationGamma, D2D1_EXTEND_MODE extendMode,
                                                     ID2D1GradientStopCollection **gradientStopCollection);
  Win_HRESULT(COMCALL *CreateLinearGradientBrush)(ID2D1RenderTarget *self, const D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES *linearGradientBrushProperties,
                                                  const D2D1_BRUSH_PROPERTIES *brushProperties, ID2D1GradientStopCollection *gradientStopCollection,
                                                  ID2D1LinearGradientBrush **linearGradientBrush);
  Win_HRESULT(COMCALL *CreateRadialGradientBrush)(ID2D1RenderTarget *self, const D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES *radialGradientBrushProperties,
                                                  const D2D1_BRUSH_PROPERTIES *brushProperties, ID2D1GradientStopCollection *gradientStopCollection,
                                                  ID2D1RadialGradientBrush **radialGradientBrush);
  Win_HRESULT(COMCALL *CreateCompatibleRenderTarget)(ID2D1RenderTarget *self, const D2D1_SIZE_F *desiredSize, const D2D1_SIZE_U *desiredPixelSize,
                                                     const D2D1_PIXEL_FORMAT *desiredFormat, D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS options,
                                                     ID2D1BitmapRenderTarget **bitmapRenderTarget);
  Win_HRESULT(COMCALL *CreateLayer)(ID2D1RenderTarget *self, const D2D1_SIZE_F *size, ID2D1Layer **layer);
  Win_HRESULT(COMCALL *CreateMesh)(ID2D1RenderTarget *self, ID2D1Mesh **mesh);
  void(COMCALL *DrawLine)(ID2D1RenderTarget *self, D2D1_POINT_2F point0, D2D1_POINT_2F point1, ID2D1Brush *brush, float strokeWidth,
                          ID2D1StrokeStyle *strokeStyle);
  void(COMCALL *DrawRectangle)(ID2D1RenderTarget *self, const D2D1_RECT_F *rect, ID2D1Brush *brush, float strokeWidth, ID2D1StrokeStyle *strokeStyle);
  void(COMCALL *FillRectangle)(ID2D1RenderTarget *self, const D2D1_RECT_F *rect, ID2D1Brush *brush);
  void(COMCALL *DrawRoundedRectangle)(ID2D1RenderTarget *self, const D2D1_ROUNDED_RECT *roundedRect, ID2D1Brush *brush, float strokeWidth,
                                      ID2D1StrokeStyle *strokeStyle);
  void(COMCALL *FillRoundedRectangle)(ID2D1RenderTarget *self, const D2D1_ROUNDED_RECT *roundedRect, ID2D1Brush *brush);
  void(COMCALL *DrawEllipse)(ID2D1RenderTarget *self, const D2D1_ELLIPSE *ellipse, ID2D1Brush *brush, float strokeWidth, ID2D1StrokeStyle *strokeStyle);
  void(COMCALL *FillEllipse)(ID2D1RenderTarget *self, const D2D1_ELLIPSE *ellipse, ID2D1Brush *brush);
  void(COMCALL *DrawGeometry)(ID2D1RenderTarget *self, ID2D1Geometry *geometry, ID2D1Brush *brush, float strokeWidth, ID2D1StrokeStyle *strokeStyle);
  void(COMCALL *FillGeometry)(ID2D1RenderTarget *self, ID2D1Geometry *geometry, ID2D1Brush *brush, ID2D1Brush *opacityBrush);
  void(COMCALL *FillMesh)(ID2D1RenderTarget *self, ID2D1Mesh *mesh, ID2D1Brush *brush);
  void(COMCALL *FillOpacityMask)(ID2D1RenderTarget *self, ID2D1Bitmap *opacityMask, ID2D1Brush *brush, D2D1_OPACITY_MASK_CONTENT content,
                                 const D2D1_RECT_F *destinationRectangle, const D2D1_RECT_F *sourceRectangle);
  void(COMCALL *DrawBitmap)(ID2D1RenderTarget *self, ID2D1Bitmap *bitmap, const D2D1_RECT_F *destinationRectangle, float opacity,
                            D2D1_BITMAP_INTERPOLATION_MODE interpolationMode, const D2D1_RECT_F *sourceRectangle);
  void(COMCALL *DrawText)(ID2D1RenderTarget *self, const Win_WCHAR *string, uint32_t stringLength, IDWriteTextFormat *textFormat, const D2D1_RECT_F *layoutRect,
                          ID2D1Brush *defaultFillBrush, D2D1_DRAW_TEXT_OPTIONS options, DWRITE_MEASURING_MODE measuringMode);
  void(COMCALL *DrawTextLayout)(ID2D1RenderTarget *self, D2D1_POINT_2F origin, IDWriteTextLayout *textLayout, ID2D1Brush *defaultFillBrush,
                                D2D1_DRAW_TEXT_OPTIONS options);
  void(COMCALL *DrawGlyphRun)(ID2D1RenderTarget *self, D2D1_POINT_2F baselineOrigin, const DWRITE_GLYPH_RUN *glyphRun, ID2D1Brush *foregroundBrush,
                              DWRITE_MEASURING_MODE measuringMode);
  void(COMCALL *SetTransform)(ID2D1RenderTarget *self, const D2D1_MATRIX_3X2_F *transform);
  void(COMCALL *GetTransform)(ID2D1RenderTarget *self, D2D1_MATRIX_3X2_F *transform);
  void(COMCALL *SetAntialiasMode)(ID2D1RenderTarget *self, D2D1_ANTIALIAS_MODE antialiasMode);
  D2D1_ANTIALIAS_MODE(COMCALL *GetAntialiasMode)(ID2D1RenderTarget *self);
  void(COMCALL *SetTextAntialiasMode)(ID2D1RenderTarget *self, D2D1_TEXT_ANTIALIAS_MODE textAntialiasMode);
  D2D1_TEXT_ANTIALIAS_MODE(COMCALL *GetTextAntialiasMode)(ID2D1RenderTarget *self);
  void(COMCALL *SetTextRenderingParams)(ID2D1RenderTarget *self, IDWriteRenderingParams *textRenderingParams);
  void(COMCALL *GetTextRenderingParams)(ID2D1RenderTarget *self, IDWriteRenderingParams **textRenderingParams);
  void(COMCALL *SetTags)(ID2D1RenderTarget *self, D2D1_TAG tag1, D2D1_TAG tag2);
  void(COMCALL *GetTags)(ID2D1RenderTarget *self, D2D1_TAG *tag1, D2D1_TAG *tag2);
  void(COMCALL *PushLayer)(ID2D1RenderTarget *self, const D2D1_LAYER_PARAMETERS *layerParameters, ID2D1Layer *layer);
  void(COMCALL *PopLayer)(ID2D1RenderTarget *self);
  Win_HRESULT(COMCALL *Flush)(ID2D1RenderTarget *self, D2D1_TAG *tag1, D2D1_TAG *tag2);
  void(COMCALL *SaveDrawingState)(ID2D1RenderTarget *self, ID2D1DrawingStateBlock *drawingStateBlock);
  void(COMCALL *RestoreDrawingState)(ID2D1RenderTarget *self, ID2D1DrawingStateBlock *drawingStateBlock);
  void(COMCALL *PushAxisAlignedClip)(ID2D1RenderTarget *self, const D2D1_RECT_F *clipRect, D2D1_ANTIALIAS_MODE antialiasMode);
  void(COMCALL *PopAxisAlignedClip)(ID2D1RenderTarget *self);
  void(COMCALL *Clear)(ID2D1RenderTarget *self, const D2D1_COLOR_F *clearColor);
  void(COMCALL *BeginDraw)(ID2D1RenderTarget *self);
  Win_HRESULT(COMCALL *EndDraw)(ID2D1RenderTarget *self, D2D1_TAG *tag1, D2D1_TAG *tag2);
  D2D1_PIXEL_FORMAT(COMCALL *GetPixelFormat)(ID2D1RenderTarget *self);
  void(COMCALL *SetDpi)(ID2D1RenderTarget *self, float dpiX, float dpiY);
  void(COMCALL *GetDpi)(ID2D1RenderTarget *self, float *dpiX, float *dpiY);
  D2D1_SIZE_F(COMCALL *GetSize)(ID2D1RenderTarget *self);
  D2D1_SIZE_U(COMCALL *GetPixelSize)(ID2D1RenderTarget *self);
  uint32_t(COMCALL *GetMaximumBitmapSize)(ID2D1RenderTarget *self);
  int32_t(COMCALL *IsSupported)(ID2D1RenderTarget *self, const D2D1_RENDER_TARGET_PROPERTIES *renderTargetProperties);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(ID2D1HwndRenderTarget, 0x2cd9069812e211dc, 0x9fed001143a055f9, ID2D1RenderTarget);
struct {
  D2D1_WINDOW_STATE(COMCALL *CheckWindowState)(ID2D1HwndRenderTarget *self);
  Win_HRESULT(COMCALL *Resize)(ID2D1HwndRenderTarget *self, const D2D1_SIZE_U *pixelSize);
  Win_HWND(COMCALL *GetHwnd)(ID2D1HwndRenderTarget *self);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(ID2D1BitmapRenderTarget, 0x2cd9069512e211dc, 0x9fed001143a055f9, ID2D1RenderTarget);
struct {
  Win_HRESULT(COMCALL *GetBitmap)(ID2D1BitmapRenderTarget *self, ID2D1Bitmap **bitmap);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(IDXGIObject, 0xaec22fb876f34639, 0x9be028eb43a67a2e, Win_IUnknown);
struct {
  Win_HRESULT(COMCALL *SetPrivateData)(IDXGIObject *self, Uuid *Name, uint32_t DataSize, const void *pData);
  Win_HRESULT(COMCALL *SetPrivateDataInterface)(IDXGIObject *self, Uuid *Name, const Win_IUnknown *pUnknown);
  Win_HRESULT(COMCALL *GetPrivateData)(IDXGIObject *self, Uuid *Name, uint32_t *pDataSize, void *pData);
  Win_HRESULT(COMCALL *GetParent)(IDXGIObject *self, Uuid *riid, void **ppParent);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(IDXGIDeviceSubObject, 0x3d3e0379f9de4d58, 0xbb6c18d62992f1a6, IDXGIObject);
struct {
  Win_HRESULT(COMCALL *GetDevice)(IDXGIDeviceSubObject *self, Uuid *riid, void **ppDevice);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(IDXGISurface, 0xcafcb56c6ac34889, 0xbf479e23bbd260ec, IDXGIDeviceSubObject);
struct {
  Win_HRESULT(COMCALL *GetDesc)(IDXGISurface *self, DXGI_SURFACE_DESC *pDesc);
  Win_HRESULT(COMCALL *Map)(IDXGISurface *self, DXGI_MAPPED_RECT *pLockedRect, uint32_t MapFlags);
  Win_HRESULT(COMCALL *Unmap)(IDXGISurface *self);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(ID2D1DCRenderTarget, 0x1c51bc64de6146fd, 0x989963a5d8f03950, ID2D1RenderTarget);
struct {
  Win_HRESULT(COMCALL *BindDC)(ID2D1DCRenderTarget *self, const Win_HDC hDC, const Win_RECT *pSubRect);
};
DECLARE_INTERFACE_END;

//////////////////////////////////////////////////////////////////
// Interface : ID2D1Factory
DECLARE_INTERFACE(ID2D1Factory, 0x061522476f50465a, 0x9245118bfd3b6007, Win_IUnknown);
struct {
  Win_HRESULT(COMCALL *ReloadSystemMetrics)(ID2D1Factory *self);
  void(COMCALL *GetDesktopDpi)(ID2D1Factory *self, float *dpiX, float *dpiY);
  Win_HRESULT(COMCALL *CreateRectangleGeometry)(ID2D1Factory *self, const D2D1_RECT_F *rectangle, ID2D1RectangleGeometry **rectangleGeometry);
  Win_HRESULT(COMCALL *CreateRoundedRectangleGeometry)(ID2D1Factory *self, const D2D1_ROUNDED_RECT *roundedRectangle,
                                                       ID2D1RoundedRectangleGeometry **roundedRectangleGeometry);
  Win_HRESULT(COMCALL *CreateEllipseGeometry)(ID2D1Factory *self, const D2D1_ELLIPSE *ellipse, ID2D1EllipseGeometry **ellipseGeometry);
  Win_HRESULT(COMCALL *CreateGeometryGroup)(ID2D1Factory *self, D2D1_FILL_MODE fillMode, ID2D1Geometry **geometries, uint32_t geometriesCount,
                                            ID2D1GeometryGroup **geometryGroup);
  Win_HRESULT(COMCALL *CreateTransformedGeometry)(ID2D1Factory *self, ID2D1Geometry *sourceGeometry, const D2D1_MATRIX_3X2_F *transform,
                                                  ID2D1TransformedGeometry **transformedGeometry);
  Win_HRESULT(COMCALL *CreatePathGeometry)(ID2D1Factory *self, ID2D1PathGeometry **pathGeometry);
  Win_HRESULT(COMCALL *CreateStrokeStyle)(ID2D1Factory *self, const D2D1_STROKE_STYLE_PROPERTIES *strokeStyleProperties, const float *dashes,
                                          uint32_t dashesCount, ID2D1StrokeStyle **strokeStyle);
  Win_HRESULT(COMCALL *CreateDrawingStateBlock)(ID2D1Factory *self, const D2D1_DRAWING_STATE_DESCRIPTION *drawingStateDescription,
                                                IDWriteRenderingParams *textRenderingParams, ID2D1DrawingStateBlock **drawingStateBlock);
  Win_HRESULT(COMCALL *CreateWicBitmapRenderTarget)(ID2D1Factory *self, IWICBitmap *target, const D2D1_RENDER_TARGET_PROPERTIES *renderTargetProperties,
                                                    ID2D1RenderTarget **renderTarget);
  Win_HRESULT(COMCALL *CreateHwndRenderTarget)(ID2D1Factory *self, const D2D1_RENDER_TARGET_PROPERTIES *renderTargetProperties,
                                               const D2D1_HWND_RENDER_TARGET_PROPERTIES *hwndRenderTargetProperties, ID2D1HwndRenderTarget **hwndRenderTarget);
  Win_HRESULT(COMCALL *CreateDxgiSurfaceRenderTarget)(ID2D1Factory *self, IDXGISurface *dxgiSurface,
                                                      const D2D1_RENDER_TARGET_PROPERTIES *renderTargetProperties, ID2D1RenderTarget **renderTarget);
  Win_HRESULT(COMCALL *CreateDCRenderTarget)(ID2D1Factory *self, const D2D1_RENDER_TARGET_PROPERTIES *renderTargetProperties,
                                             ID2D1DCRenderTarget **dcRenderTarget);
};
DECLARE_INTERFACE_END;

EXTERN Win_HRESULT(STDCALL *D2D1CreateFactory)(D2D1_FACTORY_TYPE factoryType, const Uuid *const riid, const D2D1_FACTORY_OPTIONS *pFactoryOptions,
                                               void **ppIFactory);

#endif