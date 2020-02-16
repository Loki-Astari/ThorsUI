#ifndef THORSANVIL_VALKYRIE_UI_PANEL_ANIMATEABLE_STEPER_H
#define THORSANVIL_VALKYRIE_UI_PANEL_ANIMATEABLE_STEPER_H

#include "UIPanelAnimateable.h"

namespace ThorsAnvil
{
    namespace ThorsUI
    {

class PanelAnimateableSteper: public PanelAnimateable
{
    public:
        PanelAnimateableSteper(wxWindow* parent, Animateable& drawing);
        void onDoubleClick(wxMouseEvent& event);
    private:
        DECLARE_EVENT_TABLE()
};

    }
}

#endif
