#pragma once
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

class test {

public:
	char* m_name;
	test();
	~test();
	void _malloc_(int size);
	void _free_();
};