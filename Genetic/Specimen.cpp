#include "Specimen.h"

Specimen::Specimen()
{
	Genoms = NULL;
	_GenNum = _GenBits = NULL;
}

Specimen::Specimen(int GenNum, int GenBits)
{
	_GenNum = GenNum; _GenBits = GenBits;

	Genoms = new bool* [_GenNum];
	for (int i = 0; i < _GenNum; i++)
	{
		Genoms[i] = new bool[_GenBits];
		int r = rand() % 256;
		while (r == -107 || r == -96 || r == 0 || r == 7 || r == 8 || r == 9 || r == 10 || r == 13 || r == 27)
			r = rand() % 256;
		
		for (int j = _GenBits -1; j >= 0; j--)
			if (r != 0)
			{
				Genoms[i][j] = r % 2;
				r = r / 2;
			}
			else Genoms[i][j] = false;
	}
}

Specimen::Specimen(std::string FinalWord)
{
	//Заполнение особи начальным значением генов
	_GenNum = FinalWord.size(); _GenBits = 8;

	Genoms = new bool* [_GenNum];
	for (int i = 0; i < _GenNum; i++)
	{
		//Получаем ген как набор 01
		Genoms[i] = new bool[_GenBits];
		for (int j = _GenBits - 1; j >= 0; j--)
			Genoms[i][j] = rand() % 2;
	}
}

Specimen::~Specimen()
{
	if (Genoms != NULL)
	{
		for (int i = _GenNum - 1; i >= 0; i--)
			delete[] Genoms[i];
		delete[] Genoms;
	}
}

Specimen::Specimen(const Specimen& ToCopy)
{

	_GenNum = ToCopy._GenNum;
	_GenBits = ToCopy._GenBits;

	if (Genoms != NULL)
	{
		for (int i = _GenNum - 1; i >= 0; i--)
			delete[] Genoms[i];
		delete[] Genoms;
	}

	Genoms = new bool* [_GenNum];

	for (int j = 0; j < _GenNum; j++)
	{
		Genoms[j] = new bool[_GenBits];

		for (int i = 0; i < _GenBits; i++)
			Genoms[j][i] = ToCopy.Genoms[j][i];
	}
}

bool** Specimen::GetGenoms()
{
	return Genoms;
}

bool& Specimen::GetGenomsGenBit(int GenNumber, int GenNumber2)
{
	return Genoms[GenNumber][GenNumber2];
}

void Specimen::PrintChrom()
{
	if (Genoms == NULL) return;
	std::cout << std::endl;
	for (int i = 0; i < _GenNum; i++)
	{
		for (int j = 0; j < _GenBits; j++)
			std::cout << Genoms[i][j];
		std::cout << " ";
	}
}

Specimen Specimen::operator=(Specimen EqSPC)
{
	if (this == &EqSPC) return *this;

	_GenNum = *EqSPC.GetGenNum();
	_GenBits = EqSPC.GetGenBits();

	if (Genoms != NULL)
	{
		for (int i = _GenNum - 1; i >= 0; i--)
			delete[] Genoms[i];
		delete[] Genoms;
	}

	Genoms = new bool*[_GenNum];

	for (int j = 0; j < _GenNum; j++)
	{
		Genoms[j] = new bool[_GenBits];
		for (int i = 0; i < _GenBits; i++)
			Genoms[j][i] = EqSPC.GetGenoms()[j][i];
	}

	return *this;
}

int* Specimen::GetGenNum()
{
	return &_GenNum;
}

int Specimen::GetGenBits()
{
	return _GenBits;
}

int Specimen::GetGenDataDecode(int GenNumberToDecode)
{
	int CurBit = 7;
	int dec_value = 0;
	int base = 1;

	while (CurBit+1) {
		int last_digit = Genoms[GenNumberToDecode][CurBit--];

		dec_value += last_digit * base;
		base *= 2;
	}

	return (dec_value-128);
}
