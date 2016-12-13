/*
	semseter node is the head node of courses in that semester.

	LL seems like semester->course1->course2->course3->course4....

*/

#pragma once
#include "Univ.h"

typedef struct _node {
	course* key;
	struct _node* next;
}node;