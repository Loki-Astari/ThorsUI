#include "UIPanelDrawable.h"

using namespace ThorsAnvil::ThorsUI;

BEGIN_EVENT_TABLE(PanelDrawable, wxPanel)
    EVT_PAINT(PanelDrawable::onPaint)
END_EVENT_TABLE()

PanelDrawable::PanelDrawable(wxWindow* parent, Drawable const& drawing)
    : wxPanel(parent, wxID_ANY, wxPoint{0, 0}, drawing.getSize())
    , drawing(drawing)
{}

void PanelDrawable::onPaint(wxPaintEvent& /*event*/)
{
    wxPaintDC       dc(this);
    drawing.draw(dc);
}

wxSize PanelDrawable::GetEffectiveMinSize() const
{
    return drawing.getSize();
}
