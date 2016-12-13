/*
	semseter node is the head node of courses in that semester.

	LL seems like semester->course1->course2->course3->course4....

*/

#pragma once
#include "Course.h"

typedef struct _node {
	course* key;
	struct _node* next;
}node;

void init_node(node* n);
node* insert_node(course* c, node* n);
node* find_node(course* c, node* n);