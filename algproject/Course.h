#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string.h>

class course {
private:
	char* code;
	int credit;
	int attendee[80]; // no. of students in the course
public:
};

class course_code {
private:
	char course_initial[3]; // initial letters for the course
	char course_level; // alphabet for general education, 2 for basic classes, 3 for advanced classes
	int course_serial; // 001~999 
public:
	// constructor
	course_code(char* init, char lev, int ser) {
		strcpy(course_initial, init);
		course_level = lev;
		course_serial = ser;
	}
	char** code_to_str(course_code* cc, char* str[]);
};