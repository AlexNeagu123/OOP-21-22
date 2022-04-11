//
// Created by alexandru on 11.04.2022.
//

#ifndef P5_IPAINTER_H
#define P5_IPAINTER_H


#include "Canvas.h"

class IPainter {
public:
    virtual void Paint(Canvas *c, int v1, int v2 = 0, int v3 = 0, int v4 = 0, int v5 = 0) = 0;
};


#endif //P5_IPAINTER_H
