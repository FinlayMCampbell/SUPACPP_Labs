#include "FiniteFunctions.h"
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include "CustomFunctions.h"
#include <cmath>
#include <random>
#include <functional>
#include <algorithm>

// Normal function constructors

NormalFunc::NormalFunc(){
    FiniteFunction();
    m_Mean = 0;
    m_Sigma = 1;
}

NormalFunc::NormalFunc(double range_min, double range_max, std::string outfile,double MeanVal, double SigmaVal)
:FiniteFunction(range_min, range_max, outfile)
{
    m_Mean = MeanVal;
    m_Sigma = SigmaVal;
}

NormalFunc::NormalFunc(double range_min, double range_max, std::string outfile)
:FiniteFunction(range_min, range_max, outfile)
{
    m_Mean = 0;
    m_Sigma = 1;
}


// normal function cals
double NormalFunc::callFunction(double x){return this->Normal(x);};

double NormalFunc::Normal(double x){

    return (1.0/(m_Sigma*std::sqrt(M_PI*2)))*std::exp(-((x-m_Mean)*(x-m_Mean)/(m_Sigma*m_Sigma))/2);
}

/*
###################
//Setters
###################
*/ 
void NormalFunc::setMean(double Mean) {m_Mean = Mean;};
void NormalFunc::setSigma(double Sigma) {m_Sigma = Sigma;};

/*
###################
//Getters
###################
*/ 
double NormalFunc::getMean() {return m_Mean;};
double NormalFunc::getSigma() {return m_Sigma;};

// Cauchy function constructors
CauchyFunc::CauchyFunc(){
    FiniteFunction();
    m_x0 = 0;
    m_gamma = 1;
}

CauchyFunc::CauchyFunc(double range_min, double range_max, std::string outfile,double gamma, double x0)
:FiniteFunction(range_min, range_max, outfile)
{
    m_gamma = gamma;
    m_x0 = x0;
}

CauchyFunc::CauchyFunc(double range_min, double range_max, std::string outfile)
:FiniteFunction(range_min, range_max, outfile)
{
    m_x0 = 0;
    m_gamma = 1;
}


// cauchy function calls
double CauchyFunc::callFunction(double x){return this->Cauchy(x);};

double CauchyFunc::Cauchy(double x){

    return 1/(M_PI*m_gamma*(1+(x-m_x0)*(x-m_x0)/(m_gamma*m_gamma)));
}

/*
###################
//Setters
###################
*/ 
void CauchyFunc::setgamma(double gamma) {m_gamma = gamma;};
void CauchyFunc::setx0(double x0) {m_x0 = x0;};

/*
###################
//Getters
###################
*/ 
double CauchyFunc::getgamma() {return m_gamma;};
double CauchyFunc::getx0() {return m_x0;};

// constuctors for crystal ball function

CrystalFunc::CrystalFunc(){
    FiniteFunction();
    m_Sigma = 1;
    m_Mean = 0;
    m_n = 1;
    m_alpha = 1;
}

CrystalFunc::CrystalFunc(double range_min, double range_max, std::string outfile, double Sigma, double Mean, double n, double alpha)
:FiniteFunction(range_min, range_max, outfile)
{
    m_Sigma = Sigma;
    m_Mean = Mean;
    m_n = n;
    m_alpha = alpha;

}

CrystalFunc::CrystalFunc(double range_min, double range_max, std::string outfile)
:FiniteFunction(range_min, range_max, outfile)
{
    m_Sigma = 1;
    m_Mean = 0;
    m_n = 1;
    m_alpha = 1;
}


// call crystal ball function
double CrystalFunc::callFunction(double x){return this->Crystal(x);};

double CrystalFunc::A(double n, double alpha){
    return pow(n/std::abs(alpha),n)*std::exp(-std::abs(alpha)*std::abs(alpha)/2);
}

double CrystalFunc::B(double n, double alpha){
    return (n/std::abs(alpha)) - std::abs(alpha);
}

// Note this generates an unnormalised crystal ball function but the integral normalises this
double CrystalFunc::Crystal(double x){
    
    if (((x-m_Mean)/m_Sigma) > -m_alpha ){
        return std::exp(-((x-m_Mean)*(x-m_Mean)/(2*m_Sigma*m_Sigma)));
    }
    else {
        return (this -> A(m_n,m_alpha))*pow((this-> B(m_n,m_alpha)) -(x-m_Mean)/(m_Sigma),-m_n);
    }
}


/*
###################
//Setters
###################
*/ 
void CrystalFunc::setMean(double Mean) {m_Mean = Mean;};
void CrystalFunc::setSigma(double Sigma) {m_Sigma = Sigma;};
void CrystalFunc::setn(double n) {m_n = n;};
void CrystalFunc::setalpha(double alpha) {m_alpha = alpha;};

/*
###################
//Getters
###################
*/ 
double CrystalFunc::getMean() {return m_Mean;};
double CrystalFunc::getSigma() {return m_Sigma;};
double CrystalFunc::getn() {return m_n;};
double CrystalFunc::getalpha() {return m_alpha;};




/*
###################
//Metropolis call
###################
*/ 

std::vector<double> FiniteFunction::Metropolis(int NSamples, double NormalStandDiv , int seed){

    // Create a truely random seed for the engine
    if (seed == 0){
        std::random_device rd;
        seed = rd();

        std::cout << "The random seed is " << seed << std::endl;
    }

    //Create a pseudo random generator with the seed
    std::mt19937 mtEngine(seed);

    //set up a vector to store each sample
    std::vector<double> samples;

    //sample first point in the range
    std::uniform_real_distribution<double> uniformPDF(m_RMin,m_RMax);
    double Working_xi = uniformPDF(mtEngine);
    samples.push_back(Working_xi);

    //Create a function to sample uniformly 0<T<1 
    std::uniform_real_distribution<double> TuniformPDF(0,1);

    //Create variables to store A and y
    double A, y;


    //run the algorithm N-1 times note since x_0 is already set above
    for (int i=0 ; i<NSamples; i++){

        // Generate a gaussian centred on x_i and sample a point
        std::normal_distribution<double> NormalPDF(Working_xi,NormalStandDiv);
        y = NormalPDF(mtEngine);

        // Do the steps to decide if x_(i+1) = x_i or if x_(i+1) = y for metropolis algorithm
        A = std::min((this -> callFunction(y))/(this -> callFunction(Working_xi)),1.0);
        if (TuniformPDF(mtEngine) < A){
            Working_xi = y;
        }

        //add x_(i+1) to the sample
        samples.push_back(Working_xi);

    }

    //return just the samples 
    return samples;
    
    }







template<typename T>
int NlineCheck(int Nlines, T Vec, int OversizeDefault ){
    //Change the number of printed lines to a default value if it is over the size of the vector
    
    //If N is larger than the file size print 5 lines and send the warning
    if (Nlines>= Vec.size() && Vec.size()>=OversizeDefault){
        std::cout << "You have requested more lines than there are. Printing 5 lines" << std::endl;
        Nlines = OversizeDefault;
    } //if there are less than default lines in the vector and more than default are requested print the whole vector
    else if (Nlines>= Vec.size() && Vec.size()<OversizeDefault){
        Nlines = Vec.size();
    }

    //N=0 allows print lines to print all lines
    if (Nlines==0){
        Nlines = Vec.size();
    }
    return Nlines;

}

//print to file
void printVec(std::vector<double> Vec,std::string PrintFileName , int Nlines){
    
    // Change Nlines to a default value if it is out of bounds
    Nlines = NlineCheck(Nlines,Vec,0);

    // Create and open a text file
    std::ofstream OutputFile(PrintFileName);

    //print lines up to N to a file
    for (int i=0; i<Nlines  ; i++ ){
        //1D vector just print each element to a new line in a file 
        OutputFile  << Vec[i]<< std::endl;
    }

    OutputFile.close();

}


