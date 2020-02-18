#include "Animateable.h"

using namespace ThorsAnvil::ThorsUI;

void Animateable::drawAnimation(wxDC& dc) const
{
    draw(dc);
}

void Animateable::animateOneStep()
{
    std::unique_ptr<wxDC> dc = animationDC();
    if (animateStep == 0)
    {
        animateReset(*dc);
    }
    animationStep(*dc);
}

void Animateable::animateReset(wxDC& dc)
{
    animateStep=0;
    animateResetDo(dc);
}

void Animateable::animationStep(wxDC& dc)
{
    animationStepDo(dc, animateStep);
    int maxStep = animationMaxStep();
    animateStep = maxStep == 0 ? 0 : (animateStep + 1) % maxStep;
}

void Animateable::animateOneLoop(wxDC& dc)
{
    animateStep = 0;
    do
    {
        animationStep(dc);
    }
    while (animateStep != 0);
}
