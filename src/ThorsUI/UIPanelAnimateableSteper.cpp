#include "UIPanelAnimateableSteper.h"

using namespace ThorsAnvil::ThorsUI;

BEGIN_EVENT_TABLE(PanelAnimateableSteper, wxPanel)
    EVT_LEFT_DCLICK(PanelAnimateableSteper::onDoubleClick)
END_EVENT_TABLE()

PanelAnimateableSteper::PanelAnimateableSteper(wxWindow* parent, Animateable& drawing)
    : PanelAnimateable(parent, drawing)
{}

void PanelAnimateableSteper::onDoubleClick(wxMouseEvent& /*event*/)
{
    advance();
}
