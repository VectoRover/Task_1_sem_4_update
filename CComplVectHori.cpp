#include "CComplVect.h"
#include "CComplVectHori.h"

CComplVectHori::CComplVectHori() : CComplVect() {}
CComplVectHori::CComplVectHori(int length, CComplNumb* ArrComplNumb) : CComplVect(length, ArrComplNumb ) {}
CComplVectHori:: ~CComplVectHori()
{
	delete[] ArrComplNumb;
}


/*CComplVectHori& CComplVectHori::operator=(const CComplVectHori& b)
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

void CComplVectHori::show()
{
	for (size_t i = 0; i < length; i++)
	{
		ArrComplNumb[i].show();
	}
}
	/*CComplVectHori CComplVectHori::operator=(const CComplVect& b)
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
	}
	*/
	/*CComplVectHori& CComplVectHori::operator+(const CComplVectHori& b )
	{
		CComplVectHori* ptr = new CComplVectHori;
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
	}

	CComplVectHori& CComplVectHori::operator-(const CComplVectHori& b)
	{
		CComplVectHori* ptr = new CComplVectHori;
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
	
	CComplNumb CComplVectHori::operator*(CComplVectHori& b)
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
			cout << "error*" << endl;
			exit(-2);
		}
	}

	CComplVectHori& CComplVectHori::conjugate()
	{
		for (size_t i = 0; i < this->length; i++)
		{
			this->ArrComplNumb[i].set_Im(-this->ArrComplNumb[i].get_Im());
		}
		return *this;
	}


	void CComplVectHori::output()
	{
		ofstream outf(out);
		for (int i = 0; i < length; i++)
		{
			ArrComplNumb[i].showf(outf);
		}
		outf << endl;
	}


	CComplVectHori operator+(const CComplVect& first, const CComplVect& second)
	{
		CComplVectHori* tmp = new CComplVectHori;
		CComplNumb* arr = new CComplNumb[first.get_length()];
		tmp->set_ArrComplNumb(new CComplNumb[first.get_length()]);
		if (first.get_length() == second.get_length())
		{
			for (size_t i = 0; i < first.get_length(); i++)
			{
				arr[i] = first.get_ArrComplNumb()[i] + second.get_ArrComplNumb()[i];
			}
		//	tmp->set_ArrComplNumb(arr);
			return CComplVectHori(first.get_length(), arr);
		}
		/*if (this->length != b.length && this->ArrComplNumb != NULL)
		{z
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
		}*/
		else
		{
			cout << "error+" << endl;
			exit(-1);
		}
	}

	CComplVectHori operator-(const CComplVect& first, const CComplVect& second)
	{
		CComplVectHori* tmp = new CComplVectHori;
		CComplNumb* arr = new CComplNumb[first.get_length()];
		tmp->set_ArrComplNumb(new CComplNumb[first.get_length()]);
		if (first.get_length() == second.get_length())
		{
			for (size_t i = 0; i < first.get_length(); i++)
			{
				arr[i] = first.get_ArrComplNumb()[i] - second.get_ArrComplNumb()[i];
			}
			//	tmp->set_ArrComplNumb(arr);
			return CComplVectHori(first.get_length(), arr);
		}
		/*if (this->length != b.length && this->ArrComplNumb != NULL)
		{z
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
		}*/
		else
		{
			cout << "error+" << endl;
			exit(-1);
		}
	}