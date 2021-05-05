#include <iostream>
#include <fstream>

#include"Population.h"

#define NBits 8
int GenNumber;

int main()
{
    std::fstream MyFile1("Boy1.txt");
    std::fstream MyFile2("Boy2.txt");

    srand(time(NULL)); 
    setlocale(LC_ALL, "Russian");
    //Слово для поиска
    std::string FinalWord = "МИР";
    
    GenNumber = FinalWord.size();
    //Заданные параметры
    int PopMaxAmount = 100;
    int Generation = 1, GenLimit = 500; 
    float PC = 0.5, PM = 0.01;
    float Linage = 0.4;
    //Начальная популяция
    Population ok(PopMaxAmount, FinalWord);
    ok.Aptitude(FinalWord);
    ok.Sort();
    //Цикличная работа
    int AvgCool = 0;
    int CoolCool = 0;

    for (int i = 0; i < GenLimit; i++)
    {
        ok = ok.Cross(PC, Linage, GenNumber, NBits, FinalWord, 0.95);
        ok = ok.Mutate(PM, FinalWord);
        ok.Aptitude(FinalWord);
        ok.Sort();
        AvgCool = ok.AvgCool();
        CoolCool = ok.GetSpecCoolness(0);
        MyFile1 << "(" << i << "," << AvgCool << "),";
        MyFile2 << "(" << i << "," << CoolCool << "),";
        std::cout << "Best: " << ok.GetSpecDecoded(0) << " <Error: " << ok.GetSpecCoolness(0) << ">           " << i<< std::endl;
        if (ok.GetSpecCoolness(0) == 0) break;
    }
    MyFile1.close();
    MyFile2.close();
    system("pause");
}