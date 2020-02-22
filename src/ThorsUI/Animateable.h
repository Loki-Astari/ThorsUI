#ifndef THORSANVIL_THORSUI_ANIMATEABLE_H
#define THORSANVIL_THORSUI_ANIMATEABLE_H

#include "Drawable.h"
#include <memory>

namespace ThorsAnvil
{
    namespace ThorsUI
    {

class Animateable: public Drawable
{
    int animateStep;
    public:
        Animateable()
            : animateStep(0)
        {}
        virtual void    draw(wxDC& dc) const;
        virtual void    drawAnimation(wxDC& dc, int step) const       = 0;

                void    animateOneStep();
                void    animateReset(wxDC& dc);
                void    animationStep(wxDC& dc);
                void    animateOneLoop(wxDC& dc, bool reset = true);

        virtual std::unique_ptr<wxDC>   animationDC();
        virtual void    animateResetDo(wxDC& dc);
        virtual void    animationStepDo(wxDC& dc, int step);
        virtual int     animationMaxStep() const;
};

    }
}

#endif
