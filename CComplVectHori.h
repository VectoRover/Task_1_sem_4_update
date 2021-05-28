#pragma once
#include <string>
#include <iostream>
#include "CComplNumb.h"
#include "CComplVect.h"
#include "autotests.h"
using namespace std;

class CComplVectHori : public CComplVect
{
public:
	CComplVectHori();
    CComplVectHori(int length, CComplNumb* ArrComplNumb);
	~CComplVectHori() override;

	//CComplVectHori& operator=(const CComplVectHori& b);
	/*CComplVectHori& operator+(const CComplVectHori& b);
	CComplVectHori& operator-(const CComplVectHori& b);*/
	CComplNumb operator*(CComplVectHori& b);
	CComplVectHori& conjugate();
	void show();
	virtual void output() override;
	friend class CComplNumb;

	friend CComplVectHori operator+(const CComplVect& first, const CComplVect& second);
	friend CComplVectHori operator-(const CComplVect& first, const CComplVect& second);
};