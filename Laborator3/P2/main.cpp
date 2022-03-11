#include <iostream>
#include "Canvas.h"
int main() {

    Canvas myCanvas(50, 50);
//    myCanvas.FillRect(2, 6, 7, 8, 'o');
//    myCanvas.DrawLine(0, 2, 33, 33, '*');
    myCanvas.DrawCircle(25, 25, 10, '*');
    myCanvas.DrawRect(2, 3, 10, 15, '*');
//    myCanvas.FillCircle(25, 25, 9, ' ');
    myCanvas.Print();

}
