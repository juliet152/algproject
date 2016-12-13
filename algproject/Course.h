#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string.h>

class course {
private:
	double score;
	int credit;
	int attendee; // no. of students in the course
	char course_name[30];
	char course_initial[4]; // initial letters for the course
	char course_level; // alphabet for general education, 2 for basic classes, 3 for advanced classes
	int course_serial; // 001~999 
	char course_code[10];
public:
	//getter
	double get_score() { return score; }
	double get_average() { return score*credit; }
	int get_credit() { return credit; }
	int get_attendee() { return attendee; }
	char* get_course_name() { return course_name; }
	char* get_course_initial() { return course_initial; }
	char get_course_level() { return course_level; }
	int get_course_serial() { return course_serial; }
	char* get_course_code() { return course_code; }
	//setter
	void set_score(double d) { score = d; }
	void set_credit(int n) { credit = n; }
	void set_attendee(int n) { attendee = n; }
	void set_course_name(char * a) { strcpy(course_name, a); }
	void set_course_initial(char* a) { strcpy(course_initial, a); }
	void set_course_level(char a) { course_level = a; }
	void set_course_serial(int n) { course_serial = n; }
	void set_course_code()
	{
		char buff[10];
		strcpy(course_code, course_initial);
		strcat(course_code, &course_level);
		_itoa(course_serial, buff, 10);
		strcat(course_code, buff);
	}
};