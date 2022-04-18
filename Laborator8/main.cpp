#include <iostream>
#include <fstream>
#include <map>
#include <queue>
#include <string>
using namespace std;
ifstream inFile("/home/alexandru/Documents/OOP/Laborator8/input.in");
string separators = ".,?! ";
map<string, int> wordCount;
class Comparator {
public:
    bool operator() (const string &left, const string &right) const {
        int X = wordCount[left];
        int Y = wordCount[right];
        if(X == Y) {
            return left > right;
        }
        return X < Y;
    }
};
bool isSep(char ch) {
    return (separators.find(ch) != string::npos);
}
void splitInWords(string &phrase) {
    int len = (int) phrase.size();
    string currentWord;
    for(int i = 0; i < len; ++i) {
        if(isSep(phrase[i])) {
            if(!currentWord.empty()) {
                wordCount[currentWord]++;
                currentWord.clear();
            }
        } else {
            if (phrase[i] >= 'A' && phrase[i] <= 'Z') {
                phrase[i] += 32;
            }
            currentWord += phrase[i];
        }
    }
    if(!currentWord.empty()) {
        wordCount[currentWord]++;
    }
}
int main() {
    string phrase;
    getline(inFile, phrase);
    splitInWords(phrase);
    priority_queue<string, vector<string>, Comparator> wordOrder;
    for(map<string, int> :: iterator it = wordCount.begin(); it != wordCount.end(); it++) {
        wordOrder.push(it -> first);
    }
    while(!wordOrder.empty()) {
        string TOP = wordOrder.top();
        wordOrder.pop();
        cout << TOP << ' ' << wordCount[TOP] << '\n';
    }
    return 0;
}
