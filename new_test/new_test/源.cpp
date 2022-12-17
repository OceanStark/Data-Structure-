#include"new_test.h"
int main() {
	printf("1\n");
	test T1;
	T1._malloc_(100);
	printf("2\n");
	strcpy(T1.m_name, "ocean");

}