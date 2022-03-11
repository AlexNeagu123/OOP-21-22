//
// Created by alexandru on 3/8/22.
//
#include <iostream>
#include "Canvas.h"
using namespace std;

Canvas::Canvas(int _width, int _height) {
    height = _height;
    width = _width;
    grid = new char* [height];
    for(int i = 0; i < height; ++i) {
        grid[i] = new char[width];
    }
    for(int i = 0; i < height; ++i) {
        for(int j = 0; j < width; ++j) {
            grid[i][j] = 32;
        }
    }
}
void Canvas::Print() {
    for(int i = 0; i < height; ++i) {
        for(int j = 0; j < width; ++j) {
            cout << grid[i][j] << grid[i][j];
        }
        cout << '\n';
    }
}
void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    for(int i = 0; i < height; ++i) {
        for(int j = 0; j < width; ++j) {
            auto diff = (i - x) * (i - x) + (j - y) * (j - y) - ray * ray;
            if(diff >= -2 && diff <= 2) {
                grid[i][j] = ch;
            }
        }
    }
}
void Canvas::FillCircle(int x, int y, int ray, char ch) {
    for(int i = 0; i < height; ++i) {
        for(int j = 0; j < width; ++j) {
            if((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray) {
                grid[i][j] = ch;
            }
        }
    }
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    double slope = (double) (x2 - x1) / (y2 - y1);
    for(int col = y1; col <= y2; ++col) {
        int row = slope * (col - y1) + x1;
        grid[row][col] = ch;
    }
}
void Canvas::setPoint(int x, int y, char ch) {
    grid[x][y] = ch;
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    for(int i = 0; i < height; ++i) {
        for(int j = 0; j < width; ++j) {
            if(i >= top && i <= bottom && j >= left && j <= right) {
                if(i == top || i == bottom || j == left || j == right) {
                    grid[i][j] = ch;
                }
            }
        }
    }
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for(int i = 0; i < height; ++i) {
        for(int j = 0; j < width; ++j) {
            if(i >= top && i <= bottom && j >= left && j <= right) {
                grid[i][j] = ch;
            }
        }
    }
}
void Canvas::Clear() {
    for(int i = 0; i < height; ++i) {
        for(int j = 0; j < width; ++j) {
            grid[i][j] = 32;
        }
    }
}


