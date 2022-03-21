#include <iostream>
#include "Sort.h"

int main() {

    Sort a("54,-12,59,10,-65");
    Sort(7, 1, 8, 6, 4, 3, 5, 10);

    a.Print();
    a.BubbleSort(true);
    a.Print();

    return 0;
}
