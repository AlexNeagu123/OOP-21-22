#include "NumberList.h";
#include <iostream>
void NumberList::Init() {
	this->count = 0;
}
bool NumberList::Add(int x) {
	if (count >= 10) {
		return false;
	}
	numbers[count++] = x;
	return true;
}
void NumberList::Sort() {
	for (int i = 0; i < count; ++i) {
		for (int j = 0; j < count - 1; ++j) {
			if (numbers[j] > numbers[j + 1]) {
				std::swap(numbers[j], numbers[j + 1]);
			}
		}
	}
}
void NumberList::Print() {
	for (int i = 0; i < count; ++i) {
		std::cout << numbers[i] << ' ';
	}
	std::cout << '\n';
}