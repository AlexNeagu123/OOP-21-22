#include <iostream>
#include "NumberList.h"
using namespace std;

int main() {

    NumberList obj;
    obj.Init();
    obj.Add(4);
    obj.Add(2);
    obj.Add(10);
    obj.Add(1);
    obj.Print();
    obj.Sort();
    obj.Print();

    return 0;

}