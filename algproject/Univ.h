#pragma once
#include "Course.h"
#include "RedBlackTree.h"
#include "Semester.h"
#include "Course.h"
#include <string>
#include <vector>
#define MAX_CREDIT 140

class Student : public RedBlackEntry {
private:
	char gender;
	int ID;
	int year;
	int current_sem;
	int credit;
	double GPA;
	string name;
	string coll;
	string major;
	vector<Course> sem[8];
public:
	// Virtual function
	int GetKey() const { return ID; }

	//getter
	char get_gender() { return gender; } //m,f
	int get_ID() { return ID; }
	string get_name() { return name; }
	string get_coll() { return coll; }
	vector<Course>* get_sem() { return sem; }
	int get_cursem() { return current_sem; }
	int get_year() { return year; }
	int get_credit() { return credit; }
	double get_GPA() { return GPA; }
	//setter
	void set_gender(char g) { gender = g; }
	void set_ID(int id) { ID = id; }
	void set_name(string n) { name = n; }
	void set_coll(string c) { coll = c; }
	void set_credit(int c) { credit = c; }
	void set_GPA();
	//constructor
	Student(char g, int id, int y, int cursem, string n, string c, string m) {
		gender = g; 
		ID = id; 
		year = y;
		current_sem = cursem;
		name = n; 
		coll = c; 
		major = m;
	}

	Course* SearchCourse(int id);
	void Print();
};

class major {
private:
	char name[30];
};

class college {
private:
	char* name[30];
	major* m_list[8];
public:
};