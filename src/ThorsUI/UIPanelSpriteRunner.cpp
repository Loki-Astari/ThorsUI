#include "UIPanelSpriteRunner.h"
#include "UIPanelDrawable.h"

using namespace ThorsAnvil::ThorsUI;

PanelSpriteRunner::PanelSpriteRunner(wxWindow* parent)
    : PanelAnimateableRunner(parent, *this, 40)
    , active(false)
    , maxSteps(0)
{}

void PanelSpriteRunner::addSprite(int steps, MoveAction&& action)
{
    sprites.emplace_back(std::move(action), steps);
    maxSteps = std::max(maxSteps, steps + 8);
    active = true;

}

wxSize PanelSpriteRunner::getSize() const
{
    return wxSize{0, 0};
}

void PanelSpriteRunner::drawAnimation(wxDC& /*dc*/, int /*step*/) const
{}

int PanelSpriteRunner::animationMaxStep() const
{
    // The maximum number of steps to get all sprites to where they are going.
    return maxSteps;
}

void PanelSpriteRunner::animateResetDo(wxDC& dc)
{
    // Called when all the sprites are complete.
    // Reset the animationMaxStep() so we don't do more animation and subsequent calls
    // animationResetDo() and animationStepDo() do nothing.a
    if (active)
    {
        active      = false;
        animateResetActionDone(dc);
    }
    maxSteps    = 0;
}

void PanelSpriteRunner::animationStepDo(wxDC& /*dc*/, int /*step*/)
{
    if (active)
    {
        for (auto& sprite: sprites)
        {
            sprite.moveAction(sprite.currentStep);
            ++sprite.currentStep;
        }

        sprites.erase(std::remove_if(std::begin(sprites), std::end(sprites), [](Sprite const& s){return s.currentStep == s.maxStep;}), std::end(sprites));
    }
}

void PanelSpriteRunner::animateResetActionDone(wxDC& /*dc*/)
{
    /* Do Nothing by default. */
}

PanelSpriteRunner::Sprite::Sprite(MoveAction&& action, int maxStep)
    : moveAction(std::move(action))
    , maxStep(maxStep)
    , currentStep(0)
{}
