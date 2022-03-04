#pragma once
class Student {

	static constexpr int MAXSTUDENTNAME = 100;
	char name[MAXSTUDENTNAME] = {};
	float englishMark = 0.0f, mathMark = 0.0f, historyMark = 0.0f;
	

public : 

	void setName(const char *);
	void setEnglish(float);
	void setMath(float);
	void setHistory(float);
	
	const char* getName();
	float getEnglish();
	float getMath();
	float getHistory();
	float getAvg();

};