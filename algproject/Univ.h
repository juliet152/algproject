#pragma once
#include "Course.h"
#include "RedBlackTree.h"
#include "Semester.h"

#define MAX_CREDIT 140

class student {
private:
	char gender;
	int ID;
	char name[30];
	char coll[30];
	char maj[30];
	node* sem[8];
public:
	//getter
	char get_gender() { return gender; } //m,f
	int get_ID() { return ID; }
	char* get_name() { return name; }
	char* get_coll() { return coll; }
	node** get_sem() { return sem; }
	//setter
	void set_gender(char g) { gender = g; }
	void set_ID(int id) { ID = id; }
	void set_name(char* n) { strcpy(name, n); }
	void set_coll(char* c) { strcpy(coll, c); }
	void set_sem(node** s,int sem) 
	{ 
		node* p;
		p = (node*)malloc(sizeof(node*));
		s[sem-1] = p;
	}
	//constructor
	student(char g, int id, char* n, char* c, char* m) {
		gender = g; ID = id; strcpy(name, n); strcpy(coll, c); strcpy(maj, m);
	}
};

class professor {
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

