#ifndef THORSANVIL_VALKYRIE_ANIMATEABLE_H
#define THORSANVIL_VALKYRIE_ANIMATEABLE_H

#include "Drawable.h"

namespace ThorsAnvil
{
    namespace ThorsUI
    {

class Animateable: public Drawable
{
    public:
        virtual void    animationStep() const = 0;
};

    }
}

#endif
