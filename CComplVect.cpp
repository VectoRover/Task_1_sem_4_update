 #include "CComplVect.h"

CComplVect::CComplVect()
{
	length = 0;
	this->ArrComplNumb = NULL;
}

CComplVect::CComplVect(int length, CComplNumb* ArrComplNumb)
{
	this->length = length;
	this->ArrComplNumb = new CComplNumb[length];
	for (size_t i = 0; i < length; i++)
	{
		this->ArrComplNumb[i] = ArrComplNumb[i];
	}
}

CComplVect::~CComplVect()
{

}

CComplNumb* CComplVect::get_ArrComplNumb() const
{
	return this->ArrComplNumb;
}

int CComplVect::get_length() const
{
	return this->length;
}

void CComplVect::set_output(string output)
{
	out = output;
}

void CComplVect::set_ArrComplNumb(CComplNumb* ArrComplNumb) 
{
	CComplNumb* tmp = this->ArrComplNumb;
	tmp = this->ArrComplNumb;
	this->ArrComplNumb = new CComplNumb[length];
	for (size_t i = 0; i < length; i++)
	{
		this->ArrComplNumb[i] = ArrComplNumb[i];
	}
}


void CComplVect::set_length(int length)
{
	this->length = length;
}

CComplVect& CComplVect::operator=(const CComplVect& b)
{
	this->length = b.length;
	this->ArrComplNumb = new CComplNumb[b.get_length()];
	if (this->length == b.length)
	{	
		for (size_t i = 0; i < this->length; i++)
		{
			this->ArrComplNumb[i] = b.ArrComplNumb[i];
		}
		return *this;
	}/*
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
	}*/
	else
	{
		cout << "error=" << endl;
		exit(-1);
	}
}


int CComplVect::Input(string filename, CFactoryComplVect** &factory, CComplVect** &w)
{
	string str = ""; 
	string type = "";
	int it = 0;
	int line = 0;
	int count = 0;
	string tmp_str = "";
	ifstream input_file(filename);//открываем файл

	if (input_file)
	{
		
		while (!input_file.eof())   //считаем количество строк, оно же количество векторов
		{
			getline(input_file, tmp_str, '\n');
			if (tmp_str.find(" ") == -1)
			{
				cout << "invalid input data 2" << endl;
				exit(-10);
			}
			line++; //здесь line для подсчета колва строк
		}
		
		input_file.seekg(0, ios::beg);
	    w = new CComplVect* [line];
		line = 0;


		while (!input_file.eof())
		{
			int j = 0;
			int m = -1;
			getline(input_file, tmp_str, ' '); // считываем первый символ (0 или 1)
			if (stoi(tmp_str) != 0 && stoi(tmp_str) != 1)
			{
				cout << "invalid input data 2" << endl;
				exit(-20);
			}
			str = str + tmp_str;
			while (!input_file.eof() && tmp_str.find("\n") == -1) //считываем числа до конца строки, их колво это удовенная длина вектора
			{
				getline(input_file, tmp_str, ' ');
				str = str + tmp_str;
				count++;
				if (count == 0)
				{
					cout << "invalid input data 3" << endl;
				}
			}
/*
			if (count % 2 != 0 || str[str.size() - 1] == ' ')
			{
				cout << "invalid input data 1" << endl;
				exit(2);
			}*/

			if(!input_file.eof())
			{
				input_file.seekg(-int(str.size()) - count - 2, ios::cur); //возвращаем каретку к началу строки
			}
			else
			{
				input_file.seekg(-int(str.size()) - count, ios::cur);
			}

			getline(input_file, tmp_str, ' ');   //создаем указатель на нужный вектор
			w[line] = factory[stoi(tmp_str)]->create();
			getline(input_file, tmp_str, ' ');
			type = tmp_str;

			
			CComplNumb* ArrComplNumb = new CComplNumb[count / 2];
			while (!input_file.eof() && tmp_str.find("\n") == -1)
			{
				getline(input_file, tmp_str, ' ');
				if (j % 2 == 0)
				{
					m++;
					ArrComplNumb[m].set_Re(double(stoi(tmp_str)));
				}
				if (j % 2 != 0 && tmp_str.find("\n") == -1)
				{
					ArrComplNumb[m].set_Im(double(stoi(tmp_str)));
				}
				if (tmp_str.find("\n") != -1)
				{
					ArrComplNumb[m].set_Im(double(stoi(tmp_str)));
					input_file.seekg(-int(tmp_str.size()-(tmp_str.substr(0, tmp_str.find("\n"))).size()), ios::cur);
				}
				j++;
			}
			w[line]->set_length(count / 2);
			w[line]->set_ArrComplNumb(ArrComplNumb);
			w[line]->set_output(type);
			w[line]->show();

			str = "";
			count = 0;
			line++;
			delete[] ArrComplNumb;
		}
		return 0;
	}
	else
	{
		cout << "could not open the input file" << endl;
		return NULL;
	}
}


/*CComplVect& CComplVect::operator=(const CComplVect& b)
{
	if (this != &b) {
		this->length = 0;
		delete[] ArrComplNumb;
		CopyOnly(b);
		return *this;
	}
}*/