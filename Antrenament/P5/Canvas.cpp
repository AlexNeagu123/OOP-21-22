//
// Created by alexandru on 11.04.2022.
//

#include "Canvas.h"
Canvas::Canvas(int width, int height) {
    grid = new char*[height];
    for(int i = 0; i < height; ++i) {
        grid[i] = new char[width];
    }
}

void Canvas::AddPainter(const char *_name, IPainter *p) {
    h[_name] = p;
}

