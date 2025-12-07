#include "FiniteFunctions.h"
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include "CustomFunctions.h"

// import files with 2 elements per row to a vector of 2 element vectors
std::vector<double> ImportRandDataToVec(std::string Filename1){

    //Create a class for input files 
    std::ifstream InputFile{Filename1};

    // set up a string to store each line and doubles to store numbers and one to store seperated data
    std::string InputLine;
    std::vector<double> data;

    //int i =0;
    while (std::getline(InputFile, InputLine)){
        
        data.push_back(std::stod(InputLine));
        /*
        if (i>198){
            break;
        }

        i++;
        */
    }

    return data;
}

int main(){

    std::vector<double> RandomData = ImportRandDataToVec("Outputs/data/MysteryData11110.txt");

     
std::string UserInput;

while (true){

// prompt user for which functionality they need to use
std::cout << "Investigating MysteryData11110" <<std::endl;
std::cout << "What do you want to do?" <<std::endl;
std::cout << "A) Plot data with the default function." <<std::endl;
std::cout << "B) Plot Normal Function with custom parameters." <<std::endl;
std::cout << "C) Plot Cauchy Lorentz Function with custom parameters." <<std::endl;
std::cout << "D) Plot Crystal Ball function with custom parameters." <<std::endl;
std::cout << "E) Plot all functions with a good fit." <<std::endl;
std::cout << "F) Resample and plot the best fit with the metropolis algorithm." <<std::endl;
std::cout << "G) Sample and plot one of the above functions (any parameters) with the metropolis algorithm." <<std::endl;
std::cout << "X) Exit Program" <<std::endl;

std::cin >> UserInput;



if (UserInput == "A"){
    
    FiniteFunction FunctionInstance(-5,5,"DefaultFunction");

    FunctionInstance.plotFunction();
    FunctionInstance.plotData(RandomData,100,true);
    

}
else if (UserInput == "B"){

    std::string UserRangeMinN,UserRangeMaxN,UserStandDivN,UserMeanN;
    
    // prompt user for which functionality they need to use
    std::cout << "Plotting Normal distribution." <<std::endl;
    std::cout << "Enter a number for the minimum x to be plotted." <<std::endl;
    std::cin >> UserRangeMinN;
    std::cout << "Enter a number for the maximum x to be plotted." <<std::endl;
    std::cin >> UserRangeMaxN;
    std::cout << "Enter a number for the Normal distribution standard deviation." <<std::endl;
    std::cin >> UserStandDivN;
    std::cout << "Enter a number for the Normal distribution mean." <<std::endl;
    std::cin >> UserMeanN;



    NormalFunc NormFunctionInstance(std::stod(UserRangeMinN),std::stod(UserRangeMaxN),"NormalFunction",std::stod(UserStandDivN),std::stod(UserMeanN));

    std::cout << "Normal Function Parameters:"<<std::endl;
    std::cout << "Plot minimum: " << NormFunctionInstance.rangeMin() << std::endl;
    std::cout << "Plot maximum: " << NormFunctionInstance.rangeMax() << std::endl;
    std::cout << "Standard Div: " << NormFunctionInstance.getSigma() << std::endl;
    std::cout << "Mean: " << NormFunctionInstance.getMean() << std::endl;

    NormFunctionInstance.plotFunction();
    NormFunctionInstance.plotData(RandomData,100,true);
    

}
else if (UserInput == "C"){

    std::string UserRangeMinCL,UserRangeMaxCL,Userx0CL,UserGammaCL;
    
    // prompt user for which functionality they need to use
    std::cout << "Plotting Cauchy Lorentz function." <<std::endl;
    std::cout << "Enter a number for the minimum x to be plotted." <<std::endl;
    std::cin >> UserRangeMinCL;
    std::cout << "Enter a number for the maximum x to be plotted." <<std::endl;
    std::cin >> UserRangeMaxCL;
    std::cout << "Enter a number for the Cauchy Lorentz function peak position." <<std::endl;
    std::cin >> Userx0CL;
    std::cout << "Enter a number for the Cauchy Lorentz function gamma value (gamma>0)." <<std::endl;
    std::cin >> UserGammaCL;

    CauchyFunc CauchyFunctionInstance(std::stod(UserRangeMinCL),std::stod(UserRangeMaxCL),"CauchyLorentzFunction",std::stod(UserGammaCL),std::stod(Userx0CL));


    std::cout << "Cauchy Lorentz Function Parameters:"<<std::endl;
    std::cout << "Plot minimum: " << CauchyFunctionInstance.rangeMin() << std::endl;
    std::cout << "Plot maximum: " << CauchyFunctionInstance.rangeMax() << std::endl;
    std::cout << "gamma: " << CauchyFunctionInstance.getgamma() << std::endl;
    std::cout << "x0: " << CauchyFunctionInstance.getx0() << std::endl;

    CauchyFunctionInstance.plotFunction();
    CauchyFunctionInstance.plotData(RandomData,100,true);

}
else if (UserInput == "D"){
    
    std::string UserRangeMinC,UserRangeMaxC,Userx0C,UserSigmaC,User_n_C,UserAlphaC;
    
    // prompt user for which functionality they need to use
    std::cout << "Plotting crystal ball function." <<std::endl;
    std::cout << "Enter a number for the minimum x to be plotted." <<std::endl;
    std::cin >> UserRangeMinC;
    std::cout << "Enter a number for the maximum x to be plotted." <<std::endl;
    std::cin >> UserRangeMaxC;
    std::cout << "Enter a number for the Crystal Ball function peak position." <<std::endl;
    std::cin >> Userx0C;
    std::cout << "Enter a number for the Crystal Ball function standard deviation value." <<std::endl;
    std::cin >> UserSigmaC;
    std::cout << "Enter a number for the Crystal Ball function n value (n>1)." <<std::endl;
    std::cin >> User_n_C;
    std::cout << "Enter a number for the Crystal Ball function alpha value (alpha>0)." <<std::endl;
    std::cin >> UserAlphaC;

    CrystalFunc CrystalFunctionInstance(std::stod(UserRangeMinC),std::stod(UserRangeMaxC),"CrystalBallFunction",std::stod(UserSigmaC),
                std::stod(Userx0C),std::stod(User_n_C),std::stod(UserAlphaC));


    std::cout << "Crystal Ball Function Parameters:"<<std::endl;
    std::cout << "Plot minimum: " << CrystalFunctionInstance.rangeMin() << std::endl;
    std::cout << "Plot maximum: " << CrystalFunctionInstance.rangeMax() << std::endl;
    std::cout << "Standard div: " << CrystalFunctionInstance.getSigma() << std::endl;
    std::cout << "Mean: " << CrystalFunctionInstance.getMean() << std::endl;
    std::cout << "alpha: " << CrystalFunctionInstance.getalpha() << std::endl;
    std::cout << "n: " << CrystalFunctionInstance.getn() << std::endl;


    CrystalFunctionInstance.plotFunction();
    CrystalFunctionInstance.plotData(RandomData,100,true);

}
else if (UserInput == "E"){

    NormalFunc NormFunctionInstance(-5,5,"NormalFunctionCloseFit",-2.0,0.8);

    std::cout << "Normal Function Parameters:"<<std::endl;
    std::cout << "Plot minimum: " << NormFunctionInstance.rangeMin() << std::endl;
    std::cout << "Plot maximum: " << NormFunctionInstance.rangeMax() << std::endl;
    std::cout << "Standard Div: " << NormFunctionInstance.getSigma() << std::endl;
    std::cout << "Mean: " << NormFunctionInstance.getMean() << std::endl;

    NormFunctionInstance.plotFunction();
    NormFunctionInstance.plotData(RandomData,100,true);

    CauchyFunc CauchyFunctionInstance(-5,5,"CauchyLorentzFunctionCloseFit",0.75,-2.0);


    std::cout << "Cauchy Lorentz Function Parameters:"<<std::endl;
    std::cout << "Plot minimum: " << CauchyFunctionInstance.rangeMin() << std::endl;
    std::cout << "Plot maximum: " << CauchyFunctionInstance.rangeMax() << std::endl;
    std::cout << "gamma: " << CauchyFunctionInstance.getgamma() << std::endl;
    std::cout << "x0: " << CauchyFunctionInstance.getx0() << std::endl;

    CauchyFunctionInstance.plotFunction();
    CauchyFunctionInstance.plotData(RandomData,100,true);

    CrystalFunc CrystalFunctionInstance(-5,5,"CrystalBallFunctionCloseFit",0.8,-2,2,3);


    std::cout << "Crystal Ball Function Parameters:"<<std::endl;
    std::cout << "Plot minimum: " << CrystalFunctionInstance.rangeMin() << std::endl;
    std::cout << "Plot maximum: " << CrystalFunctionInstance.rangeMax() << std::endl;
    std::cout << "Standard div: " << CrystalFunctionInstance.getSigma() << std::endl;
    std::cout << "Mean: " << CrystalFunctionInstance.getMean() << std::endl;
    std::cout << "alpha: " << CrystalFunctionInstance.getalpha() << std::endl;
    std::cout << "n: " << CrystalFunctionInstance.getn() << std::endl;


    CrystalFunctionInstance.plotFunction();
    CrystalFunctionInstance.plotData(RandomData,100,true);

}

else if (UserInput == "F"){
    CauchyFunc CauchyFunctionSample(-5,5,"CauchyLorentzFunctionBestFitResampled",0.75,-2.0);

    
    
    std::vector<double> SampledData = CauchyFunctionSample.Metropolis(100000,1.0,0);

    CauchyFunctionSample.plotFunction();
    CauchyFunctionSample.plotData(RandomData,100,true);
    CauchyFunctionSample.plotData(SampledData,100,false);
}

else if (UserInput == "G"){

    std::string MetroSampleNo,MetroStandDev,MetroSeed,PlotName,UserRangeMin,UserRangeMax;
    
    // prompt user for which functionality they need to use
    std::cout << "How many samples do you want generated enter a positive integer." <<std::endl;
    std::cin >> MetroSampleNo;
    std::cout << "Enter a number for the standard deviation of the normal function used to generate samples." <<std::endl;
    std::cin >> MetroStandDev;
    std::cout << "Choose a random number generator seed (0 will choose a truely random seed)." <<std::endl;
    std::cin >> MetroSeed;

    std::cout << "Choose a function to sample with the metropolis algorithm." <<std::endl;
    std::cout << "1) Normal Distribution." <<std::endl;
    std::cout << "2) Cauchy Lorentz Function." <<std::endl;
    std::cout << "3) Crystal Ball Function." <<std::endl;

    std::string SampleFuncChoice;
    std::cin >> SampleFuncChoice;


    std::cout << "Enter a name to save the plot under." <<std::endl;
    std::cin >> PlotName;

    std::cout << "Enter a number for the minimum x to be plotted." <<std::endl;
    std::cin >> UserRangeMin;
    std::cout << "Enter a number for the maximum x to be plotted." <<std::endl;
    std::cin >> UserRangeMax;

    std::vector<double> SampledData;

    if (std::stoi(SampleFuncChoice)==1){


            std::string UserStandDivN_sample,UserMeanN_sample;
    
            std::cout << "Enter a number for the Normal distribution standard deviation." <<std::endl;
            std::cin >> UserStandDivN_sample;
            std::cout << "Enter a number for the Normal distribution mean." <<std::endl;
            std::cin >> UserMeanN_sample;
            


            NormalFunc NormFunctionSampleInstance(std::stod(UserRangeMin),std::stod(UserRangeMax),PlotName,
                                            std::stod(UserMeanN_sample),std::stod(UserStandDivN_sample));
            



            SampledData = NormFunctionSampleInstance.Metropolis(std::stoi(MetroSampleNo),std::stod(MetroStandDev),
                                        std::stoi(MetroSeed));

            NormFunctionSampleInstance.plotFunction();
            NormFunctionSampleInstance.plotData(SampledData,100,false);
    }

    else if (std::stoi(SampleFuncChoice)==2){


            std::string Userx0CL_sample,UserGammaCL_sample;
    
             
            std::cout << "Enter a number for the Cauchy Lorentz function peak position." <<std::endl;
            std::cin >> Userx0CL_sample;
            std::cout << "Enter a number for the Cauchy Lorentz function gamma value (gamma>0)." <<std::endl;
            std::cin >> UserGammaCL_sample;

            CauchyFunc CauchyFunctionSampleInstance(std::stod(UserRangeMin),std::stod(UserRangeMax),PlotName,
                                                    std::stod(UserGammaCL_sample),std::stod(Userx0CL_sample));

            SampledData = CauchyFunctionSampleInstance.Metropolis(std::stoi(MetroSampleNo),std::stod(MetroStandDev),
                                        std::stoi(MetroSeed));

            CauchyFunctionSampleInstance.plotFunction();
            CauchyFunctionSampleInstance.plotData(SampledData,100,false);

        }

    else if (std::stoi(SampleFuncChoice)==3){

        std::string Userx0C_sample,UserSigmaC_sample,User_n_C_sample,UserAlphaC_sample;
    
        std::cout << "Enter a number for the Crystal Ball function peak position." <<std::endl;
        std::cin >> Userx0C_sample;
        std::cout << "Enter a number for the Crystal Ball function standard deviation value." <<std::endl;
        std::cin >> UserSigmaC_sample;
        std::cout << "Enter a number for the Crystal Ball function n value (n>1)." <<std::endl;
        std::cin >> User_n_C_sample;
        std::cout << "Enter a number for the Crystal Ball function alpha value (alpha>0)." <<std::endl;
        std::cin >> UserAlphaC_sample;

    CrystalFunc CrystalFunctionSampleInstance(std::stod(UserRangeMin),std::stod(UserRangeMax),PlotName,
            std::stod(UserSigmaC_sample),std::stod(Userx0C_sample),std::stod(User_n_C_sample),std::stod(UserAlphaC_sample));

        SampledData = CrystalFunctionSampleInstance.Metropolis(std::stoi(MetroSampleNo),std::stod(MetroStandDev),
                                        std::stoi(MetroSeed));

        CrystalFunctionSampleInstance.plotFunction();
        CrystalFunctionSampleInstance.plotData(SampledData,100,false);

    }

    else{
        std::cout<< "Invalid choice of function to use try again." <<std::endl; 
        continue;
    }

    
}


else if (UserInput == "X"){
    std::cout << "Exiting" <<std::endl;
    break;
}

else {
    std::cout << "Choose a valid input or exit program" <<std::endl;
}

std::cout << "Would you like to try another option? Press Y to choose another option or any other input to exit." <<std::endl;

std::cin >> UserInput;
if (!(UserInput == "Y")){
    std::cout << "Exiting" <<std::endl;
    break;
}

}

return 0;  


}