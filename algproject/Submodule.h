#pragma once
#include "Course.h"
#include "Univ.h"
#include "RedBlackTree.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <functional>

class Submodule
{
private:
	RedBlackTree* RBStudentInfo;
	vector<Course> CourseInfo;

public:
	priority_queue<pair<double, int>, vector<pair<double, int> >>* RankInfo;

	Submodule();
	~Submodule();

	void InsertStudent(int ID_, int year_, int sem_, char gender_, string name_, string coll_, string major_);
	Student* SearchStudent(int id);

	Course* SearchCourse(int id);
	
	void UpdateRank();
};