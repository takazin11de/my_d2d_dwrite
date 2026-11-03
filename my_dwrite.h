#ifndef MY_DWRITE_H
#define MY_DWRITE_H

#include "com.h"
#include "my_dcommon.h"
#include "my_win.h"

#include <stddef.h>
#include <stdint.h>
//////////////////////////////

typedef uint32_t DWRITE_FACTORY_TYPE;
enum {
  DWRITE_FACTORY_TYPE_SHARED,
  DWRITE_FACTORY_TYPE_ISOLATED,
};

typedef uint32_t DWRITE_PIXEL_GEOMETRY;
enum {
  DWRITE_PIXEL_GEOMETRY_FLAT,
  DWRITE_PIXEL_GEOMETRY_RGB,
  DWRITE_PIXEL_GEOMETRY_BGR,
};

typedef uint32_t DWRITE_RENDERING_MODE;
enum {
  DWRITE_RENDERING_MODE_DEFAULT,
  DWRITE_RENDERING_MODE_ALIASED,
  DWRITE_RENDERING_MODE_GDI_CLASSIC,
  DWRITE_RENDERING_MODE_GDI_NATURAL,
  DWRITE_RENDERING_MODE_NATURAL,
  DWRITE_RENDERING_MODE_NATURAL_SYMMETRIC,
  DWRITE_RENDERING_MODE_OUTLINE,
  DWRITE_RENDERING_MODE_CLEARTYPE_GDI_CLASSIC       = DWRITE_RENDERING_MODE_GDI_CLASSIC,
  DWRITE_RENDERING_MODE_CLEARTYPE_GDI_NATURAL       = DWRITE_RENDERING_MODE_GDI_NATURAL,
  DWRITE_RENDERING_MODE_CLEARTYPE_NATURAL           = DWRITE_RENDERING_MODE_NATURAL,
  DWRITE_RENDERING_MODE_CLEARTYPE_NATURAL_SYMMETRIC = DWRITE_RENDERING_MODE_NATURAL_SYMMETRIC,
};

typedef uint32_t DWRITE_TEXT_ALIGNMENT;
enum {
  DWRITE_TEXT_ALIGNMENT_LEADING,
  DWRITE_TEXT_ALIGNMENT_TRAILING,
  DWRITE_TEXT_ALIGNMENT_CENTER,
  DWRITE_TEXT_ALIGNMENT_JUSTIFIED,
};

typedef uint32_t DWRITE_PARAGRAPH_ALIGNMENT;
enum {
  DWRITE_PARAGRAPH_ALIGNMENT_NEAR,
  DWRITE_PARAGRAPH_ALIGNMENT_FAR,
  DWRITE_PARAGRAPH_ALIGNMENT_CENTER,
};

typedef uint32_t DWRITE_WORD_WRAPPING;
enum {
  DWRITE_WORD_WRAPPING_WRAP            = 0,
  DWRITE_WORD_WRAPPING_NO_WRAP         = 1,
  DWRITE_WORD_WRAPPING_EMERGENCY_BREAK = 2,
  DWRITE_WORD_WRAPPING_WHOLE_WORD      = 3,
  DWRITE_WORD_WRAPPING_CHARACTER       = 4,
};

typedef uint32_t DWRITE_READING_DIRECTION;
enum {
  DWRITE_READING_DIRECTION_LEFT_TO_RIGHT = 0,
  DWRITE_READING_DIRECTION_RIGHT_TO_LEFT = 1,
  DWRITE_READING_DIRECTION_TOP_TO_BOTTOM = 2,
  DWRITE_READING_DIRECTION_BOTTOM_TO_TOP = 3,
};

typedef uint32_t DWRITE_FLOW_DIRECTION;
enum {
  DWRITE_FLOW_DIRECTION_TOP_TO_BOTTOM = 0,
  DWRITE_FLOW_DIRECTION_BOTTOM_TO_TOP = 1,
  DWRITE_FLOW_DIRECTION_LEFT_TO_RIGHT = 2,
  DWRITE_FLOW_DIRECTION_RIGHT_TO_LEFT = 3,
};

typedef uint32_t DWRITE_TRIMMING_GRANULARITY;
enum {
  DWRITE_TRIMMING_GRANULARITY_NONE,
  DWRITE_TRIMMING_GRANULARITY_CHARACTER,
  DWRITE_TRIMMING_GRANULARITY_WORD,
};

typedef uint32_t DWRITE_LINE_SPACING_METHOD;
enum {
  DWRITE_LINE_SPACING_METHOD_DEFAULT,
  DWRITE_LINE_SPACING_METHOD_UNIFORM,
  DWRITE_LINE_SPACING_METHOD_PROPORTIONAL,
};

typedef uint32_t DWRITE_FONT_WEIGHT;
enum {
  DWRITE_FONT_WEIGHT_THIN        = 100,
  DWRITE_FONT_WEIGHT_EXTRA_LIGHT = 200,
  DWRITE_FONT_WEIGHT_ULTRA_LIGHT = 200,
  DWRITE_FONT_WEIGHT_LIGHT       = 300,
  DWRITE_FONT_WEIGHT_SEMI_LIGHT  = 350,
  DWRITE_FONT_WEIGHT_NORMAL      = 400,
  DWRITE_FONT_WEIGHT_REGULAR     = 400,
  DWRITE_FONT_WEIGHT_MEDIUM      = 500,
  DWRITE_FONT_WEIGHT_DEMI_BOLD   = 600,
  DWRITE_FONT_WEIGHT_SEMI_BOLD   = 600,
  DWRITE_FONT_WEIGHT_BOLD        = 700,
  DWRITE_FONT_WEIGHT_EXTRA_BOLD  = 800,
  DWRITE_FONT_WEIGHT_ULTRA_BOLD  = 800,
  DWRITE_FONT_WEIGHT_BLACK       = 900,
  DWRITE_FONT_WEIGHT_HEAVY       = 900,
  DWRITE_FONT_WEIGHT_EXTRA_BLACK = 950,
  DWRITE_FONT_WEIGHT_ULTRA_BLACK = 950,
};

typedef uint32_t DWRITE_FONT_STYLE;
enum {
  DWRITE_FONT_STYLE_NORMAL,
  DWRITE_FONT_STYLE_OBLIQUE,
  DWRITE_FONT_STYLE_ITALIC,
};

typedef uint32_t DWRITE_FONT_STRETCH;
enum {
  DWRITE_FONT_STRETCH_UNDEFINED       = 0,
  DWRITE_FONT_STRETCH_ULTRA_CONDENSED = 1,
  DWRITE_FONT_STRETCH_EXTRA_CONDENSED = 2,
  DWRITE_FONT_STRETCH_CONDENSED       = 3,
  DWRITE_FONT_STRETCH_SEMI_CONDENSED  = 4,
  DWRITE_FONT_STRETCH_NORMAL          = 5,
  DWRITE_FONT_STRETCH_MEDIUM          = 5,
  DWRITE_FONT_STRETCH_SEMI_EXPANDED   = 6,
  DWRITE_FONT_STRETCH_EXPANDED        = 7,
  DWRITE_FONT_STRETCH_EXTRA_EXPANDED  = 8,
  DWRITE_FONT_STRETCH_ULTRA_EXPANDED  = 9,
};

typedef uint32_t DWRITE_INFORMATIONAL_STRING_ID;
enum {
  DWRITE_INFORMATIONAL_STRING_NONE,
  DWRITE_INFORMATIONAL_STRING_COPYRIGHT_NOTICE,
  DWRITE_INFORMATIONAL_STRING_VERSION_STRINGS,
  DWRITE_INFORMATIONAL_STRING_TRADEMARK,
  DWRITE_INFORMATIONAL_STRING_MANUFACTURER,
  DWRITE_INFORMATIONAL_STRING_DESIGNER,
  DWRITE_INFORMATIONAL_STRING_DESIGNER_URL,
  DWRITE_INFORMATIONAL_STRING_DESCRIPTION,
  DWRITE_INFORMATIONAL_STRING_FONT_VENDOR_URL,
  DWRITE_INFORMATIONAL_STRING_LICENSE_DESCRIPTION,
  DWRITE_INFORMATIONAL_STRING_LICENSE_INFO_URL,
  DWRITE_INFORMATIONAL_STRING_WIN32_FAMILY_NAMES,
  DWRITE_INFORMATIONAL_STRING_WIN32_SUBFAMILY_NAMES,
  DWRITE_INFORMATIONAL_STRING_TYPOGRAPHIC_FAMILY_NAMES,
  DWRITE_INFORMATIONAL_STRING_TYPOGRAPHIC_SUBFAMILY_NAMES,
  DWRITE_INFORMATIONAL_STRING_SAMPLE_TEXT,
  DWRITE_INFORMATIONAL_STRING_FULL_NAME,
  DWRITE_INFORMATIONAL_STRING_POSTSCRIPT_NAME,
  DWRITE_INFORMATIONAL_STRING_POSTSCRIPT_CID_NAME,
  DWRITE_INFORMATIONAL_STRING_WEIGHT_STRETCH_STYLE_FAMILY_NAME,
  DWRITE_INFORMATIONAL_STRING_DESIGN_SCRIPT_LANGUAGE_TAG,
  DWRITE_INFORMATIONAL_STRING_SUPPORTED_SCRIPT_LANGUAGE_TAG,
  DWRITE_INFORMATIONAL_STRING_PREFERRED_FAMILY_NAMES    = DWRITE_INFORMATIONAL_STRING_TYPOGRAPHIC_FAMILY_NAMES,
  DWRITE_INFORMATIONAL_STRING_PREFERRED_SUBFAMILY_NAMES = DWRITE_INFORMATIONAL_STRING_TYPOGRAPHIC_SUBFAMILY_NAMES,
  DWRITE_INFORMATIONAL_STRING_WWS_FAMILY_NAME           = DWRITE_INFORMATIONAL_STRING_WEIGHT_STRETCH_STYLE_FAMILY_NAME,
};

typedef uint32_t DWRITE_FONT_SIMULATIONS;
enum {
  DWRITE_FONT_SIMULATIONS_NONE    = 0x0000,
  DWRITE_FONT_SIMULATIONS_BOLD    = 0x0001,
  DWRITE_FONT_SIMULATIONS_OBLIQUE = 0x0002,
};

typedef uint32_t DWRITE_FONT_FACE_TYPE;
enum {
  DWRITE_FONT_FACE_TYPE_CFF,
  DWRITE_FONT_FACE_TYPE_TRUETYPE,
  DWRITE_FONT_FACE_TYPE_OPENTYPE_COLLECTION,
  DWRITE_FONT_FACE_TYPE_TYPE1,
  DWRITE_FONT_FACE_TYPE_VECTOR,
  DWRITE_FONT_FACE_TYPE_BITMAP,
  DWRITE_FONT_FACE_TYPE_UNKNOWN,
  DWRITE_FONT_FACE_TYPE_RAW_CFF,
  DWRITE_FONT_FACE_TYPE_TRUETYPE_COLLECTION = DWRITE_FONT_FACE_TYPE_OPENTYPE_COLLECTION,
};

typedef uint32_t DWRITE_FONT_FILE_TYPE;
enum {
  DWRITE_FONT_FILE_TYPE_UNKNOWN,
  DWRITE_FONT_FILE_TYPE_CFF,
  DWRITE_FONT_FILE_TYPE_TRUETYPE,
  DWRITE_FONT_FILE_TYPE_OPENTYPE_COLLECTION,
  DWRITE_FONT_FILE_TYPE_TYPE1_PFM,
  DWRITE_FONT_FILE_TYPE_TYPE1_PFB,
  DWRITE_FONT_FILE_TYPE_VECTOR,
  DWRITE_FONT_FILE_TYPE_BITMAP,
  DWRITE_FONT_FILE_TYPE_TRUETYPE_COLLECTION = DWRITE_FONT_FILE_TYPE_OPENTYPE_COLLECTION,
};

typedef uint32_t DWRITE_BREAK_CONDITION;
enum {
  DWRITE_BREAK_CONDITION_NEUTRAL,
  DWRITE_BREAK_CONDITION_CAN_BREAK,
  DWRITE_BREAK_CONDITION_MAY_NOT_BREAK,
  DWRITE_BREAK_CONDITION_MUST_BREAK,
};

#define DWRITE_MAKE_OPENTYPE_TAG(a, b, c, d)                                                                                                                   \
  ((uint32_t)((uint8_t)(d)) << 24) | ((uint32_t)((uint8_t)(c)) << 16) | ((uint32_t)((uint8_t)(b)) << 8) | ((uint32_t)((uint8_t)(a)))

typedef uint32_t DWRITE_FONT_FEATURE_TAG;
enum {
  DWRITE_FONT_FEATURE_TAG_ALTERNATIVE_FRACTIONS            = DWRITE_MAKE_OPENTYPE_TAG('a', 'f', 'r', 'c'),
  DWRITE_FONT_FEATURE_TAG_PETITE_CAPITALS_FROM_CAPITALS    = DWRITE_MAKE_OPENTYPE_TAG('c', '2', 'p', 'c'),
  DWRITE_FONT_FEATURE_TAG_SMALL_CAPITALS_FROM_CAPITALS     = DWRITE_MAKE_OPENTYPE_TAG('c', '2', 's', 'c'),
  DWRITE_FONT_FEATURE_TAG_CONTEXTUAL_ALTERNATES            = DWRITE_MAKE_OPENTYPE_TAG('c', 'a', 'l', 't'),
  DWRITE_FONT_FEATURE_TAG_CASE_SENSITIVE_FORMS             = DWRITE_MAKE_OPENTYPE_TAG('c', 'a', 's', 'e'),
  DWRITE_FONT_FEATURE_TAG_GLYPH_COMPOSITION_DECOMPOSITION  = DWRITE_MAKE_OPENTYPE_TAG('c', 'c', 'm', 'p'),
  DWRITE_FONT_FEATURE_TAG_CONTEXTUAL_LIGATURES             = DWRITE_MAKE_OPENTYPE_TAG('c', 'l', 'i', 'g'),
  DWRITE_FONT_FEATURE_TAG_CAPITAL_SPACING                  = DWRITE_MAKE_OPENTYPE_TAG('c', 'p', 's', 'p'),
  DWRITE_FONT_FEATURE_TAG_CONTEXTUAL_SWASH                 = DWRITE_MAKE_OPENTYPE_TAG('c', 's', 'w', 'h'),
  DWRITE_FONT_FEATURE_TAG_CURSIVE_POSITIONING              = DWRITE_MAKE_OPENTYPE_TAG('c', 'u', 'r', 's'),
  DWRITE_FONT_FEATURE_TAG_DEFAULT                          = DWRITE_MAKE_OPENTYPE_TAG('d', 'f', 'l', 't'),
  DWRITE_FONT_FEATURE_TAG_DISCRETIONARY_LIGATURES          = DWRITE_MAKE_OPENTYPE_TAG('d', 'l', 'i', 'g'),
  DWRITE_FONT_FEATURE_TAG_EXPERT_FORMS                     = DWRITE_MAKE_OPENTYPE_TAG('e', 'x', 'p', 't'),
  DWRITE_FONT_FEATURE_TAG_FRACTIONS                        = DWRITE_MAKE_OPENTYPE_TAG('f', 'r', 'a', 'c'),
  DWRITE_FONT_FEATURE_TAG_FULL_WIDTH                       = DWRITE_MAKE_OPENTYPE_TAG('f', 'w', 'i', 'd'),
  DWRITE_FONT_FEATURE_TAG_HALF_FORMS                       = DWRITE_MAKE_OPENTYPE_TAG('h', 'a', 'l', 'f'),
  DWRITE_FONT_FEATURE_TAG_HALANT_FORMS                     = DWRITE_MAKE_OPENTYPE_TAG('h', 'a', 'l', 'n'),
  DWRITE_FONT_FEATURE_TAG_ALTERNATE_HALF_WIDTH             = DWRITE_MAKE_OPENTYPE_TAG('h', 'a', 'l', 't'),
  DWRITE_FONT_FEATURE_TAG_HISTORICAL_FORMS                 = DWRITE_MAKE_OPENTYPE_TAG('h', 'i', 's', 't'),
  DWRITE_FONT_FEATURE_TAG_HORIZONTAL_KANA_ALTERNATES       = DWRITE_MAKE_OPENTYPE_TAG('h', 'k', 'n', 'a'),
  DWRITE_FONT_FEATURE_TAG_HISTORICAL_LIGATURES             = DWRITE_MAKE_OPENTYPE_TAG('h', 'l', 'i', 'g'),
  DWRITE_FONT_FEATURE_TAG_HALF_WIDTH                       = DWRITE_MAKE_OPENTYPE_TAG('h', 'w', 'i', 'd'),
  DWRITE_FONT_FEATURE_TAG_HOJO_KANJI_FORMS                 = DWRITE_MAKE_OPENTYPE_TAG('h', 'o', 'j', 'o'),
  DWRITE_FONT_FEATURE_TAG_JIS04_FORMS                      = DWRITE_MAKE_OPENTYPE_TAG('j', 'p', '0', '4'),
  DWRITE_FONT_FEATURE_TAG_JIS78_FORMS                      = DWRITE_MAKE_OPENTYPE_TAG('j', 'p', '7', '8'),
  DWRITE_FONT_FEATURE_TAG_JIS83_FORMS                      = DWRITE_MAKE_OPENTYPE_TAG('j', 'p', '8', '3'),
  DWRITE_FONT_FEATURE_TAG_JIS90_FORMS                      = DWRITE_MAKE_OPENTYPE_TAG('j', 'p', '9', '0'),
  DWRITE_FONT_FEATURE_TAG_KERNING                          = DWRITE_MAKE_OPENTYPE_TAG('k', 'e', 'r', 'n'),
  DWRITE_FONT_FEATURE_TAG_STANDARD_LIGATURES               = DWRITE_MAKE_OPENTYPE_TAG('l', 'i', 'g', 'a'),
  DWRITE_FONT_FEATURE_TAG_LINING_FIGURES                   = DWRITE_MAKE_OPENTYPE_TAG('l', 'n', 'u', 'm'),
  DWRITE_FONT_FEATURE_TAG_LOCALIZED_FORMS                  = DWRITE_MAKE_OPENTYPE_TAG('l', 'o', 'c', 'l'),
  DWRITE_FONT_FEATURE_TAG_MARK_POSITIONING                 = DWRITE_MAKE_OPENTYPE_TAG('m', 'a', 'r', 'k'),
  DWRITE_FONT_FEATURE_TAG_MATHEMATICAL_GREEK               = DWRITE_MAKE_OPENTYPE_TAG('m', 'g', 'r', 'k'),
  DWRITE_FONT_FEATURE_TAG_MARK_TO_MARK_POSITIONING         = DWRITE_MAKE_OPENTYPE_TAG('m', 'k', 'm', 'k'),
  DWRITE_FONT_FEATURE_TAG_ALTERNATE_ANNOTATION_FORMS       = DWRITE_MAKE_OPENTYPE_TAG('n', 'a', 'l', 't'),
  DWRITE_FONT_FEATURE_TAG_NLC_KANJI_FORMS                  = DWRITE_MAKE_OPENTYPE_TAG('n', 'l', 'c', 'k'),
  DWRITE_FONT_FEATURE_TAG_OLD_STYLE_FIGURES                = DWRITE_MAKE_OPENTYPE_TAG('o', 'n', 'u', 'm'),
  DWRITE_FONT_FEATURE_TAG_ORDINALS                         = DWRITE_MAKE_OPENTYPE_TAG('o', 'r', 'd', 'n'),
  DWRITE_FONT_FEATURE_TAG_PROPORTIONAL_ALTERNATE_WIDTH     = DWRITE_MAKE_OPENTYPE_TAG('p', 'a', 'l', 't'),
  DWRITE_FONT_FEATURE_TAG_PETITE_CAPITALS                  = DWRITE_MAKE_OPENTYPE_TAG('p', 'c', 'a', 'p'),
  DWRITE_FONT_FEATURE_TAG_PROPORTIONAL_FIGURES             = DWRITE_MAKE_OPENTYPE_TAG('p', 'n', 'u', 'm'),
  DWRITE_FONT_FEATURE_TAG_PROPORTIONAL_WIDTHS              = DWRITE_MAKE_OPENTYPE_TAG('p', 'w', 'i', 'd'),
  DWRITE_FONT_FEATURE_TAG_QUARTER_WIDTHS                   = DWRITE_MAKE_OPENTYPE_TAG('q', 'w', 'i', 'd'),
  DWRITE_FONT_FEATURE_TAG_REQUIRED_LIGATURES               = DWRITE_MAKE_OPENTYPE_TAG('r', 'l', 'i', 'g'),
  DWRITE_FONT_FEATURE_TAG_RUBY_NOTATION_FORMS              = DWRITE_MAKE_OPENTYPE_TAG('r', 'u', 'b', 'y'),
  DWRITE_FONT_FEATURE_TAG_STYLISTIC_ALTERNATES             = DWRITE_MAKE_OPENTYPE_TAG('s', 'a', 'l', 't'),
  DWRITE_FONT_FEATURE_TAG_SCIENTIFIC_INFERIORS             = DWRITE_MAKE_OPENTYPE_TAG('s', 'i', 'n', 'f'),
  DWRITE_FONT_FEATURE_TAG_SMALL_CAPITALS                   = DWRITE_MAKE_OPENTYPE_TAG('s', 'm', 'c', 'p'),
  DWRITE_FONT_FEATURE_TAG_SIMPLIFIED_FORMS                 = DWRITE_MAKE_OPENTYPE_TAG('s', 'm', 'p', 'l'),
  DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_1                  = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '0', '1'),
  DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_2                  = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '0', '2'),
  DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_3                  = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '0', '3'),
  DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_4                  = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '0', '4'),
  DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_5                  = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '0', '5'),
  DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_6                  = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '0', '6'),
  DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_7                  = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '0', '7'),
  DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_8                  = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '0', '8'),
  DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_9                  = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '0', '9'),
  DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_10                 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '1', '0'),
  DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_11                 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '1', '1'),
  DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_12                 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '1', '2'),
  DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_13                 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '1', '3'),
  DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_14                 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '1', '4'),
  DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_15                 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '1', '5'),
  DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_16                 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '1', '6'),
  DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_17                 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '1', '7'),
  DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_18                 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '1', '8'),
  DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_19                 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '1', '9'),
  DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_20                 = DWRITE_MAKE_OPENTYPE_TAG('s', 's', '2', '0'),
  DWRITE_FONT_FEATURE_TAG_SUBSCRIPT                        = DWRITE_MAKE_OPENTYPE_TAG('s', 'u', 'b', 's'),
  DWRITE_FONT_FEATURE_TAG_SUPERSCRIPT                      = DWRITE_MAKE_OPENTYPE_TAG('s', 'u', 'p', 's'),
  DWRITE_FONT_FEATURE_TAG_SWASH                            = DWRITE_MAKE_OPENTYPE_TAG('s', 'w', 's', 'h'),
  DWRITE_FONT_FEATURE_TAG_TITLING                          = DWRITE_MAKE_OPENTYPE_TAG('t', 'i', 't', 'l'),
  DWRITE_FONT_FEATURE_TAG_TRADITIONAL_NAME_FORMS           = DWRITE_MAKE_OPENTYPE_TAG('t', 'n', 'a', 'm'),
  DWRITE_FONT_FEATURE_TAG_TABULAR_FIGURES                  = DWRITE_MAKE_OPENTYPE_TAG('t', 'n', 'u', 'm'),
  DWRITE_FONT_FEATURE_TAG_TRADITIONAL_FORMS                = DWRITE_MAKE_OPENTYPE_TAG('t', 'r', 'a', 'd'),
  DWRITE_FONT_FEATURE_TAG_THIRD_WIDTHS                     = DWRITE_MAKE_OPENTYPE_TAG('t', 'w', 'i', 'd'),
  DWRITE_FONT_FEATURE_TAG_UNICASE                          = DWRITE_MAKE_OPENTYPE_TAG('u', 'n', 'i', 'c'),
  DWRITE_FONT_FEATURE_TAG_VERTICAL_WRITING                 = DWRITE_MAKE_OPENTYPE_TAG('v', 'e', 'r', 't'),
  DWRITE_FONT_FEATURE_TAG_VERTICAL_ALTERNATES_AND_ROTATION = DWRITE_MAKE_OPENTYPE_TAG('v', 'r', 't', '2'),
  DWRITE_FONT_FEATURE_TAG_SLASHED_ZERO                     = DWRITE_MAKE_OPENTYPE_TAG('z', 'e', 'r', 'o'),
};

typedef uint32_t DWRITE_SCRIPT_SHAPES;
enum {
  DWRITE_SCRIPT_SHAPES_DEFAULT   = 0,
  DWRITE_SCRIPT_SHAPES_NO_VISUAL = 1,
};

typedef uint32_t DWRITE_NUMBER_SUBSTITUTION_METHOD;
enum {
  DWRITE_NUMBER_SUBSTITUTION_METHOD_FROM_CULTURE,
  DWRITE_NUMBER_SUBSTITUTION_METHOD_CONTEXTUAL,
  DWRITE_NUMBER_SUBSTITUTION_METHOD_NONE,
  DWRITE_NUMBER_SUBSTITUTION_METHOD_NATIONAL,
  DWRITE_NUMBER_SUBSTITUTION_METHOD_TRADITIONAL,
};

typedef uint32_t DWRITE_TEXTURE_TYPE;
enum {
  DWRITE_TEXTURE_ALIASED_1x1,
  DWRITE_TEXTURE_CLEARTYPE_3x1,
};

typedef struct {
  DWRITE_TRIMMING_GRANULARITY granularity;
  uint32_t delimiter;
  uint32_t delimiterCount;
} DWRITE_TRIMMING;

typedef struct {
  uint16_t designUnitsPerEm;
  uint16_t ascent;
  uint16_t descent;
  int16_t lineGap;
  uint16_t capHeight;
  uint16_t xHeight;
  int16_t underlinePosition;
  uint16_t underlineThickness;
  int16_t strikethroughPosition;
  uint16_t strikethroughThickness;
} DWRITE_FONT_METRICS;

typedef struct {
  int32_t leftSideBearing;
  uint32_t advanceWidth;
  int32_t rightSideBearing;
  int32_t topSideBearing;
  uint32_t advanceHeight;
  int32_t bottomSideBearing;
  int32_t verticalOriginY;
} DWRITE_GLYPH_METRICS;

typedef struct {
  float advanceOffset;
  float ascenderOffset;
} DWRITE_GLYPH_OFFSET;

typedef struct {
  float m11;
  float m12;
  float m21;
  float m22;
  float dx;
  float dy;
} DWRITE_MATRIX;

typedef struct {
  float width;
  float height;
  float baseline;
  int32_t supportsSideways;
} DWRITE_INLINE_OBJECT_METRICS;

typedef struct {
  float left;
  float top;
  float right;
  float bottom;
} DWRITE_OVERHANG_METRICS;

typedef struct {
  Win_WCHAR const *localeName;
  Win_WCHAR const *string;
  uint32_t stringLength;
  uint16_t const *clusterMap;
  uint32_t textPosition;
} DWRITE_GLYPH_RUN_DESCRIPTION;

typedef uint32_t DWRITE_MEASURING_MODE;

typedef struct {
  float width;
  float thickness;
  float offset;
  float runHeight;
  DWRITE_READING_DIRECTION readingDirection;
  DWRITE_FLOW_DIRECTION flowDirection;
  Win_WCHAR const *localeName;
  DWRITE_MEASURING_MODE measuringMode;
} DWRITE_UNDERLINE;

typedef struct {
  float width;
  float thickness;
  float offset;
  DWRITE_READING_DIRECTION readingDirection;
  DWRITE_FLOW_DIRECTION flowDirection;
  Win_WCHAR const *localeName;
  DWRITE_MEASURING_MODE measuringMode;
} DWRITE_STRIKETHROUGH;

typedef struct {
  uint32_t startPosition;
  uint32_t length;
} DWRITE_TEXT_RANGE;

typedef struct {
  DWRITE_FONT_FEATURE_TAG nameTag;
  uint32_t parameter;
} DWRITE_FONT_FEATURE;

typedef struct {
  uint32_t length;
  uint32_t trailingWhitespaceLength;
  uint32_t newlineLength;
  float height;
  float baseline;
  int32_t isTrimmed;
} DWRITE_LINE_METRICS;

typedef struct {
  float left;
  float top;
  float width;
  float widthIncludingTrailingWhitespace;
  float height;
  float layoutWidth;
  float layoutHeight;
  uint32_t maxBidiReorderingDepth;
  uint32_t lineCount;
} DWRITE_TEXT_METRICS;

typedef struct {
  float width;
  uint16_t length;
  uint16_t canWrapLineAfter : 1;
  uint16_t isWhitespace : 1;
  uint16_t isNewline : 1;
  uint16_t isSoftHyphen : 1;
  uint16_t isRightToLeft : 1;
  uint16_t padding : 11;
} DWRITE_CLUSTER_METRICS;

typedef struct {
  uint32_t textPosition;
  uint32_t length;
  float left;
  float top;
  float width;
  float height;
  uint32_t bidiLevel;
  int32_t isText;
  int32_t isTrimmed;
} DWRITE_HIT_TEST_METRICS;

typedef struct IDWriteFontFace IDWriteFontFace;

typedef struct DWRITE_GLYPH_RUN {
  IDWriteFontFace *fontFace;
  float fontEmSize;
  uint32_t glyphCount;
  uint16_t const *glyphIndices;
  float const *glyphAdvances;
  DWRITE_GLYPH_OFFSET const *glyphOffsets;
  int32_t isSideways;
  uint32_t bidiLevel;
} DWRITE_GLYPH_RUN;

typedef struct {
  uint16_t script;
  DWRITE_SCRIPT_SHAPES shapes;
} DWRITE_SCRIPT_ANALYSIS;

typedef struct {
  uint8_t breakConditionBefore : 2;
  uint8_t breakConditionAfter : 2;
  uint8_t isWhitespace : 1;
  uint8_t isSoftHyphen : 1;
  uint8_t padding : 2;
} DWRITE_LINE_BREAKPOINT;

typedef struct {
  DWRITE_FONT_FEATURE *features;
  uint32_t featureCount;
} DWRITE_TYPOGRAPHIC_FEATURES;

typedef struct {
  uint16_t isShapedAlone : 1;
  uint16_t reserved1 : 1;
  uint16_t canBreakShapingAfter : 1;
  uint16_t reserved : 13;
} DWRITE_SHAPING_TEXT_PROPERTIES;

typedef struct {
  uint16_t justification : 4;
  uint16_t isClusterStart : 1;
  uint16_t isDiacritic : 1;
  uint16_t isZeroWidthSpace : 1;
  uint16_t reserved : 9;
} DWRITE_SHAPING_GLYPH_PROPERTIES;

DECLARE_INTERFACE(IDWriteLocalizedStrings, 0x08256209099a4b34, 0xb86dc22b110e7771, Win_IUnknown);
struct {
  uint32_t(COMCALL *GetCount)(IDWriteLocalizedStrings *self);
  Win_HRESULT(COMCALL *FindLocaleName)(IDWriteLocalizedStrings *self, Win_WCHAR const *localeName, uint32_t *index, int32_t *exists);
  Win_HRESULT(COMCALL *GetLocaleNameLength)(IDWriteLocalizedStrings *self, uint32_t index, uint32_t *length);
  Win_HRESULT(COMCALL *GetLocaleName)(IDWriteLocalizedStrings *self, uint32_t index, Win_WCHAR *localeName, uint32_t size);
  Win_HRESULT(COMCALL *GetStringLength)(IDWriteLocalizedStrings *self, uint32_t index, uint32_t *length);
  Win_HRESULT(COMCALL *GetString)(IDWriteLocalizedStrings *self, uint32_t index, Win_WCHAR *stringBuffer, uint32_t size);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(IDWriteRenderingParams, 0x2f0da53a2add47cd, 0x82eed9ec34688e75, Win_IUnknown);
struct {
  float(COMCALL *GetGamma)(IDWriteRenderingParams *self);
  float(COMCALL *GetEnhancedContrast)(IDWriteRenderingParams *self);
  float(COMCALL *GetClearTypeLevel)(IDWriteRenderingParams *self);
  DWRITE_PIXEL_GEOMETRY(COMCALL *GetPixelGeometry)(IDWriteRenderingParams *self);
  DWRITE_RENDERING_MODE(COMCALL *GetRenderingMode)(IDWriteRenderingParams *self);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(IDWritePixelSnapping, 0xeaf3a2daecf44d24, 0xb644b34f6842024b, Win_IUnknown);
struct {
  Win_HRESULT(COMCALL *IsPixelSnappingDisabled)(IDWritePixelSnapping *self, void *clientDrawingContext, int32_t *isDisabled);
  Win_HRESULT(COMCALL *GetCurrentTransform)(IDWritePixelSnapping *self, void *clientDrawingContext, DWRITE_MATRIX *transform);
  Win_HRESULT(COMCALL *GetPixelsPerDip)(IDWritePixelSnapping *self, void *clientDrawingContext, float *pixelsPerDip);
};
DECLARE_INTERFACE_END;

typedef struct IDWriteTextRenderer IDWriteTextRenderer;

DECLARE_INTERFACE(IDWriteInlineObject, 0x8339FDE3106F47ab, 0x83731C6295EB10B3, Win_IUnknown);
struct {
  Win_HRESULT(COMCALL *Draw)(IDWriteInlineObject *self, void *clientDrawingContext, IDWriteTextRenderer *renderer, float originX, float originY,
                             int32_t isSideways, int32_t isRightToLeft, Win_IUnknown *clientDrawingEffect);
  Win_HRESULT(COMCALL *GetMetrics)(IDWriteInlineObject *self, DWRITE_INLINE_OBJECT_METRICS *metrics);
  Win_HRESULT(COMCALL *GetOverhangMetrics)(IDWriteInlineObject *self, DWRITE_OVERHANG_METRICS *overhangs);
  Win_HRESULT(COMCALL *GetBreakConditions)(IDWriteInlineObject *self, DWRITE_BREAK_CONDITION *breakConditionBefore,
                                           DWRITE_BREAK_CONDITION *breakConditionAfter);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(IDWriteTextRenderer, 0xef8a81355cc645fe, 0x8825c5a0724eb819, IDWritePixelSnapping);
struct {
  Win_HRESULT(COMCALL *DrawGlyphRun)(IDWriteTextRenderer *self, void *clientDrawingContext, float baselineOriginX, float baselineOriginY,
                                     DWRITE_MEASURING_MODE measuringMode, DWRITE_GLYPH_RUN const *glyphRun,
                                     DWRITE_GLYPH_RUN_DESCRIPTION const *glyphRunDescription, Win_IUnknown *clientDrawingEffect);
  Win_HRESULT(COMCALL *DrawUnderline)(IDWriteTextRenderer *self, void *clientDrawingContext, float baselineOriginX, float baselineOriginY,
                                      DWRITE_UNDERLINE const *underline, Win_IUnknown *clientDrawingEffect);
  Win_HRESULT(COMCALL *DrawStrikethrough)(IDWriteTextRenderer *self, void *clientDrawingContext, float baselineOriginX, float baselineOriginY,
                                          DWRITE_STRIKETHROUGH const *strikethrough, Win_IUnknown *clientDrawingEffect);
  Win_HRESULT(COMCALL *DrawInlineObject)(IDWriteTextRenderer *self, void *clientDrawingContext, float originX, float originY, IDWriteInlineObject *inlineObject,
                                         int32_t isSideways, int32_t isRightToLeft, Win_IUnknown *clientDrawingEffect);
};
DECLARE_INTERFACE_END;

typedef struct IDWriteFontCollection IDWriteFontCollection;
typedef struct IDWriteFont IDWriteFont;

DECLARE_INTERFACE(IDWriteFontList, 0x1a0d84381d974ec1, 0xaef9a2fb86ed6acb, Win_IUnknown);
struct {
  Win_HRESULT(COMCALL *GetFontCollection)(IDWriteFontList *self, IDWriteFontCollection **fontCollection);
  uint32_t(COMCALL *GetFontCount)(IDWriteFontList *self);
  Win_HRESULT(COMCALL *GetFont)(IDWriteFontList *self, uint32_t index, IDWriteFont **font);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(IDWriteFontFamily, 0xda20d8ef812a4c43, 0x980262ec4abd7add, IDWriteFontList);
struct {
  Win_HRESULT(COMCALL *GetFamilyNames)(IDWriteFontFamily *self, IDWriteLocalizedStrings **names);
  Win_HRESULT(COMCALL *GetFirstMatchingFont)(IDWriteFontFamily *self, DWRITE_FONT_WEIGHT weight, DWRITE_FONT_STRETCH stretch, DWRITE_FONT_STYLE style,
                                             IDWriteFont **matchingFont);
  Win_HRESULT(COMCALL *GetMatchingFonts)(IDWriteFontFamily *self, DWRITE_FONT_WEIGHT weight, DWRITE_FONT_STRETCH stretch, DWRITE_FONT_STYLE style,
                                         IDWriteFontList **matchingFonts);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(IDWriteFontFileStream, 0x6d4865fe0ab84d91, 0x8f625dd6be34a3e0, Win_IUnknown);
struct {
  Win_HRESULT(COMCALL *ReadFileFragment)(IDWriteFontFileStream *self, void const **fragmentStart, uint64_t fileOffset, uint64_t fragmentSize,
                                         void **fragmentContext);
  void(COMCALL *ReleaseFileFragment)(IDWriteFontFileStream *self, void *fragmentContext);
  Win_HRESULT(COMCALL *GetFileSize)(IDWriteFontFileStream *self, uint64_t *fileSize);
  Win_HRESULT(COMCALL *GetLastWriteTime)(IDWriteFontFileStream *self, uint64_t *lastWriteTime);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(IDWriteFontFileLoader, 0x727cad4ed6af4c9e, 0x8a08d695b11caa49, Win_IUnknown);
struct {
  Win_HRESULT(COMCALL *CreateStreamFromKey)(IDWriteFontFileLoader *self, void const *fontFileReferenceKey, uint32_t fontFileReferenceKeySize,
                                            IDWriteFontFileStream **fontFileStream);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(IDWriteFontFile, 0x739d886acef547dc, 0x87691a8b41bebbb0, Win_IUnknown);
struct {
  Win_HRESULT(COMCALL *GetReferenceKey)(IDWriteFontFile *self, void const **fontFileReferenceKey, uint32_t *fontFileReferenceKeySize);
  Win_HRESULT(COMCALL *GetLoader)(IDWriteFontFile *self, IDWriteFontFileLoader **fontFileLoader);
  Win_HRESULT(COMCALL *Analyze)(IDWriteFontFile *self, int32_t *isSupportedFontType, DWRITE_FONT_FILE_TYPE *fontFileType, DWRITE_FONT_FACE_TYPE *fontFaceType,
                                uint32_t *numberOfFaces);
};
DECLARE_INTERFACE_END;

typedef struct ID2D1SimplifiedGeometrySink IDWriteGeometrySink;

DECLARE_INTERFACE(IDWriteFontFace, 0x5f49804d70244d43, 0xbfa9d25984f53849, Win_IUnknown);
struct {
  DWRITE_FONT_FACE_TYPE(COMCALL *GetType)(IDWriteFontFace *self);
  Win_HRESULT(COMCALL *GetFiles)(IDWriteFontFace *self, uint32_t *numberOfFiles, IDWriteFontFile **fontFiles);
  uint32_t(COMCALL *GetIndex)(IDWriteFontFace *self);
  DWRITE_FONT_SIMULATIONS(COMCALL *GetSimulations)(IDWriteFontFace *self);
  int32_t(COMCALL *IsSymbolFont)(IDWriteFontFace *self);
  void(COMCALL *GetMetrics)(IDWriteFontFace *self, DWRITE_FONT_METRICS *fontFaceMetrics);
  uint16_t(COMCALL *GetGlyphCount)(IDWriteFontFace *self);
  Win_HRESULT(COMCALL *GetDesignGlyphMetrics)(IDWriteFontFace *self, uint16_t const *glyphIndices, uint32_t glyphCount, DWRITE_GLYPH_METRICS *glyphMetrics,
                                              int32_t isSideways);
  Win_HRESULT(COMCALL *GetGlyphIndices)(IDWriteFontFace *self, uint32_t const *codePoints, uint32_t codePointCount, uint16_t *glyphIndices);
  Win_HRESULT(COMCALL *TryGetFontTable)(IDWriteFontFace *self, uint32_t openTypeTableTag, const void **tableData, uint32_t *tableSize, void **tableContext,
                                        int32_t *exists);
  void(COMCALL *ReleaseFontTable)(IDWriteFontFace *self, void *tableContext);
  Win_HRESULT(COMCALL *GetGlyphRunOutline)(IDWriteFontFace *self, float emSize, uint16_t const *glyphIndices, float const *glyphAdvances,
                                           DWRITE_GLYPH_OFFSET const *glyphOffsets, uint32_t glyphCount, int32_t isSideways, int32_t isRightToLeft,
                                           IDWriteGeometrySink *geometrySink);
  Win_HRESULT(COMCALL *GetRecommendedRenderingMode)(IDWriteFontFace *self, float emSize, float pixelsPerDip, DWRITE_MEASURING_MODE measuringMode,
                                                    IDWriteRenderingParams *renderingParams, DWRITE_RENDERING_MODE *renderingMode);
  Win_HRESULT(COMCALL *GetGdiCompatibleMetrics)(IDWriteFontFace *self, float emSize, float pixelsPerDip, DWRITE_MATRIX const *transform,
                                                DWRITE_FONT_METRICS *fontFaceMetrics);
  Win_HRESULT(COMCALL *GetGdiCompatibleGlyphMetrics)(IDWriteFontFace *self, float emSize, float pixelsPerDip, DWRITE_MATRIX const *transform,
                                                     int32_t useGdiNatural, uint16_t const *glyphIndices, uint32_t glyphCount,
                                                     DWRITE_GLYPH_METRICS *glyphMetrics, int32_t isSideways);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(IDWriteFont, 0xacd166968c144f5d, 0x877efe3fc1d32737, Win_IUnknown);
struct {
  Win_HRESULT(COMCALL *GetFontFamily)(IDWriteFont *self, IDWriteFontFamily **fontFamily);
  DWRITE_FONT_WEIGHT(COMCALL *GetWeight)(IDWriteFont *self);
  DWRITE_FONT_STRETCH(COMCALL *GetStretch)(IDWriteFont *self);
  DWRITE_FONT_STYLE(COMCALL *GetStyle)(IDWriteFont *self);
  int32_t(COMCALL *IsSymbolFont)(IDWriteFont *self);
  Win_HRESULT(COMCALL *GetFaceNames)(IDWriteFont *self, IDWriteLocalizedStrings **names);
  Win_HRESULT(COMCALL *GetInformationalStrings)(IDWriteFont *self, DWRITE_INFORMATIONAL_STRING_ID informationalStringID,
                                                IDWriteLocalizedStrings **informationalStrings, int32_t *exists);
  DWRITE_FONT_SIMULATIONS(COMCALL *GetSimulations)(IDWriteFont *self);
  void(COMCALL *GetMetrics)(IDWriteFont *self, DWRITE_FONT_METRICS *fontMetrics);
  Win_HRESULT(COMCALL *HasCharacter)(IDWriteFont *self, uint32_t unicodeValue, int32_t *exists);
  Win_HRESULT(COMCALL *CreateFontFace)(IDWriteFont *self, IDWriteFontFace **fontFace);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(IDWriteFontCollection, 0xa84cee023eea4eee, 0xa82787c1a02a0fcc, Win_IUnknown);
struct {

  uint32_t(COMCALL *GetFontFamilyCount)(IDWriteFontCollection *self);
  Win_HRESULT(COMCALL *GetFontFamily)(IDWriteFontCollection *self, uint32_t index, IDWriteFontFamily **fontFamily);
  Win_HRESULT(COMCALL *FindFamilyName)(IDWriteFontCollection *self, Win_WCHAR const *familyName, uint32_t *index, int32_t *exists);
  Win_HRESULT(COMCALL *GetFontFromFontFace)(IDWriteFontCollection *self, IDWriteFontFace *fontFace, IDWriteFont **font);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(IDWriteTextFormat, 0x9c90681831d74fd3, 0xa1517c5e225db55a, Win_IUnknown);
struct {
  Win_HRESULT(COMCALL *SetTextAlignment)(IDWriteTextFormat *self, DWRITE_TEXT_ALIGNMENT textAlignment);
  Win_HRESULT(COMCALL *SetParagraphAlignment)(IDWriteTextFormat *self, DWRITE_PARAGRAPH_ALIGNMENT paragraphAlignment);
  Win_HRESULT(COMCALL *SetWordWrapping)(IDWriteTextFormat *self, DWRITE_WORD_WRAPPING wordWrapping);
  Win_HRESULT(COMCALL *SetReadingDirection)(IDWriteTextFormat *self, DWRITE_READING_DIRECTION readingDirection);
  Win_HRESULT(COMCALL *SetFlowDirection)(IDWriteTextFormat *self, DWRITE_FLOW_DIRECTION flowDirection);
  Win_HRESULT(COMCALL *SetIncrementalTabStop)(IDWriteTextFormat *self, float incrementalTabStop);
  Win_HRESULT(COMCALL *SetTrimming)(IDWriteTextFormat *self, DWRITE_TRIMMING const *trimmingOptions, IDWriteInlineObject *trimmingSign);
  Win_HRESULT(COMCALL *SetLineSpacing)(IDWriteTextFormat *self, DWRITE_LINE_SPACING_METHOD lineSpacingMethod, float lineSpacing, float baseline);
  DWRITE_TEXT_ALIGNMENT(COMCALL *GetTextAlignment)(IDWriteTextFormat *self);
  DWRITE_PARAGRAPH_ALIGNMENT(COMCALL *GetParagraphAlignment)(IDWriteTextFormat *self);
  DWRITE_WORD_WRAPPING(COMCALL *GetWordWrapping)(IDWriteTextFormat *self);
  DWRITE_READING_DIRECTION(COMCALL *GetReadingDirection)(IDWriteTextFormat *self);
  DWRITE_FLOW_DIRECTION(COMCALL *GetFlowDirection)(IDWriteTextFormat *self);
  float(COMCALL *GetIncrementalTabStop)(IDWriteTextFormat *self);
  Win_HRESULT(COMCALL *GetTrimming)(IDWriteTextFormat *self, DWRITE_TRIMMING *trimmingOptions, IDWriteInlineObject **trimmingSign);
  Win_HRESULT(COMCALL *GetLineSpacing)(IDWriteTextFormat *self, DWRITE_LINE_SPACING_METHOD *lineSpacingMethod, float *lineSpacing, float *baseline);
  Win_HRESULT(COMCALL *GetFontCollection)(IDWriteTextFormat *self, IDWriteFontCollection **fontCollection);
  uint32_t(COMCALL *GetFontFamilyNameLength)(IDWriteTextFormat *self);
  Win_HRESULT(COMCALL *GetFontFamilyName)(IDWriteTextFormat *self, Win_WCHAR *fontFamilyName, uint32_t nameSize);
  DWRITE_FONT_WEIGHT(COMCALL *GetFontWeight)(IDWriteTextFormat *self);
  DWRITE_FONT_STYLE(COMCALL *GetFontStyle)(IDWriteTextFormat *self);
  DWRITE_FONT_STRETCH(COMCALL *GetFontStretch)(IDWriteTextFormat *self);
  float(COMCALL *GetFontSize)(IDWriteTextFormat *self);
  uint32_t(COMCALL *GetLocaleNameLength)(IDWriteTextFormat *self);
  Win_HRESULT(COMCALL *GetLocaleName)(IDWriteTextFormat *self, Win_WCHAR *localeName, uint32_t nameSize);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(IDWriteTypography, 0x55f1112b1dc24b3c, 0x9541f46894ed85b6, Win_IUnknown);
struct {
  Win_HRESULT(COMCALL *AddFontFeature)(IDWriteTypography *self, DWRITE_FONT_FEATURE fontFeature);
  uint32_t(COMCALL *GetFontFeatureCount)(IDWriteTypography *self);
  Win_HRESULT(COMCALL *GetFontFeature)(IDWriteTypography *self, uint32_t fontFeatureIndex, DWRITE_FONT_FEATURE *fontFeature);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(IDWriteTextLayout, 0x537370376d14410b, 0x9bfe0b182bb70961, IDWriteTextFormat);
struct {
  Win_HRESULT(COMCALL *SetMaxWidth)(IDWriteTextLayout *self, float maxWidth);
  Win_HRESULT(COMCALL *SetMaxHeight)(IDWriteTextLayout *self, float maxHeight);
  Win_HRESULT(COMCALL *SetFontCollection)(IDWriteTextLayout *self, IDWriteFontCollection *fontCollection, DWRITE_TEXT_RANGE textRange);
  Win_HRESULT(COMCALL *SetFontFamilyName)(IDWriteTextLayout *self, Win_WCHAR const *fontFamilyName, DWRITE_TEXT_RANGE textRange);
  Win_HRESULT(COMCALL *SetFontWeight)(IDWriteTextLayout *self, DWRITE_FONT_WEIGHT fontWeight, DWRITE_TEXT_RANGE textRange);
  Win_HRESULT(COMCALL *SetFontStyle)(IDWriteTextLayout *self, DWRITE_FONT_STYLE fontStyle, DWRITE_TEXT_RANGE textRange);
  Win_HRESULT(COMCALL *SetFontStretch)(IDWriteTextLayout *self, DWRITE_FONT_STRETCH fontStretch, DWRITE_TEXT_RANGE textRange);
  Win_HRESULT(COMCALL *SetFontSize)(IDWriteTextLayout *self, float fontSize, DWRITE_TEXT_RANGE textRange);
  Win_HRESULT(COMCALL *SetUnderline)(IDWriteTextLayout *self, int32_t hasUnderline, DWRITE_TEXT_RANGE textRange);
  Win_HRESULT(COMCALL *SetStrikethrough)(IDWriteTextLayout *self, int32_t hasStrikethrough, DWRITE_TEXT_RANGE textRange);
  Win_HRESULT(COMCALL *SetDrawingEffect)(IDWriteTextLayout *self, Win_IUnknown *drawingEffect, DWRITE_TEXT_RANGE textRange);
  Win_HRESULT(COMCALL *SetInlineObject)(IDWriteTextLayout *self, IDWriteInlineObject *inlineObject, DWRITE_TEXT_RANGE textRange);
  Win_HRESULT(COMCALL *SetTypography)(IDWriteTextLayout *self, IDWriteTypography *typography, DWRITE_TEXT_RANGE textRange);
  Win_HRESULT(COMCALL *SetLocaleName)(IDWriteTextLayout *self, Win_WCHAR const *localeName, DWRITE_TEXT_RANGE textRange);
  float(COMCALL *GetMaxWidth)(IDWriteTextLayout *self);
  float(COMCALL *GetMaxHeight)(IDWriteTextLayout *self);
  Win_HRESULT(COMCALL *GetFontCollection)(IDWriteTextLayout *self, uint32_t currentPosition, IDWriteFontCollection **fontCollection,
                                          DWRITE_TEXT_RANGE *textRange);
  Win_HRESULT(COMCALL *GetFontFamilyNameLength)(IDWriteTextLayout *self, uint32_t currentPosition, uint32_t *nameLength, DWRITE_TEXT_RANGE *textRange);
  Win_HRESULT(COMCALL *GetFontFamilyName)(IDWriteTextLayout *self, uint32_t currentPosition, Win_WCHAR *fontFamilyName, uint32_t nameSize,
                                          DWRITE_TEXT_RANGE *textRange);
  Win_HRESULT(COMCALL *GetFontWeight)(IDWriteTextLayout *self, uint32_t currentPosition, DWRITE_FONT_WEIGHT *fontWeight, DWRITE_TEXT_RANGE *textRange);
  Win_HRESULT(COMCALL *GetFontStyle)(IDWriteTextLayout *self, uint32_t currentPosition, DWRITE_FONT_STYLE *fontStyle, DWRITE_TEXT_RANGE *textRange);
  Win_HRESULT(COMCALL *GetFontStretch)(IDWriteTextLayout *self, uint32_t currentPosition, DWRITE_FONT_STRETCH *fontStretch, DWRITE_TEXT_RANGE *textRange);
  Win_HRESULT(COMCALL *GetFontSize)(IDWriteTextLayout *self, uint32_t currentPosition, float *fontSize, DWRITE_TEXT_RANGE *textRange);
  Win_HRESULT(COMCALL *GetUnderline)(IDWriteTextLayout *self, uint32_t currentPosition, int32_t *hasUnderline, DWRITE_TEXT_RANGE *textRange);
  Win_HRESULT(COMCALL *GetStrikethrough)(IDWriteTextLayout *self, uint32_t currentPosition, int32_t *hasStrikethrough, DWRITE_TEXT_RANGE *textRange);
  Win_HRESULT(COMCALL *GetDrawingEffect)(IDWriteTextLayout *self, uint32_t currentPosition, Win_IUnknown **drawingEffect, DWRITE_TEXT_RANGE *textRange);
  Win_HRESULT(COMCALL *GetInlineObject)(IDWriteTextLayout *self, uint32_t currentPosition, IDWriteInlineObject **inlineObject, DWRITE_TEXT_RANGE *textRange);
  Win_HRESULT(COMCALL *GetTypography)(IDWriteTextLayout *self, uint32_t currentPosition, IDWriteTypography **typography, DWRITE_TEXT_RANGE *textRange);
  Win_HRESULT(COMCALL *GetLocaleNameLength)(IDWriteTextLayout *self, uint32_t currentPosition, uint32_t *nameLength, DWRITE_TEXT_RANGE *textRange);
  Win_HRESULT(COMCALL *GetLocaleName)(IDWriteTextLayout *self, uint32_t currentPosition, Win_WCHAR *localeName, uint32_t nameSize,
                                      DWRITE_TEXT_RANGE *textRange);
  Win_HRESULT(COMCALL *Draw)(IDWriteTextLayout *self, void *clientDrawingContext, IDWriteTextRenderer *renderer, float originX, float originY);
  Win_HRESULT(COMCALL *GetLineMetrics)(IDWriteTextLayout *self, DWRITE_LINE_METRICS *lineMetrics, uint32_t maxLineCount, uint32_t *actualLineCount);
  Win_HRESULT(COMCALL *GetMetrics)(IDWriteTextLayout *self, DWRITE_TEXT_METRICS *textMetrics);
  Win_HRESULT(COMCALL *GetOverhangMetrics)(IDWriteTextLayout *self, DWRITE_OVERHANG_METRICS *overhangs);
  Win_HRESULT(COMCALL *GetClusterMetrics)(IDWriteTextLayout *self, DWRITE_CLUSTER_METRICS *clusterMetrics, uint32_t maxClusterCount,
                                          uint32_t *actualClusterCount);
  Win_HRESULT(COMCALL *DetermineMinWidth)(IDWriteTextLayout *self, float *minWidth);
  Win_HRESULT(COMCALL *HitTestPoint)(IDWriteTextLayout *self, float pointX, float pointY, int32_t *isTrailingHit, int32_t *isInside,
                                     DWRITE_HIT_TEST_METRICS *hitTestMetrics);
  Win_HRESULT(COMCALL *HitTestTextPosition)(IDWriteTextLayout *self, uint32_t textPosition, int32_t isTrailingHit, float *pointX, float *pointY,
                                            DWRITE_HIT_TEST_METRICS *hitTestMetrics);
  Win_HRESULT(COMCALL *HitTestTextRange)(IDWriteTextLayout *self, uint32_t textPosition, uint32_t textLength, float originX, float originY,
                                         DWRITE_HIT_TEST_METRICS *hitTestMetrics, uint32_t maxHitTestMetricsCount, uint32_t *actualHitTestMetricsCount);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(IDWriteFontFileEnumerator, 0x727550495ff7435d, 0x83484be97cfa6c7c, Win_IUnknown);
struct {
  Win_HRESULT(COMCALL *MoveNext)(IDWriteFontFileEnumerator *self, int32_t *hasCurrentFile);
  Win_HRESULT(COMCALL *GetCurrentFontFile)(IDWriteFontFileEnumerator *self, IDWriteFontFile **fontFile);
};
DECLARE_INTERFACE_END;

typedef struct IDWriteFactory IDWriteFactory;
DECLARE_INTERFACE(IDWriteFontCollectionLoader, 0xcca920e452f0492b, 0xbfa829c72ee0a468, Win_IUnknown);
struct {
  Win_HRESULT(COMCALL *CreateEnumeratorFromKey)(IDWriteFontCollectionLoader *self, IDWriteFactory *factory, void const *collectionKey,
                                                uint32_t collectionKeySize, IDWriteFontFileEnumerator **fontFileEnumerator);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(IDWriteBitmapRenderTarget, 0x5e5a32a38dff4773, 0x9ff60696eab77267, Win_IUnknown);
struct {
  Win_HRESULT(COMCALL *DrawGlyphRun)(IDWriteBitmapRenderTarget *self, float baselineOriginX, float baselineOriginY, DWRITE_MEASURING_MODE measuringMode,
                                     DWRITE_GLYPH_RUN const *glyphRun, IDWriteRenderingParams *renderingParams, Win_COLORREF textColor, Win_RECT *blackBoxRect);
  Win_HDC(COMCALL *GetMemoryDC)(IDWriteBitmapRenderTarget *self);
  float(COMCALL *GetPixelsPerDip)(IDWriteBitmapRenderTarget *self);
  Win_HRESULT(COMCALL *SetPixelsPerDip)(IDWriteBitmapRenderTarget *self, float pixelsPerDip);
  Win_HRESULT(COMCALL *GetCurrentTransform)(IDWriteBitmapRenderTarget *self, DWRITE_MATRIX *transform);
  Win_HRESULT(COMCALL *SetCurrentTransform)(IDWriteBitmapRenderTarget *self, DWRITE_MATRIX const *transform);
  Win_HRESULT(COMCALL *GetSize)(IDWriteBitmapRenderTarget *self, Win_SIZE *size);
  Win_HRESULT(COMCALL *Resize)(IDWriteBitmapRenderTarget *self, uint32_t width, uint32_t height);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(IDWriteGdiInterop, 0x1edd949198534299, 0x898f6432983b6f3a, Win_IUnknown);
struct {
  Win_HRESULT(COMCALL *CreateFontFromLOGFONT)(IDWriteGdiInterop *self, Win_LOGFONTW const *logFont, IDWriteFont **font);
  Win_HRESULT(COMCALL *ConvertFontToLOGFONT)(IDWriteGdiInterop *self, IDWriteFont *font, Win_LOGFONTW *logFont, int32_t *isSystemFont);
  Win_HRESULT(COMCALL *ConvertFontFaceToLOGFONT)(IDWriteGdiInterop *self, IDWriteFontFace *font, Win_LOGFONTW *logFont);
  Win_HRESULT(COMCALL *CreateFontFaceFromHdc)(IDWriteGdiInterop *self, Win_HDC hdc, IDWriteFontFace **fontFace);
  Win_HRESULT(COMCALL *CreateBitmapRenderTarget)(IDWriteGdiInterop *self, Win_HDC hdc, uint32_t width, uint32_t height,
                                                 IDWriteBitmapRenderTarget **renderTarget);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(IDWriteNumberSubstitution, 0x14885CC9BAB04f90, 0xB6ED5C366A2CD03D, Win_IUnknown);
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(IDWriteTextAnalysisSource, 0x688e1a58509447c8, 0xadc8fbcea60ae92b, Win_IUnknown);
struct {
  Win_HRESULT(COMCALL *GetTextAtPosition)(IDWriteTextAnalysisSource *self, uint32_t textPosition, Win_WCHAR const **textString, uint32_t *textLength);
  Win_HRESULT(COMCALL *GetTextBeforePosition)(IDWriteTextAnalysisSource *self, uint32_t textPosition, Win_WCHAR const **textString, uint32_t *textLength);
  DWRITE_READING_DIRECTION(COMCALL *GetParagraphReadingDirection)(IDWriteTextAnalysisSource *self);
  Win_HRESULT(COMCALL *GetLocaleName)(IDWriteTextAnalysisSource *self, uint32_t textPosition, uint32_t *textLength, Win_WCHAR const **localeName);
  Win_HRESULT(COMCALL *GetNumberSubstitution)(IDWriteTextAnalysisSource *self, uint32_t textPosition, uint32_t *textLength,
                                              IDWriteNumberSubstitution **numberSubstitution);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(IDWriteTextAnalysisSink, 0x5810cd440ca04701, 0xb3fabec5182ae4f6, Win_IUnknown);
struct {
  Win_HRESULT(COMCALL *SetScriptAnalysis)(IDWriteTextAnalysisSink *self, uint32_t textPosition, uint32_t textLength,
                                          DWRITE_SCRIPT_ANALYSIS const *scriptAnalysis);
  Win_HRESULT(COMCALL *SetLineBreakpoints)(IDWriteTextAnalysisSink *self, uint32_t textPosition, uint32_t textLength,
                                           DWRITE_LINE_BREAKPOINT const *lineBreakpoints);
  Win_HRESULT(COMCALL *SetBidiLevel)(IDWriteTextAnalysisSink *self, uint32_t textPosition, uint32_t textLength, uint8_t explicitLevel, uint8_t resolvedLevel);
  Win_HRESULT(COMCALL *SetNumberSubstitution)(IDWriteTextAnalysisSink *self, uint32_t textPosition, uint32_t textLength,
                                              IDWriteNumberSubstitution *numberSubstitution);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(IDWriteTextAnalyzer, 0xb7e6163e7f4643b4, 0x84b3e4e6249c365d, Win_IUnknown);
struct {
  Win_HRESULT(COMCALL *AnalyzeScript)(IDWriteTextAnalyzer *self, IDWriteTextAnalysisSource *analysisSource, uint32_t textPosition, uint32_t textLength,
                                      IDWriteTextAnalysisSink *analysisSink);
  Win_HRESULT(COMCALL *AnalyzeBidi)(IDWriteTextAnalyzer *self, IDWriteTextAnalysisSource *analysisSource, uint32_t textPosition, uint32_t textLength,
                                    IDWriteTextAnalysisSink *analysisSink);
  Win_HRESULT(COMCALL *AnalyzeNumberSubstitution)(IDWriteTextAnalyzer *self, IDWriteTextAnalysisSource *analysisSource, uint32_t textPosition,
                                                  uint32_t textLength, IDWriteTextAnalysisSink *analysisSink);
  Win_HRESULT(COMCALL *AnalyzeLineBreakpoints)(IDWriteTextAnalyzer *self, IDWriteTextAnalysisSource *analysisSource, uint32_t textPosition, uint32_t textLength,
                                               IDWriteTextAnalysisSink *analysisSink);
  Win_HRESULT(COMCALL *GetGlyphs)(IDWriteTextAnalyzer *self, Win_WCHAR const *textString, uint32_t textLength, IDWriteFontFace *fontFace, int32_t isSideways,
                                  int32_t isRightToLeft, DWRITE_SCRIPT_ANALYSIS const *scriptAnalysis, Win_WCHAR const *localeName,
                                  IDWriteNumberSubstitution *numberSubstitution, DWRITE_TYPOGRAPHIC_FEATURES const **features,
                                  uint32_t const *featureRangeLengths, uint32_t featureRanges, uint32_t maxGlyphCount, uint16_t *clusterMap,
                                  DWRITE_SHAPING_TEXT_PROPERTIES *textProps, uint16_t *glyphIndices, DWRITE_SHAPING_GLYPH_PROPERTIES *glyphProps,
                                  uint32_t *actualGlyphCount);
  Win_HRESULT(COMCALL *GetGlyphPlacements)(IDWriteTextAnalyzer *self, Win_WCHAR const *textString, uint16_t const *clusterMap,
                                           DWRITE_SHAPING_TEXT_PROPERTIES *textProps, uint32_t textLength, uint16_t const *glyphIndices,
                                           DWRITE_SHAPING_GLYPH_PROPERTIES const *glyphProps, uint32_t glyphCount, IDWriteFontFace *fontFace, float fontEmSize,
                                           int32_t isSideways, int32_t isRightToLeft, DWRITE_SCRIPT_ANALYSIS const *scriptAnalysis, Win_WCHAR const *localeName,
                                           DWRITE_TYPOGRAPHIC_FEATURES const **features, uint32_t const *featureRangeLengths, uint32_t featureRanges,
                                           float *glyphAdvances, DWRITE_GLYPH_OFFSET *glyphOffsets);
  Win_HRESULT(COMCALL *GetGdiCompatibleGlyphPlacements)(IDWriteTextAnalyzer *self, Win_WCHAR const *textString, uint16_t const *clusterMap,
                                                        DWRITE_SHAPING_TEXT_PROPERTIES *textProps, uint32_t textLength, uint16_t const *glyphIndices,
                                                        DWRITE_SHAPING_GLYPH_PROPERTIES const *glyphProps, uint32_t glyphCount, IDWriteFontFace *fontFace,
                                                        float fontEmSize, float pixelsPerDip, DWRITE_MATRIX const *transform, int32_t useGdiNatural,
                                                        int32_t isSideways, int32_t isRightToLeft, DWRITE_SCRIPT_ANALYSIS const *scriptAnalysis,
                                                        Win_WCHAR const *localeName, DWRITE_TYPOGRAPHIC_FEATURES const **features,
                                                        uint32_t const *featureRangeLengths, uint32_t featureRanges, float *glyphAdvances,
                                                        DWRITE_GLYPH_OFFSET *glyphOffsets);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(IDWriteGlyphRunAnalysis, 0x7d97dbf7e08542d4, 0x81e36a883bded118, Win_IUnknown);
struct {
  Win_HRESULT(COMCALL *GetAlphaTextureBounds)(IDWriteGlyphRunAnalysis *self, DWRITE_TEXTURE_TYPE textureType, Win_RECT *textureBounds);
  Win_HRESULT(COMCALL *CreateAlphaTexture)(IDWriteGlyphRunAnalysis *self, DWRITE_TEXTURE_TYPE textureType, Win_RECT const *textureBounds, uint8_t *alphaValues,
                                           uint32_t bufferSize);
  Win_HRESULT(COMCALL *GetAlphaBlendParams)(IDWriteGlyphRunAnalysis *self, IDWriteRenderingParams *renderingParams, float *blendGamma,
                                            float *blendEnhancedContrast, float *blendClearTypeLevel);
};
DECLARE_INTERFACE_END;

DECLARE_INTERFACE(IDWriteFactory, 0xb859ee5ad8384b5b, 0xa2e81adc7d93db48, Win_IUnknown);
struct {
  Win_HRESULT(COMCALL *GetSystemFontCollection)(IDWriteFactory *self, IDWriteFontCollection **fontCollection, int32_t checkForUpdates);
  Win_HRESULT(COMCALL *CreateCustomFontCollection)(IDWriteFactory *self, IDWriteFontCollectionLoader *collectionLoader, void const *collectionKey,
                                                   uint32_t collectionKeySize, IDWriteFontCollection **fontCollection);
  Win_HRESULT(COMCALL *RegisterFontCollectionLoader)(IDWriteFactory *self, IDWriteFontCollectionLoader *fontCollectionLoader);
  Win_HRESULT(COMCALL *UnregisterFontCollectionLoader)(IDWriteFactory *self, IDWriteFontCollectionLoader *fontCollectionLoader);
  Win_HRESULT(COMCALL *CreateFontFileReference)(IDWriteFactory *self, Win_WCHAR const *filePath, Win_FILETIME const *lastWriteTime, IDWriteFontFile **fontFile);
  Win_HRESULT(COMCALL *CreateCustomFontFileReference)(IDWriteFactory *self, void const *fontFileReferenceKey, uint32_t fontFileReferenceKeySize,
                                                      IDWriteFontFileLoader *fontFileLoader, IDWriteFontFile **fontFile);
  Win_HRESULT(COMCALL *CreateFontFace)(IDWriteFactory *self, DWRITE_FONT_FACE_TYPE fontFaceType, uint32_t numberOfFiles, IDWriteFontFile *const *fontFiles,
                                       uint32_t faceIndex, DWRITE_FONT_SIMULATIONS fontFaceSimulationFlags, IDWriteFontFace **fontFace);
  Win_HRESULT(COMCALL *CreateRenderingParams)(IDWriteFactory *self, IDWriteRenderingParams **renderingParams);
  Win_HRESULT(COMCALL *CreateMonitorRenderingParams)(IDWriteFactory *self, Win_HMONITOR monitor, IDWriteRenderingParams **renderingParams);
  Win_HRESULT(COMCALL *CreateCustomRenderingParams)(IDWriteFactory *self, float gamma, float enhancedContrast, float clearTypeLevel,
                                                    DWRITE_PIXEL_GEOMETRY pixelGeometry, DWRITE_RENDERING_MODE renderingMode,
                                                    IDWriteRenderingParams **renderingParams);
  Win_HRESULT(COMCALL *RegisterFontFileLoader)(IDWriteFactory *self, IDWriteFontFileLoader *fontFileLoader);
  Win_HRESULT(COMCALL *UnregisterFontFileLoader)(IDWriteFactory *self, IDWriteFontFileLoader *fontFileLoader);
  Win_HRESULT(COMCALL *CreateTextFormat)(IDWriteFactory *self, Win_WCHAR const *fontFamilyName, IDWriteFontCollection *fontCollection,
                                         DWRITE_FONT_WEIGHT fontWeight, DWRITE_FONT_STYLE fontStyle, DWRITE_FONT_STRETCH fontStretch, float fontSize,
                                         Win_WCHAR const *localeName, IDWriteTextFormat **textFormat);
  Win_HRESULT(COMCALL *CreateTypography)(IDWriteFactory *self, IDWriteTypography **typography);
  Win_HRESULT(COMCALL *GetGdiInterop)(IDWriteFactory *self, IDWriteGdiInterop **gdiInterop);
  Win_HRESULT(COMCALL *CreateTextLayout)(IDWriteFactory *self, Win_WCHAR const *string, uint32_t stringLength, IDWriteTextFormat *textFormat, float maxWidth,
                                         float maxHeight, IDWriteTextLayout **textLayout);
  Win_HRESULT(COMCALL *CreateGdiCompatibleTextLayout)(IDWriteFactory *self, Win_WCHAR const *string, uint32_t stringLength, IDWriteTextFormat *textFormat,
                                                      float layoutWidth, float layoutHeight, float pixelsPerDip, DWRITE_MATRIX const *transform,
                                                      int32_t useGdiNatural, IDWriteTextLayout **textLayout);
  Win_HRESULT(COMCALL *CreateEllipsisTrimmingSign)(IDWriteFactory *self, IDWriteTextFormat *textFormat, IDWriteInlineObject **trimmingSign);
  Win_HRESULT(COMCALL *CreateTextAnalyzer)(IDWriteFactory *self, IDWriteTextAnalyzer **textAnalyzer);
  Win_HRESULT(COMCALL *CreateNumberSubstitution)(IDWriteFactory *self, DWRITE_NUMBER_SUBSTITUTION_METHOD substitutionMethod, Win_WCHAR const *localeName,
                                                 int32_t ignoreUserOverride, IDWriteNumberSubstitution **numberSubstitution);
  Win_HRESULT(COMCALL *CreateGlyphRunAnalysis)(IDWriteFactory *self, DWRITE_GLYPH_RUN const *glyphRun, float pixelsPerDip, DWRITE_MATRIX const *transform,
                                               DWRITE_RENDERING_MODE renderingMode, DWRITE_MEASURING_MODE measuringMode, float baselineOriginX,
                                               float baselineOriginY, IDWriteGlyphRunAnalysis **glyphRunAnalysis);
};
DECLARE_INTERFACE_END;

EXTERN Win_HRESULT(STDCALL *DWriteCreateFactory)(DWRITE_FACTORY_TYPE factoryType, const Uuid *const riid, void **ppIFactory);

#endif