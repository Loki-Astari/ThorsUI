#ifndef THORSANVIL_THORUI_UI_FRAME_SIMPLE_H
#define THORSANVIL_THORUI_UI_FRAME_SIMPLE_H

#include <wx/wx.h>
#include "ThorsUI/UIPanelDrawable.h"


namespace ThorsAnvil
{
    namespace ThorsUI
    {

template<typename T, int = 0>
struct FrameSimplePanelTraits
{
    using PanelType = PanelDrawable;
};

#if 0
template<typename D>
struct FrameSimplePanelTraits<D, 0>
{
    using PanelType = typename D::FrameSimplePanelType;
};
#endif

class SimplePanelBuilder
{
    public:
        virtual ~SimplePanelBuilder() {}
        virtual void addItems(wxWindow* panel, wxSizer* sizer) const= 0;
};

class FrameSimple: public wxFrame
{
    template<typename T, typename V = void>
    struct PanelAdder;

    template<typename T>
    struct PanelAdder<T, std::enable_if_t<std::is_base_of_v<Drawable, T>>>
    {
        PanelAdder(wxFrame* parent, wxSizer* sizer, bool& first, Drawable& drawable)
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

    template<typename T>
    struct PanelAdder<T, std::enable_if_t<std::is_base_of_v<SimplePanelBuilder, T>>>
    {
        PanelAdder(wxWindow* parent, wxSizer* sizer, bool& first, SimplePanelBuilder const& builder)
        {
            builder.addItems(parent, sizer);
            first = false;
        }
    };

    public:
        template<typename... Args>
        FrameSimple(wxWindow* parent, wxWindowID id, wxString const& title, int orientation /* wxVERTICAL or wxHORIZONTAL*/, wxPoint const& pos, Args&... args)
            : FrameSimple(parent, id, title, new wxBoxSizer(orientation), pos, args...)
        {}

        template<typename... Args>
        FrameSimple(wxWindow* parent, wxWindowID id, wxString const& title, wxSizer* sizer, wxPoint const& pos, Args&... args)
            : wxFrame(parent, id , title, pos)
        {
            bool                        first  {true};
            std::initializer_list<int>  ignore {0, (PanelAdder<Args>(this, sizer, first, args), 0)...};
            (void)ignore;

            SetSizerAndFit(sizer);
        }
};

template<typename... Args>
FrameSimple* make_FrameSimpleHorz(wxWindow* parent, wxWindowID id, wxString const& title, wxPoint const& pos, Args&... args)
{
    return new FrameSimple(parent, id, title, wxHORIZONTAL, pos, args...);
}

template<typename... Args>
FrameSimple* make_FrameSimpleVert(wxWindow* parent, wxWindowID id, wxString const& title, wxPoint const& pos, Args&... args)
{
    return new FrameSimple(parent, id, title, wxVERTICAL, pos, args...);
}

template<typename... Args>
FrameSimple* make_FrameSimple(wxWindow* parent, wxWindowID id, wxString const& title, wxSizer* sizer, wxPoint const& pos, Args&... args)
{
    return new FrameSimple(parent, id, title, sizer, pos, args...);
}

    }
}

#endif
