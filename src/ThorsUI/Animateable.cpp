#include "Animateable.h"

using namespace ThorsAnvil::ThorsUI;

/*
 * The generic use case for animation involves the calling of
 *   1. animateOneStep()        followed by a call to
 *   2. Refresh()               this will result in a call to
 *   3. draw()                  which for Animatable objects (see draw function here) calls
 *   4. drawAnimation()
 *
 * drawAnimation() uses `animateStep - 1` as the previous call to animateOneStep()
 * is done the animation for step `animateStep` but then incremented the variable `animateStep`
 * so have worked out the details for the previous step.
 *
 * If you examine the function animationStep() you will see that we allow incrementing of
 * `animateStep` up to the max value but make sure it resets to zero before actual use.
 * This means the animation step range is [0 .. max) (note max not includes). When called via
 * animationStep() we pass the current value as that is the value we are generating the
 * animation for while draw() uses the value `animateStep - 1` as we want to draw the value
 * we have already done the calculations for.
 *
 * I hope that was clear?
 */
void Animateable::draw(wxDC& dc) const
{
    drawAnimation(dc, animateStep - 1);
}

void Animateable::animateOneStep()
{
    std::unique_ptr<wxDC> dc = animationDC();
    if (animateStep == 0 || animateStep >= animationMaxStep())
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
    int maxStep = animationMaxStep();
    if (animateStep >= maxStep)
    {
        animateStep = 0;
    }
    animationStepDo(dc, animateStep);
    ++animateStep;
}

void Animateable::animateOneLoop(wxDC& dc, bool reset)
{
    int maxStep = animationMaxStep();
    animateStep = 0;
    if (reset)
    {
        animateReset(dc);
    }
    do
    {
        animationStep(dc);
    }
    while (animateStep < maxStep);
}

std::unique_ptr<wxDC> Animateable::animationDC()
{
    return std::unique_ptr<wxDC>(nullptr);
}

void Animateable::animateResetDo(wxDC& /*dc*/)
{}

void Animateable::animationStepDo(wxDC& /*dc*/, int /*step*/)
{}

int Animateable::animationMaxStep() const
{
    return 0;
}
