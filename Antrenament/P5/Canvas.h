//
// Created by alexandru on 11.04.2022.
//

#ifndef P5_CANVAS_H
#define P5_CANVAS_H


#include <map>
#include <cstring>
#include "IPainter.h"
class Canvas {
    std::map<const char*, IPainter*> h;
    char **grid;
public:
    Canvas(int width, int height);
    void AddPainter(const char *_name, IPainter *p);
};


#endif //P5_CANVAS_H
