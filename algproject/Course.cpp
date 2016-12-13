#include "Course.h"
#include <iostream>

char** course_code::code_to_str(course_code* cc, char* str[])
{
	char buff[10];
	strcpy(*str, cc->course_initial);
	strcat(*str, &(cc->course_level));
	strcat(*str, _itoa(cc->course_serial, buff, 10));
	return str;
}