#ifndef THORSANVIL_THORSUI_UI_DRAWABLE_LINE_GRAPH_H
#define THORSANVIL_THORSUI_UI_DRAWABLE_LINE_GRAPH_H

#include "Drawable.h"
#include <map>
#include <vector>
#include <initializer_list>

namespace ThorsAnvil
{
    namespace ThorsUI
    {

class UIDrawableLineGraph: public Drawable
{
    static constexpr int gap        = 6;
    static constexpr int lineLen    = 30;
    static const wxColor lineColors[];

    struct LineInfo
    {
        LineInfo(): visible(true), minPoint(0), maxPoint(0), lineColor(*wxBLACK) {}

        bool                visible;
        int                 minPoint;
        int                 maxPoint;
        wxColour            lineColor;
        std::vector<int>    points;
    };
    using LineMap   = std::map<std::string, LineInfo>;
    using LineValue = LineMap::value_type;

    LineMap     lines;
    int         maxPoint;
    int         minPoint;
    int         nextColour;
    int         pointCount;

    public:
        UIDrawableLineGraph();

        virtual void    draw(wxDC& dc)  const override;

        void    addPoints(std::string const& name, std::initializer_list<int> const& list);
        void    addPoint(std::string const& name, int point);
        void    setState(std::string const& name, bool vis)                 {lines[name].visible    = vis;}
        void    setState(std::string const& name, wxColour col)             {lines[name].lineColor  = col;}
        void    setState(std::string const& name, bool vis, wxColour col)   {setState(name, vis);setState(name, col);}
    private:
        using Area  = std::pair<wxPoint, wxSize>;
        using Spec  = std::tuple<wxSize, wxSize, int>;

        Spec    calcLegendStats(wxDC& dc) const;
        wxSize  drawLegend(wxDC& dc, int count, wxSize const& size, wxSize const& maxNameSize) const;
        Area    drawAxis(wxDC& dc, wxSize const& size, wxSize const& maxValueSize) const;
        void    drawGraphs(wxDC& dc, Area const& graphArea) const;

        void    rightjustifyText(wxDC& dc, std::string const& text, wxPoint const& topLeft, wxSize const& size) const;
        wxSize  getTextSize(wxDC& dc, std::string const& text) const;
};


    }
}

#endif
