#include "UIBasicFrame.h"

using namespace ThorsAnvil::ThorsUI;

BasicFrame::BasicFrame(wxString const& title, ContentInserter&& contentInserter)
    : wxFrame(nullptr, wxID_ANY, title)
    , contentInserterCB([cInserter = std::move(contentInserter), frame = this]()
    {
        wxSizer* sizer = frame->GetSizer();

        cInserter(frame, *sizer);

        sizer->Fit(frame);
        sizer->SetSizeHints(frame);
    })
{
    SetSizer(new wxBoxSizer(wxVERTICAL));
}

bool BasicFrame::Show(bool show)
{
    contentInserterCB();
    contentInserterCB = [](){};

    return wxFrame::Show(show);
}
