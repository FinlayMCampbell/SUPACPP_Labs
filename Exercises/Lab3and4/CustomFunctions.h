#include <string>
#include <vector>
#include "FiniteFunctions.h"

#pragma once //Replacement for IFNDEF

class NormalFunc: public FiniteFunction{
    
    public:
        NormalFunc();
        NormalFunc(double range_min, double range_max, std::string outfile, double MeanVal, double SigmaVal);
        NormalFunc(double range_min, double range_max, std::string outfile);
        double callFunction(double x);
        void setMean(double Mean);
        void setSigma(double Sigma);
        double getMean();
        double getSigma();
        
    private: 
        double Normal(double x);

        double m_Sigma;
        double m_Mean;
        
};


class CauchyFunc: public FiniteFunction{
    
    public:
        CauchyFunc();
        CauchyFunc(double range_min, double range_max, std::string outfile, double gamma, double x0);
        CauchyFunc(double range_min, double range_max, std::string outfile);
        double callFunction(double x);

        void setgamma(double gamma);
        void setx0(double x0);
        double getgamma() ;
        double getx0() ;

        
    private: 
        double Cauchy(double x);

        double m_gamma;
        double m_x0;
        
};

class CrystalFunc: public FiniteFunction{
    
    public:
        CrystalFunc();
        CrystalFunc(double range_min, double range_max, std::string outfile, double Sigma, double Mean, double n, double alpha);
        CrystalFunc(double range_min, double range_max, std::string outfile);
        double callFunction(double x);

        void setMean(double Mean);
        void setSigma(double Sigma);
        double getMean();
        double getSigma();
        void setn(double Mn);
        void setalpha(double alpha);
        double getn();
        double getalpha();
        
    private: 
        double Crystal(double x);
        
        double m_Sigma;
        double m_Mean;
        double m_n;
        double m_alpha;

        double A(double n,double alpha);
        double B(double n,double alpha);
};




template<typename T>
int NlineCheck(int Nlines, T Vec, int OversizeDefault );
void printVec(std::vector<double> Vec,std::string PrintFileName , int Nlines );