#ifndef THORSANVIL_THORSUI_UI_PANEL_ANIMATEABLE_H
#define THORSANVIL_THORSUI_UI_PANEL_ANIMATEABLE_H

#include "UIPanelDrawable.h"
#include "Animateable.h"

namespace ThorsAnvil
{
    namespace ThorsUI
    {

class PanelAnimateable: public PanelDrawable
{
    Animateable&         drawing;

    public:
        PanelAnimateable(wxWindow* parent, Animateable& drawing);

        void advance();
    private:
        DECLARE_EVENT_TABLE()
};

    }
}

#endif
