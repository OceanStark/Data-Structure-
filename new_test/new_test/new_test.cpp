#include "new_test.h"

test::test()
{
	if (m_name != 0) { 
		
		delete m_name; 
		m_name = 0;
		
	}
	printf("�����ǹ��캯��\n");
}



test::~test()
{
	_free_();
	/*if (m_name != 0) {
		delete m_name;
		m_name = 0;
	}
	printf("������������\n");
	*/
}

void test::_malloc_(int size)
{
	 m_name = new  char[size];
}

void test::_free_()
{
	if (m_name != 0) {
		delete m_name;
		m_name = 0;
	}
	printf("������������\n");
}
