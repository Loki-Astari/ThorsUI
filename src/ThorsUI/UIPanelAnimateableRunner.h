#ifndef THORSANVIL_THORSUI_UI_PANEL_ANIMATEABLE_RUNNER_H
#define THORSANVIL_THORSUI_UI_PANEL_ANIMATEABLE_RUNNER_H

#include "UIPanelAnimateable.h"

namespace ThorsAnvil
{
    namespace ThorsUI
    {

class PanelAnimateableRunner: public PanelAnimateable
{
    static constexpr int TIMER_ID   = 1000;

    wxTimer                 timer;

    public:
        PanelAnimateableRunner(wxWindow* parent, Animateable& drawing, int refreshTime);
        ~PanelAnimateableRunner();

        void onTimer(wxTimerEvent& event);
    private:
        DECLARE_EVENT_TABLE()
};

    }
}

#endif
