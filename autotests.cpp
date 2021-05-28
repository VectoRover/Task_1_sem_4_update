#include <iostream>
#include "autotests.h"

using namespace std;

void autotest_CComplNumb()
{
	CComplNumb a(2, 3);
	CComplNumb b(4, 5);
	CComplNumb c;
	CComplNumb d;
	CComplNumb e;

	c = a + b;
	d = a - b;
	e = a * b;

	if (c.get_Re() == 6 && c.get_Im() == 8 && d.get_Re() == -2 && d.get_Im() == -2 && e.get_Re() == -7 && e.get_Im() == 22)
	{
		cout << "autotest_CComplNumb passed" << endl;
	}
	else
	{
		cout << "autotest_CComplNumb failed" << endl;
	}
	
};

void autotest_CComplVect()
{
	CComplNumb arr0[2];
	CComplNumb arr1[2];
	CComplVectHori result1;
	CComplVectHori result2;
	CComplNumb result3;
	CComplNumb a(1, 2);
	CComplNumb b(3, 4);
	CComplNumb c(5, 6);
	CComplNumb d(7, 8);

	arr0[0] = a;
	arr0[1] = b;
	arr1[0] = c;
	arr1[1] = d;

	CComplVectHori e(2, arr0);
	CComplVectHori f(2, arr1);
	result1 = e + f;
	result2 = e - f;
	result3 = e * f;

	e.show();
	f.show();
	result1.show();
	result2.show();



	if (result1.get_ArrComplNumb()[0].get_Re() == 6 && result1.get_ArrComplNumb()[0].get_Im() == 8 &&
		result1.get_ArrComplNumb()[1].get_Re() == 10 && result1.get_ArrComplNumb()[1].get_Im() == 12 &&
		result2.get_ArrComplNumb()[0].get_Re() == -4 && result2.get_ArrComplNumb()[0].get_Im() == -4 &&
		result2.get_ArrComplNumb()[1].get_Re() == -4 && result2.get_ArrComplNumb()[1].get_Im() == -4 &&
		result3.get_Re() == 70 && result3.get_Im() == 8)
	{
		cout << "autotest_CComplVect passed" << endl;
	}
	else
	{
		cout << "autotest_CComplVect failed" << endl;
	}
};


