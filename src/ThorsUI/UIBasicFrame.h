#ifndef THORSANVIL_THORSUI_UI_BASIC_FRAME_H
#define THORSANVIL_THORSUI_UI_BASIC_FRAME_H

#include <wx/wx.h>
#include <functional>

namespace ThorsAnvil
{
    namespace ThorsUI
    {

class BasicFrame;

using ContentInserter   = std::function<void(BasicFrame*,wxSizer&)>;
using ContentInserterCB = std::function<void()>;

class BasicFrame: public wxFrame
{
    ContentInserterCB   contentInserterCB;

    public:
        BasicFrame(wxString const& title, ContentInserter&& contentInserter);
        virtual bool Show(bool show = true) override;
};

template<typename Holder>
class BasicFrameWithHolder: public BasicFrame
{
    Holder      data;
    public:
        BasicFrameWithHolder(Holder&& data, wxString const& title, ContentInserter&& contentInserter)
            : BasicFrame(title, std::move(contentInserter))
            , data(std::move(data))
        {}

        Holder&         getData()       {return data;}
        Holder const&   getData() const {return data;}
};

    }
}

#endif
