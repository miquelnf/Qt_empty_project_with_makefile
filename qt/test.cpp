#include "test.h"

test::test(QString str)
{
	//1
	m_str = str;

	//2
	//m_cspstr = m_str.toStdString().c_str();
	QByteArray ba = str.toLocal8Bit();
	m_cspstr = ba.data();

	//3
	m_spstr = new char[str.length()+1];
	strcpy(m_spstr, str.toStdString().c_str());

	printf("0: %s\n1: %s\n2: %s\n3: %s\n",
		   str.toStdString().c_str(),
		   m_str.toStdString().c_str(),
		   m_cspstr,
		   m_spstr);
}

void test::despres()
{
	printf("1: %s\n2: %s\n3: %s\n",
		   m_str.toStdString().c_str(),
		   m_cspstr,
		   m_spstr);
}
