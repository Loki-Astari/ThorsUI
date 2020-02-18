#include "UIPanelAnimateable.h"

using namespace ThorsAnvil::ThorsUI;

BEGIN_EVENT_TABLE(PanelAnimateable, wxPanel)
    EVT_PAINT(PanelDrawable::onPaint)
END_EVENT_TABLE()

PanelAnimateable::PanelAnimateable(wxWindow* parent, Animateable& drawing)
    : PanelDrawable(parent, drawing)
    , drawing(drawing)
{
    advance();
}

void PanelAnimateable::advance()
{
    wxClientDC      dc(this);
    drawing.animateOneStep();
    drawing.draw(dc);
}
