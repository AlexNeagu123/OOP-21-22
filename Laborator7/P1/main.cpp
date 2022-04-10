#include <iostream>
float operator "" _Fahrenheit(unsigned long long int x) {
    return ((float) x * 1.8f) + 32;
}
float operator "" _Kelvin(unsigned long long int x) {
    return (float) x + 273.15f;
}
int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    std::cout << a << ' ' << b << '\n';
    return 0;
}
