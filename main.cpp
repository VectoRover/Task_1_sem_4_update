#define __CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#include <string>
#include <iostream>
#include <fstream>
#include "CComplNumb.h"
#include "CComplVect.h"
#include "CComplVectHori.h"
#include "CComplVectVert.h"
#include "autotests.h"
#include "CFactoryComplVect.h"
#include "CFactoryComplVectHori.h"
#include "CFactoryComplVectVert.h"


using namespace std;
int main()
{
	string str = "";
	int line = 0;
	int count = 0;
	CComplVect** w = NULL;
	//ofstream outf("output.txt");
	ifstream input_file("data.txt");
	CFactoryComplVect** factory = new CFactoryComplVect*[2];
	factory[0] = new CFactoryComplVectHori;
	factory[1] = new CFactoryComplVectVert;

	autotest_CComplNumb();
	autotest_CComplVect();

    CComplVect::Input("data.txt", factory, w);
	
	while (!input_file.eof())   
	{
		getline(input_file, str, '\n');
		line++; 
	}

	for (int i = 0; i < line; i++)
	{
		w[i]->output();
	}

	for (int i = 0; i < line; i++)
	{
		w[i]->~CComplVect();
		delete w[i];
	}

	delete[] w;
	delete factory[0];
	delete factory[1];
	delete[] factory;
	input_file.close();
	//outf.close();


	CComplVectHori a, b;
	CComplVectVert c;
	
	c = a + b;



	_CrtDumpMemoryLeaks();
	return 0;
}