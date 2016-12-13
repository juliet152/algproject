#pragma once

typedef struct _course {
	int credit;
	char level; // alphabet for general education, 2 for basic classes, 3 for advanced classes
	char* major_code; // initial letters for major
	int attendee[80]; // no. of students in the course
}course;

typedef struct _student {
	int ID;
	char* name;
	node* semester;
}student;