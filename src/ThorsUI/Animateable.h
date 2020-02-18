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
        virtual void    drawAnimation(wxDC& dc) const;

                void    animateOneStep();
                void    animateReset(wxDC& dc);
                void    animationStep(wxDC& dc);
                void    animateOneLoop(wxDC& dc);

        virtual std::unique_ptr<wxDC>   animationDC()       = 0;
        virtual void    animateResetDo(wxDC& dc)            = 0;
        virtual void    animationStepDo(wxDC& dc, int step) = 0;
        virtual int     animationMaxStep() const            = 0;
};

    }
}

#endif
