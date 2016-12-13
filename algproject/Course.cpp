#include "Course.h"
#include <iostream>

void Course::Print()
{
	cout.precision(3);
	cout << code << ": " << name << "(" << credit << ", " << score <<")";
}
