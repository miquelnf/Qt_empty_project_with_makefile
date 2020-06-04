#include <QCoreApplication>
#include <QUrl>
#include <QUrlQuery>
#include <math.h>
#include "test.h"

struct ProytecsaPlatesIdTypes{
	quint32 deviceName;
	quint16 hardwareVersion;
	quint32 softwareVersion;
};
struct ProytecsaNodes{
	quint32 master;
	quint8 nodeId;
	ProytecsaPlatesIdTypes id;

	//internal declaration of struct just for the next union
	struct fullCodeST{
		quint16 boardType;
		quint8 HWrevision;
		quint8 boardNumber;
	};
	union {
		quint32 fullCodeI;
		fullCodeST fullCodeS;
	};
};

void Test1()
{
	QString bitrate = "0";
	QString bitrateo = "0";
	quint32 result = 0;

	bitrate = bitrateo = "10";
	result = bitrateo.replace('K', "000").replace('M', "000000").toUInt();
	printf("%s - %d\n", bitrate.toStdString().c_str(), result);

	bitrate = bitrateo = "1K";
	result = bitrateo.replace('K', "000").replace('M', "000000").toUInt();
	printf("%s - %d\n", bitrate.toStdString().c_str(), result);

	bitrate = bitrateo = "1M";
	result = bitrateo.replace('K', "000").replace('M', "000000").toUInt();
	printf("%s - %d\n", bitrate.toStdString().c_str(), result);

	bitrate = bitrateo = "10M";
	result = bitrateo.replace('K', "000").replace('M', "000000").toUInt();
	printf("%s - %d\n", bitrate.toStdString().c_str(), result);
}

void Test2()
{
	test t("hola");
	printf("\n");
	t.despres();
}

void Test3()
{
	ProytecsaNodes n;
	n.fullCodeI = 0xFFFFFFFF;
	printf("%08X\n", n.fullCodeI);
	n.fullCodeS.boardType = 0; //0x5678
	printf("%08X\n", n.fullCodeI);
	n.fullCodeS.HWrevision = 0; //0x34
	printf("%08X\n", n.fullCodeI);
	n.fullCodeS.boardNumber = 0; //0x12
	printf("%08X\n", n.fullCodeI);
}

void Test4()
{
	QUrl url;
	url.setUrl("https://www.feaser.com/openblt/doku.php?id=manual:demos:nucleo_f746zg_gcc");
	QUrlQuery qurl(url);
	
	QString value = url.queryItemValue("id"); //cal compilar amb: -DQT_DISABLE_DEPRECATED_BEFORE al Makefile
	QString qvalue = qurl.queryItemValue("id");
	printf("value: %s, qvalue: %s\n", value.toStdString().c_str(), qvalue.toStdString().c_str());
}

//void Test5(QVector<float> *vector)
void Test5(QVector<float>& vector)
{
	QVector<float> vector1;
	QVector<float> vector2;
	for(int i=0; i<10; i++)
	{
		vector1.append(static_cast<float>(i)/3);
	}
	
	vector2 = vector1;
	vector1.clear();
	for(int i=0; i<vector2.count(); i++)
		printf("%f ", vector2[i]);
	printf("\n");
	
	//*vector = vector2;
	vector = vector2;
}

void Test6()
{
	float f = NAN;
	double d = static_cast<double>(NAN);
	printf("%f %f\n", f, d);
}

int main(int argc, char *argv[])
{
	//QCoreApplication a(argc, argv);
	Q_UNUSED(argc)
	Q_UNUSED(argv)


	// 1 QString replace
	//Test1();

	// 2 char const* i QByteArray
	//Test2();
	
	// 3 Union
	//Test3();
	
	// 4 QUrl vs QUrlQuery
	//Test4();
	
	// 5 QVector
	QVector<float> vector;
	//Test5(&vector);
	Test5(vector);
	for(int i=0; i<vector.count(); i++)
		printf("%f ", vector[i]);
	printf("\n");
	
	// 6 NAN
	//Test6();

	//return a.exec();
	return 0;
}
