#include "Student.h"
#include <iostream>
void Student::setName(const char* c) {
	int i = 0;
	while (*(c + i) != '\0') {
		name[i] = *(c + i);
		++i;
	}
	name[i] = '\0';
}
const char* Student::getName() {
	return name;
}
void Student::setEnglish(float mark) {
	if (mark >= 1.0 && mark <= 10.0) {
		englishMark = mark;
	}
}
void Student::setHistory(float mark) {
	if (mark >= 1.0 && mark <= 10.0) {
		historyMark = mark;
	}
}
void Student::setMath(float mark) {
	if (mark >= 1.0 && mark <= 10.0) {
		mathMark = mark;
	}
}
float Student::getEnglish() {
	return englishMark;
}
float Student::getMath() {
	return mathMark;
}
float Student::getHistory() {
	return historyMark;
}
float Student::getAvg() {
	return (englishMark + mathMark + historyMark) / 3.0;
}