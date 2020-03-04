#ifndef THORSANVIL_THORSUI_UI_PANEL_SPRITE_RUNNER_H
#define THORSANVIL_THORSUI_UI_PANEL_SPRITE_RUNNER_H

#include "ThorsUI/Animateable.h"
#include "ThorsUI/UIPanelAnimateableRunner.h"
#include "ThorsUtil/Util.h"

namespace ThorsAnvil
{
    namespace ThorsUI
    {

using MoveAction = std::function<void(int step)>;
class PanelSpriteRunner: public ThorsUI::PanelAnimateableRunner, public ThorsUI::Animateable
{
    struct Sprite
    {
        MoveAction          moveAction;
        int                 maxStep;
        int                 currentStep;

        Sprite(MoveAction&& action, int maxStep);
    };

    std::vector<Sprite>             sprites;
    bool                            active;
    int                             maxSteps;

    public:
        PanelSpriteRunner(wxWindow* parent);
        void addSprite(int steps, MoveAction&& action);

    private:
        virtual wxSize  getSize()                           const override;
        virtual void    drawAnimation(wxDC& dc, int step)   const override;
        virtual int     animationMaxStep()                  const override;
        virtual void    animateResetDo(wxDC& dc)                  override;
        virtual void    animationStepDo(wxDC& dc, int step)       override;
        virtual void    animateResetActionDone(wxDC& dc);
};


    }
}

#endif
