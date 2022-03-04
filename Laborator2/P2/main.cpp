#include<iostream>
#include "Student.h"
#include "GlobalFunctions.h"

using namespace GlobalFunctions;
using namespace std;

int main() {

	Student Laur;
	Laur.setName("Laur");
	cout << Laur.getName() << '\n';
	
	Laur.setEnglish(4.56);
	Laur.setHistory(9.76);
	Laur.setMath(2.54);
	
	cout << Laur.getAvg() << '\n';
	cout << Laur.getMath() << '\n';
	
	Student Alex;
	Alex.setName("Alex");
	Alex.setEnglish(7.56);
	Alex.setHistory(8.76);
	Alex.setMath(9.54);
	
	cout << SimpleCompare::byName(Laur, Alex) << '\n';
	cout << SimpleCompare::byAvg(Laur, Alex) << '\n';

}