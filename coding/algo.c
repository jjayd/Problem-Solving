#include <stdio.h>


typedef struct student{
	int num;
	char name[10];
}S;


int main(void) {

	S stu[10];
	stu[0].num=1;

	S* ss;
	ss->num=1;
}
