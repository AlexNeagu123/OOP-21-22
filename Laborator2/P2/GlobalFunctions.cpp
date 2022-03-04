#include <iostream>
#include "GlobalFunctions.h"
int compareMark(float x, float y) {
	if (x > y) return 1;
	if (x < y) return -1;
	return 0;
}
int compareName(const char* a, const char* b) {
	int lenA = strlen(a);
	int lenB = strlen(b);
	for (int i = 0; i < std::min(lenA, lenB); ++i) {
		if (*(a + i) < *(b + i)) {
			return -1;
		}
		if (*(a + i) > *(b + i)) {
			return 1;
		}
	}
	if (lenA > lenB) return 1;
	if (lenA < lenB) return -1;
	return 0;
}
int GlobalFunctions::SimpleCompare::byMath(Student &a, Student &b) {
	return compareMark(a.getMath(), b.getMath());
}
int GlobalFunctions::SimpleCompare::byEnglish(Student& a, Student& b) {
	return compareMark(a.getEnglish(), b.getEnglish());
}
int GlobalFunctions::SimpleCompare::byHistory(Student& a, Student& b) {
	return compareMark(a.getHistory(), b.getHistory());
}
int GlobalFunctions::SimpleCompare::byAvg(Student& a, Student& b) {
	return compareMark(a.getAvg(), b.getAvg());
}
int GlobalFunctions::SimpleCompare::byName(Student& a, Student& b) {
	return compareName(a.getName(), b.getName());
}