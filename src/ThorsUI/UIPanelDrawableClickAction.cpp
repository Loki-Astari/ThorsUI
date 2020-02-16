#include "UIPanelDrawableClickAction.h"

using namespace ThorsAnvil::ThorsUI;

BEGIN_EVENT_TABLE(PanelDrawableClickAction, wxPanel)
    EVT_LEFT_DCLICK(PanelDrawableClickAction::onDoubleClick)
END_EVENT_TABLE()

PanelDrawableClickAction::PanelDrawableClickAction(wxWindow* parent, Drawable& drawing, Action&& action)
    : PanelDrawable(parent, drawing)
    , clickAction(std::move(action))
{}

void PanelDrawableClickAction::onDoubleClick(wxMouseEvent& /*event*/)
{
    clickAction(*this);
}
