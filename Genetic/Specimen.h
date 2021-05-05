#include<ctime>
#include<iostream>

#pragma once
class Specimen
{
	bool** Genoms = NULL;
	int _GenNum, _GenBits;

public:
	Specimen();

	Specimen(int GenNum, int GenBits);

	Specimen(std::string FinalWord);

	~Specimen();

	Specimen(const Specimen& ToCopy);

	bool** GetGenoms();

	bool& GetGenomsGenBit(int GenNumber, int GenNumber2);

	void PrintChrom();

	int* GetGenNum();

	Specimen operator=(Specimen EqSPC);

	int GetGenBits();

	int GetGenDataDecode(int GenNumberToDecode);
};

