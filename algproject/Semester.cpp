#include "Semester.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

void init_node(node* n)
{
	n = (node*)malloc(sizeof(node*));
	n->next = NULL;
}

node* insert_node(course* c,node* n)
{
	node* s;
	s = (node*)malloc(sizeof(node*));
	s->key = c;
	s->next = n->next;
	n->next = s;
	return s;
}

node* find_node(course* c, node* n)
{
	node* s;
	s = n->next;
	while (s->key != c && s != NULL)
		s = s->next;
	if (s == NULL)
		printf("course not found\n");
	return s;
}