#include "CComplVect.h"
#include "CComplVectVert.h"

CComplVectVert::CComplVectVert()/*(int length, CComplNumb* ArrComplNumb) ::*/ : CComplVect() {}
CComplVectVert::CComplVectVert(int length, CComplNumb* ArrComplNumb) : CComplVect(length, ArrComplNumb) {}
CComplVectVert:: ~CComplVectVert()
{
	delete[] ArrComplNumb;
}

/*{
	this->length = length;
	this->ArrComplNumb = new CComplNumb[length];
	for (size_t i = 0; i < length; i++)
	{
		this->ArrComplNumb[i] = ArrComplNumb[i];
	}
}*/

/*CComplVectVert& CComplVectVert::operator=(const CComplVectVert& b)
{
	if (this->length == b.length && this->ArrComplNumb != NULL)
	{
		for (size_t i = 0; i < this->length; i++)
		{
			this->ArrComplNumb[i] = b.ArrComplNumb[i];
		}
		return *this;
	}
	if (this->length != b.length && this->ArrComplNumb != NULL)
	{
		cout << "vectors of different lengths" << endl;
		exit(-1);
	}
	if (this->length != b.length && this->ArrComplNumb == NULL)
	{
		this->length = b.length;
		this->ArrComplNumb = b.ArrComplNumb;
		for (size_t i = 0; i < this->length; i++)
		{
			this->ArrComplNumb[i] = b.ArrComplNumb[i];
		}
		return *this;
	}
	else
	{
		cout << "error" << endl;
		exit(-1);
	}
}*/

void CComplVectVert::show()
{
	for (size_t i = 0; i < length; i++)
	{
		ArrComplNumb[i].show();
		cout << endl;
	}
}


/*CComplVectVert& CComplVectVert::operator+(const CComplVectVert& b)
{
	CComplVectVert* ptr = new CComplVectVert;
	ptr->ArrComplNumb = new CComplNumb[length];
	if (b.length == this->length)
	{
		ptr->length = b.length;
		for (size_t i = 0; i < this->length; i++)
		{
			ptr->ArrComplNumb[i] = this->ArrComplNumb[i] + b.ArrComplNumb[i];
		}
		return *ptr;
	}
	else
	{
		cout << "vectors of different lengths" << endl;
		exit(-1);
	}
}*/

/*CComplVectVert& CComplVectVert::operator-(const CComplVectVert& b)
{
	CComplVectVert* ptr = new CComplVectVert;
	ptr->ArrComplNumb = new CComplNumb[length];
	if (b.length == this->length)
	{
		ptr->length = b.length;
		for (size_t i = 0; i < this->length; i++)
		{
			ptr->ArrComplNumb[i] = this->ArrComplNumb[i] - b.ArrComplNumb[i];
		}
		return *ptr;
	}
	else
	{
		cout << "vectors of different lengths" << endl;
		exit(-1);
	}
}*/

CComplNumb CComplVectVert::operator*(CComplVectVert& b)
{
	CComplNumb m;
	if (this->length != b.length && this->ArrComplNumb != NULL)
	{
		cout << "vectors of different lengths" << endl;
		exit(-1);
	}
	if (this->ArrComplNumb != NULL)
	{
		b.conjugate();
		for (size_t i = 0; i < length; i++)
		{
			m = m + this->ArrComplNumb[i] * b.ArrComplNumb[i];
		}
		return m;
	}
	else
	{
		cout << "error" << endl;
		exit(-2);
	}
}

CComplVectVert& CComplVectVert::conjugate()
{
	for (size_t i = 0; i < this->length; i++)
	{
		this->ArrComplNumb[i].set_Im(-this->ArrComplNumb[i].get_Im());
	}
	return *this;
}


void CComplVectVert::output()
{
	ofstream outf(out);
	for (int i = 0; i < length; i++)
	{
		ArrComplNumb[i].showf(outf);
		outf << endl;
	}
}