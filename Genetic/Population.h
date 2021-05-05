#include"Specimen.h"

#pragma once

class Population
{
	Specimen* PopSpecimens;
	int* CoolnessSpecimens;
	int _GenNum, _GenBits, _PopAmount, _crosslen;
	
public:

	Population(int AmountOfSpecimens, std::string FinalWord);

	Population(int GenNum, int GenBits, int PopAmount, std::string FinalWord);

	void SelectionSlice(float l);

	Population Cross(float PC, float Lineage, int GenNum, int GenBit, std::string FinalWord, float T);

	void Aptitude(std::string& FinalWord);

	float AvgCool();

	int GetSpecCoolness(int CurSpec);

	Population Mutate(float PM, std::string FinalWord);

	Specimen& operator[](int i);

	void Sort();

	std::string GetSpecDecoded(int CurSpec);
};

