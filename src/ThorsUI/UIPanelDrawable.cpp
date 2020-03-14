#include "UIPanelDrawable.h"

using namespace ThorsAnvil::ThorsUI;

BEGIN_EVENT_TABLE(PanelDrawable, wxPanel)
    EVT_PAINT(PanelDrawable::onPaint)
END_EVENT_TABLE()

PanelDrawable::PanelDrawable(wxWindow* parent, Drawable& drawing)
    : wxPanel(parent, wxID_ANY, wxPoint{0, 0}, drawing.getSize())
    , drawing(drawing)
{
    drawing.addDisplayer(*this);
}

PanelDrawable::~PanelDrawable()
{
    drawing.remDisplayer(*this);
}

void PanelDrawable::onPaint(wxPaintEvent& /*event*/)
{
    wxPaintDC       dc(this);
    drawing.draw(dc);
}

wxSize PanelDrawable::GetEffectiveMinSize() const
{
    return drawing.getSize();
}
