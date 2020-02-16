#ifndef THORSANVIL_VALKYRIE_UI_PANEL_DRAWABLE_CLICK_ACTION_H
#define THORSANVIL_VALKYRIE_UI_PANEL_DRAWABLE_CLICK_ACTION_H

#include "UIPanelDrawable.h"

namespace ThorsAnvil
{
    namespace ThorsUI
    {

class PanelDrawableClickAction: public PanelDrawable
{
    public:
        using Action = std::function<void(PanelDrawableClickAction&)>;

        PanelDrawableClickAction(wxWindow* parent, Drawable& drawing, Action&& action);
        void onDoubleClick(wxMouseEvent& event);
    private:
        Action      clickAction;
        DECLARE_EVENT_TABLE()
};

    }
}

#endif
