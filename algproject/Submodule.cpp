#include "Submodule.h"
Submodule::Submodule()
{
	RBStudentInfo = new RedBlackTree();
	srand((unsigned int)time(NULL));

	// ���� ���� ����
	for (int i = 0; i < 100; i++) {
		string name = "����";
		name.append(to_string(i));
		Course* t = new Course(0, 3, 0, name, "", i);
		CourseInfo.push_back(*t);
	}
	for (int i = 100; i < 200; i++) {
		string name = "����";
		name.append(to_string(i));
		Course* t = new Course(0, 2, 0, name, "", i);
		CourseInfo.push_back(*t);
	}

	for (int i = 0; i < 200; i++) {
		int rnd = rand() % 2;
		char gender = rnd == 0 ? 'm' : 'f';
		int year = 1+ i / 50;
		rnd = 1 + (rand() % 2);
		int sem = (year - 1)*2 + rnd; // ���� �г�*2 + ���� �ٴ� �б�
		string name = "�л�";
		name.append(to_string(i));
		string coll = "����";
		coll.append(to_string(rand() % 6));
		string maj = "����";
		maj.append(to_string(rand() % 20));
		Student* t = new Student(gender, i, year, sem, name, coll, maj);
		int cur_credit = 0;
		bool lect[200];
		memset(lect, false, 200);
		for (int j = 0; j < sem; j++) {
			int credit = 0;
			int maxcredit = 15 + rand() % 7;
			do {
				while (lect[(rnd = rand() % 200)]); // ���� �ߺ� ����
				Course* c = new Course(*SearchCourse(rnd));
				lect[rnd] = true; 
				credit += c->get_credit();
				if (j != sem - 1) { // ���� �б� �̿ܿ��� �������� ���� �Է�
					double score = 2 + rand() % 3; // 2~4
					score += (rand() % 2)*0.5; // + 0.0 or 0.5
					c->set_score(score);
				}
				t->get_sem()[j].push_back(*c);
			} while (credit < maxcredit);
			cur_credit += credit;
		}
		t->set_credit(cur_credit);
		t->set_GPA();
		RBStudentInfo->Insert(t);
	}

}

Submodule::~Submodule()
{
	delete RBStudentInfo;

	while (!CourseInfo.empty()) {
		delete &CourseInfo.back();
		CourseInfo.pop_back();
	}
}

void Submodule::InsertStudent(int ID_, int year_, int sem_, char gender_, string name_, string coll_, string major_)
{
	Student* t = new Student(gender_, ID_, year_, sem_, name_, coll_, major_);
	t->set_credit(0);
	t->set_GPA();
	RBStudentInfo->Insert(t);
}

Student* Submodule::SearchStudent(int id)
{
	Student* t = (Student*)RBStudentInfo->Search(id)->GetEntry();
	return t;
}

Course* Submodule::SearchCourse(int id)
{
	Course* t = &CourseInfo[id];
	return t;
}

void Submodule::UpdateRank()
{
	if (RankInfo) delete RankInfo;
	RankInfo = new priority_queue<pair<double, int>, vector<pair<double, int> >>();
	for (int i = 0; i < 500; i++) {
		Student* t = SearchStudent(i);
		if (t)
			RankInfo->push(make_pair<double, int>(t->get_GPA(), t->GetKey()));
	}

}