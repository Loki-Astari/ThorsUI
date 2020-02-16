#include "UIPanelAnimateable.h"

using namespace ThorsAnvil::ThorsUI;

PanelAnimateable::PanelAnimateable(wxWindow* parent, Animateable& drawing)
    : PanelDrawable(parent, drawing)
    , drawing(drawing)
{
    advance();
}

void PanelAnimateable::advance()
{
    wxClientDC      dc(this);
    drawing.animationStep();
    drawing.draw(dc);
}
