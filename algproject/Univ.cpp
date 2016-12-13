#include "Univ.h"
#include "Semester.h"

void Student::Print()
{
	cout << "[*] 학번: " << ID << "\n";
	cout << "[*] 이름: " << name << "\n";
	cout << "[*] 학년: " << year << "\n";
	cout << "[*] 학기: " << current_sem << "\n";
	cout << "[*] 수강 학점: " << credit << "\n";
	cout << "[*] 졸업까지 남은 학점: " << (140 - credit >= 0 ? 140 - credit : 0) << "\n";
	cout.precision(3);
	cout << "[*] 평점: " << GPA << "\n";
	for (int i = 0; i < current_sem; i++) {
		cout << "[-] " << i + 1 << "학기 (학점, 평점)\n";
		int c = 0;
		for (vector<Course>::iterator it = sem[i].begin(); it < sem[i].end(); it++) {
			it->Print();
			cout << "\t";
			if (++c == 3) {
				cout << "\n";
				c = 0;
			}
		}

		cout << "\n";
	}
}

void Student::set_GPA()
{
	if (credit == 0) {
		this->GPA = 0;
		return;
	}
	vector<Course>::iterator it;
	double GPA = 0.;
	for (int i = 0; i < current_sem; i++) {
		for (it = sem[i].begin(); it < sem[i].end(); it++) {
			GPA += it->get_average();
		}
	}
	GPA /= credit;
	this->GPA = GPA;
}

Course* Student::SearchCourse(int id)
{
	vector<Course>::iterator it;
	for (int i = 0; i < current_sem; i++) {
		for (it = sem[i].begin(); it < sem[i].end(); it++) {
			if (it->get_code() == id) {
				return &(*it);
			}
		}
	}
	return NULL;
}