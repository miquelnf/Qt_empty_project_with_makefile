#ifndef TEST_H
#define TEST_H

#include <qstring.h>

class test
{
public:
	test(QString str);
	void despres();

	char const*	m_cspstr;
	char*		m_spstr;
	QString		m_str;
};

#endif // TEST_H
