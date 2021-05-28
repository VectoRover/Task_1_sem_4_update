#pragma once
#include <string>
#include <iostream>
#include "CComplNumb.h"
#include "CComplVect.h"
#include "autotests.h"
using namespace std;

class CComplVectVert : public CComplVect
{
public:
	using CComplVect::CComplVect;
	using CComplVect::operator=;

	CComplVectVert();
	CComplVectVert(int length, CComplNumb* ArrComplNumb);
	~CComplVectVert () override;

	//CComplVectVert& operator=(const CComplVectVert& b);
	/*CComplVectVert& operator+(const CComplVectVert& b);
	CComplVectVert& operator-(const CComplVectVert& b);*/
	CComplNumb operator*(CComplVectVert& b);
	CComplVectVert& conjugate();
	/*	CComplVect(int length, CComplNumb* ArrComplNumb);
		CComplVect operator=(const CComplVect& b);
		CComplVect operator+(const CComplVect& b);
		CComplVect operator-(const CComplVect& b);
		CComplNumb operator*(CComplVect& b);
		CComplVect conjugate();*/
	void show();
	virtual void output() override;
	/*int get_length();
	CComplNumb* get_ArrComplNumb();*/
	friend class CComplNumb;
};