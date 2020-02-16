#include "UIPanelAnimateableRunner.h"

using namespace ThorsAnvil::ThorsUI;

BEGIN_EVENT_TABLE(PanelAnimateableRunner, wxPanel)
    EVT_TIMER(TIMER_ID, PanelAnimateableRunner::onTimer)
END_EVENT_TABLE()

PanelAnimateableRunner::PanelAnimateableRunner(wxWindow* parent, Animateable& drawing, int refreshTime)
    : PanelAnimateable(parent, drawing)
    , timer(this, TIMER_ID)
{
    timer.Start(refreshTime);
}

PanelAnimateableRunner::~PanelAnimateableRunner()
{
    timer.Stop();
}

void PanelAnimateableRunner::onTimer(wxTimerEvent& /*event*/)
{
    advance();
}
