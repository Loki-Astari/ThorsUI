#ifndef THORSANVIL_THORUI_UI_FRAME_SIMPLE_H
#define THORSANVIL_THORUI_UI_FRAME_SIMPLE_H

#include <wx/wx.h>
#include "ThorsUI/UIPanelDrawable.h"


namespace ThorsAnvil
{
    namespace ThorsUI
    {

template<typename T>
struct FrameSimplePanelTraits
{
    using PanelType = PanelDrawable;
};

class FrameSimple: public wxFrame
{
    struct PanelAdder
    {
        template<typename T>
        PanelAdder(wxFrame* parent, wxSizer* sizer, bool& first, T& drawable)
        {
            if (!first)
            {
                sizer->AddSpacer(10);
            }
            using PanelType = typename FrameSimplePanelTraits<T>::PanelType;
            wxPanel*    panel = new PanelType(parent, drawable);
            sizer->Add(panel, wxSizerFlags());
            first = false;
        }
    };
    public:
        template<typename... Args>
        FrameSimple(wxWindow* parent, wxWindowID id, wxString const& title, int orientation /* wxVERTICAL or wxHORIZONTAL*/, Args&... args)
            : FrameSimple(parent, id, title, new wxBoxSizer(orientation), args...)
        {}

        template<typename... Args>
        FrameSimple(wxWindow* parent, wxWindowID id, wxString const& title, wxSizer* sizer, Args&... args)
            : wxFrame(parent, id , title)
        {
            bool                        first  {true};
            std::initializer_list<int>  ignore {0, (PanelAdder(this, sizer, first, args), 0)...};
            (void)ignore;

            SetSizerAndFit(sizer);
        }
};

template<typename... Args>
FrameSimple* make_FrameSimpleHorz(wxWindow* parent, wxWindowID id, wxString const& title, Args&... args)
{
    return new FrameSimple(parent, id, title, wxHORIZONTAL, args...);
}

template<typename... Args>
FrameSimple* make_FrameSimpleVert(wxWindow* parent, wxWindowID id, wxString const& title, Args&... args)
{
    return new FrameSimple(parent, id, title, wxVERTICAL, args...);
}

template<typename... Args>
FrameSimple* make_FrameSimple(wxWindow* parent, wxWindowID id, wxString const& title, wxSizer* sizer, Args&... args)
{
    return new FrameSimple(parent, id, title, sizer, args...);
}

    }
}

#endif
