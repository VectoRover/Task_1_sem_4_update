#pragma once
#include <string>
#include <iostream>
#include "CComplNumb.h"
#include "CFactoryComplVect.h"
#include <fstream>
using namespace std;

class CComplVectHori;
class CComplVectVert;

class CComplVect
{
protected:
	int length;
	CComplNumb* ArrComplNumb;
	string out;
public:
	CComplVect();
	CComplVect(int length, CComplNumb* ArrComplNumb);
	virtual ~CComplVect();
	CComplNumb* get_ArrComplNumb() const;

	void CopyOnly(const CComplVect& b)
	{
		length = b.length;
		ArrComplNumb = new CComplNumb[length];
		for (int i = 0; i < length; i++)
		{
			ArrComplNumb[i] = b.ArrComplNumb[i];
		}
	}



	int get_length() const;
	void set_output(string output);
	void set_length(int length);
	void set_ArrComplNumb(CComplNumb* ArrComplNumb);
	CComplVect& operator=(const CComplVect& b);
	virtual void show() = 0;
	virtual void output() = 0;
	static int Input(string filename, CFactoryComplVect**& factory, CComplVect**& w);

	friend class CComplNumb;
	friend CComplVectHori operator+(const CComplVect& first, const CComplVect& second);
	friend CComplVectHori operator-(const CComplVect& first, const CComplVect& second);
};