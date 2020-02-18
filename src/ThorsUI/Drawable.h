#ifndef THORSANVIL_THORSUI_DRAWABLE_H
#define THORSANVIL_THORSUI_DRAWABLE_H

#include <wx/wx.h>

namespace ThorsAnvil
{
    namespace ThorsUI
    {

class Drawable
{
    public:
        virtual ~Drawable() {}
        virtual void    draw(wxDC& dc)  const = 0;
        virtual wxSize  getSize()       const = 0;
};

    }
}

#endif
