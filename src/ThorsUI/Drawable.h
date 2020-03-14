#ifndef THORSANVIL_THORSUI_DRAWABLE_H
#define THORSANVIL_THORSUI_DRAWABLE_H

#include <wx/wx.h>
#include <algorithm>

namespace ThorsAnvil
{
    namespace ThorsUI
    {

class PanelDrawable;
class Drawable
{
    std::vector<wxPanel*>     displayers;
    public:
        virtual ~Drawable() {}
        virtual void    draw(wxDC& dc)  const = 0;
        virtual wxSize  getSize()       const = 0;
                void    refresh()                   {for (auto& d: displayers){d->Refresh();}}

    private:
        friend class PanelDrawable;
        void addDisplayer(wxPanel& display)   {displayers.emplace_back(&display);}
        void remDisplayer(wxPanel& display)   {displayers.erase(std::find(std::begin(displayers), std::end(displayers), &display));}
};

    }
}

#endif
