#include "widget.h"

#include "color.h"
#include "text_font.h"
#include "window.h"

// 0x50EB1C
const float flt_50EB1C = 31.0;

// 0x50EB20
const float flt_50EB20 = 31.0;

// 0x66E6A0
int _updateRegions[32];

// 0x4B5A64
void _showRegion(int a1)
{
    // TODO: Incomplete.
}

// 0x4B5C24
int _update_widgets()
{
    for (int index = 0; index < 32; index++) {
        if (_updateRegions[index]) {
            _showRegion(_updateRegions[index]);
        }
    }

    return 1;
}

// 0x4B6120
int widgetGetFont()
{
    return gWidgetFont;
}

// 0x4B6128
int widgetSetFont(int a1)
{
    gWidgetFont = a1;
    fontSetCurrent(a1);
    return 1;
}

// 0x4B6160
int widgetGetTextFlags()
{
    return gWidgetTextFlags;
}

// 0x4B6168
int widgetSetTextFlags(int a1)
{
    gWidgetTextFlags = a1;
    return 1;
}

// 0x4B6174
unsigned char widgetGetTextColor()
{
    return _colorTable[_currentTextColorB | (_currentTextColorG << 5) | (_currentTextColorR << 10)];
}

// 0x4B6198
unsigned char widgetGetHighlightColor()
{
    return _colorTable[_currentHighlightColorB | (_currentHighlightColorG << 5) | (_currentHighlightColorR << 10)];
}

// 0x4B61BC
int widgetSetTextColor(float a1, float a2, float a3)
{
    _currentTextColorR = (int)(a1 * flt_50EB1C);
    _currentTextColorG = (int)(a2 * flt_50EB1C);
    _currentTextColorB = (int)(a3 * flt_50EB1C);

    return 1;
}

// 0x4B6208
int widgetSetHighlightColor(float a1, float a2, float a3)
{
    _currentHighlightColorR = (int)(a1 * flt_50EB20);
    _currentHighlightColorG = (int)(a2 * flt_50EB20);
    _currentHighlightColorB = (int)(a3 * flt_50EB20);

    return 1;
}
