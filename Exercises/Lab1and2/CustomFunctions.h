#pragma once 
#include <vector>
#include <string>

template<typename T>
int NlineCheck(int Nlines, T Vec, int OversizeDefault = 0);

//template<typename T1>
void printVec(std::vector<std::vector<double>> Vec, int Nlines = 0);

//template<typename T2>
void printVec(std::vector<std::vector<double>> Vec,std::string PrintFileName , int Nlines = 0);

//template<typename T3>
void printVec(std::vector<double> Vec,std::string PrintFileName , int Nlines = 0);

//template<typename T4>
void printVec(std::vector<double> Vec , int Nlines = 0);

//void PrintLines(std::vector<std::vector<double>>, int N = 0);

std::vector<double> CalcMagnitudes(std::vector<std::vector<double>>);


std::vector<std::vector<double>> ImportDataToVec(std::string Filename);

double ChiSquared(double p, double q, std::vector<std::vector<double>> data,
        std::vector<std::vector<double>> Errors);

void LeastSquaresFit(std::string FilenameData = "input2D_float.txt",std::string FilenameError = "error2D_float.txt");

double RecursivePower(double x, int y);

std::vector<double> PowerXYvec(std::vector<std::vector<double>> xy);
