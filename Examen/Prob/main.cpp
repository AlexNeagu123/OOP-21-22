#include <iostream>
#include "Phrase.h"
using namespace std;
int main() {
    Phrase p = "I   have   POO   examination   today in C++ ";
    std::cout << "Total words: " << (int)p << "\n";
    for (int i = 0; i < (int)p; i++)
    {
        std::cout << "Word[" << i << "] = " << p[i] << "\n";
    }
    std::cout << "Letter 'a' is present in word: '" << p[3] << "' for " << p.CountLetter(3, 'a') << " times\n";
    std::cout << "Letter 'a' is present in the phrase for " << p.CountLetter('a') << " times\n";
    std::cout << "Longest word is: " << p.GetLongestWord() << "\n";
    std::cout << "Total vowels: " << p.CountVowels() << "\n";
    Phrase p2 = "Hello";
    std::cout << "Words in p2: " << (int)p2 << "\n";
    Phrase p3 = "  hello    world   ";
    std::cout << "Words in p3: " << (int)p3 << " [" << p3[0]<<" and "<< p3[1]<<"]\n";
    return 0;
}

