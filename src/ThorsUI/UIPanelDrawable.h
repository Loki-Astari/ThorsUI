#ifndef THORSANVIL_THORSUI_UI_PANEL_DRAWABLE_H
#define THORSANVIL_THORSUI_UI_PANEL_DRAWABLE_H

#include "Drawable.h"

namespace ThorsAnvil
{
    namespace ThorsUI
    {

class PanelDrawable: public wxPanel
{
    Drawable const&         drawing;

    public:
        PanelDrawable(wxWindow* parent, Drawable const& drawing);

        void onPaint(wxPaintEvent& event);
#pragma vera-pushoff
        virtual wxSize GetEffectiveMinSize()    const override;
#pragma vera-pop
    private:
        DECLARE_EVENT_TABLE()
};

    }
}

#endif
