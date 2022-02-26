#include<iostream>
using namespace std;

bool bigger(char* a, char* b) {
	for (int i = 0; i < strlen(a); ++i) {
		if (a[i] > b[i]) {
			return true;
		}
	}
	return false;
}

int main() {
	
	char c[100];
	scanf_s("%[^\n]s", c, 100);
	
	char sentence[100][100];
	int l = 0, w = 0;
	for (int i = 0; i < strlen(c); ++i) {
		if (c[i] == ' ' && w) {
			sentence[l][w] = '\0';
			l++;
			w = 0;
		}
		else if (c[i] != ' ') {
			sentence[l][w++] = c[i];
		}
	}
	if (w) {
		sentence[l][w] = '\0';
		l++;
	}
	for (int i = 0; i < l; ++i) {
		for (int j = 0; j < l - 1; ++j) {
			if(strlen(sentence[j]) < strlen(sentence[j + 1])) {
				swap(sentence[j], sentence[j + 1]);
			}
			else if (strlen(sentence[j]) == strlen(sentence[j + 1]) && bigger(sentence[j], sentence[j + 1])) {
				swap(sentence[j], sentence[j + 1]);
			}
		}
	}
	for (int i = 0; i < l; ++i) {
		printf("%s\n", sentence[i]);
	}

}