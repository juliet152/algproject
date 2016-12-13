#pragma once
#include "Course.h"
#include "RedBlackTree.h"
#include "Semester.h"

class student {
private:
	bool gender;
	int ID;
	char name[30];
	char coll[30];
	char maj[30];
	node* sem[8];
public:
	//getter
	bool get_gender() { return gender; }
	int get_ID() { return ID; }
	char* get_name() { return name; }
	char* get_coll() { return coll; }
	node** get_sem() { return sem; }
	//setter
	void set_gender(bool g) { gender = g; }
	void set_ID(int id) { ID = id; }
	void set_name(char* n) { strcpy(name, n); }
	void set_coll(char* c) { strcpy(coll, c); }
	void set_sem(node** s) { ; }
	//constructor
	student(bool g, char id, char* n, char* c, char*m) {
		gender = g; ID = id; strcpy(name, n); strcpy(coll, c); strcpy(maj, m);
	}
};

class professor {
};

class college {
private:
	char* name[30];
	major* m_list[8];
public:
};

class major {
private:
	char name[30];
};