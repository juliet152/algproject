#pragma once
#include <string>

using namespace std;

class Course {
private:
	double score;
	int credit;
	int attendee; // no. of students in the course
	string name;
	string prof_name;
	int code; // 001~999 
public:
	Course(double score_, int credit_, int attendee_, string name_, string prof_name_, int code_)
		: score(score_), credit(credit_), attendee(attendee_), name(name_), prof_name(prof_name_), code(code_)
	{}

	//getter
	double get_score() { return score; }
	double get_average() { return score*credit; }
	int get_credit() { return credit; }
	int get_attendee() { return attendee; }
	string get_name() { return name; }
	int get_code() { return code; }
	//setter
	void set_score(double d) { score = d; }
	void set_credit(int n) { credit = n; }
	void set_attendee(int n) { attendee = n; }
	void set_name(string a) { name = a; }
	void set_code(int c) { code = c; }

	void Print();
};