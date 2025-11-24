#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

template<typename T>
int NlineCheck(int Nlines, T Vec, int OversizeDefault = 0){
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


//template<typename T1>
//For some reason template doesnt work here - It may be because template below of std::vector<T3> clashes 
// Therefore if we need a vector of vectors of a different type like int we need to define it manually
void printVec(std::vector<std::vector<double>> Vec, int Nlines = 0){
    
    // Change Nlines to a default value (5 lines) if it is out of bounds
    Nlines = NlineCheck(Nlines,Vec,5);
    //print lines up to N
    for (int i=0; i<Nlines  ; i++ ){
        //Number lines only if printed to terminal
        std::cout << i+1 << ")  ";
        for (int j=0; j<Vec[i].size(); j++){
            std::cout  <<Vec[i][j]  << ", ";
            
        }
        std::cout  << std::endl;
    }
}

//template<typename T1>
//For some reason template doesnt work here
void printVec(std::vector<std::vector<double>> Vec,std::string PrintFileName , int Nlines = 0){
    
    // Change Nlines to a default value (full vector) if it is out of bounds
    Nlines = NlineCheck(Nlines,Vec,0);

    // Create and open a text file
    std::ofstream OutputFile(PrintFileName);

    //print lines up to N to a file
    for (int i=0; i<Nlines  ; i++ ){
        // No line count when printing to file
        for (int j=0; j<Vec[i].size(); j++){
            OutputFile  << Vec[i][j] << ", ";
        }
        OutputFile  << std::endl;
    }

    OutputFile.close();

}

//template<typename T3>
void printVec(std::vector<double> Vec,std::string PrintFileName , int Nlines = 0){
    
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

//template<typename T4>
void printVec(std::vector<double> Vec , int Nlines = 0){
    
    // Change Nlines to a default value if it is out of bounds
    Nlines = NlineCheck(Nlines,Vec,0);


    //print lines up to N to a terminal
    for (int i=0; i<Nlines  ; i++ ){
        //1D vector just print each element to a new line on the terminal
        std::cout  <<i+1 << ") "  << Vec[i]<< std::endl;
    }
}



//function creates a vector of the magnitudes of xy data
std::vector<double> CalcMagnitudes(std::vector<std::vector<double>> xyVals){
    
    std::vector<double> Mags;
    //Run through all xy points and add their magnitude to a different vector
    for (std::vector<double> xyElem: xyVals){
        Mags.push_back(std::sqrt(xyElem[0]*xyElem[0]+xyElem[1]*xyElem[1]) );
    }

    return Mags;
}

// import files with 2 elements per row to a vector of 2 element vectors
std::vector<std::vector<double>> ImportDataToVec(std::string Filename1){

    //Create a class for input files 
    std::ifstream InputFile{Filename1};

    // set up a string to store each line and doubles to store numbers and one to store seperated data
    std::string InputLine;



    //Have an integer to skip the first line which is x,y
    int i{0};
    //integer to get position of comma in data 
    int CommaPos{};

    //vectors to hold the x values and the y values

    std::vector<std::vector<double>> xy;


    while (std::getline(InputFile, InputLine)){
    
        // if statement just ignores the text line that is not floats
        if (i>0){
         //seperate data into x and y data and store as vector in a vector of vectors
            CommaPos = InputLine.find(',');
            xy.push_back({std::stod(InputLine.substr(0,CommaPos)),std::stod(InputLine.substr(CommaPos+1))});
        }
        i++;
    }

    return xy;
}


double ChiSquared(double p, double q, std::vector<std::vector<double>> data,
        std::vector<std::vector<double>> Errors){
    //Error if the data size doesnt match the error size
    if (!(data.size()==Errors.size())){
        return -1.0;
    }

    //declare variables
    double y;
    double ChiSum = 0;
    
    //Loop to get all data points
    for (int i=0; i<data.size(); i++){

        //Calculate a least squared estimated y for a given x value
        y = p * data[i][0] + q;

        // Chalculate Chisquared for each point using only the error in y 
        ChiSum += (y-data[i][1])*(y-data[i][1])/((Errors[i][1])*(Errors[i][1]));


    }
    

    return ChiSum;
}

void LeastSquaresFit(std::string FilenameData,std::string FilenameError){
    
    std::vector<std::vector<double>> xy,Errors;
    xy = ImportDataToVec(FilenameData);
    Errors = ImportDataToVec(FilenameError);

    //Calculate all the sums needed for p and q
    double xSquaredSum=0, xSum=0, xySum=0,ySum=0;

    for (std::vector<double> xyElem : xy){
        
        xSquaredSum += xyElem[0] * xyElem[0];
        xSum += xyElem[0];
        xySum += xyElem[0] * xyElem[1];
        ySum += xyElem[1];
    }

    //evaluate p and q
    double p, q;
    p = (xy.size()*xySum - xSum*ySum)/(xy.size()*xSquaredSum- xSum*xSum);
    q = (xSquaredSum*ySum-xySum*xSum)/(xy.size()*xSquaredSum- xSum*xSum);

    //Do the ChiSquared Test
    double ChiSquaredVal = ChiSquared(p,q,xy,Errors);

    // Number of degrees of freedom = Number of points - number of fitted parameters (p,q->2)
    int NDOF = xy.size()-2;

    // Create and open a text file
    std::ofstream LeastSquares("LeastSquaresFit.txt");

    // Write to the file
    LeastSquares << "y = " << std::to_string(p)<< "x + " << std::to_string(q) <<std::endl;

    LeastSquares << "\u03C7^2 /NDOF = " << ChiSquaredVal / NDOF <<std::endl;
    // Close the file
    LeastSquares.close();

    std::cout << "y = " << std::to_string(p)<< "x + " << std::to_string(q) <<std::endl;
    std::cout << "\u03C7^2 /NDOF = " << ChiSquaredVal / NDOF <<std::endl;

}

// calculate x^y
double RecursivePower(double x, int y){

    if (y>1){
        return x*RecursivePower(x,y-1);
    }
    else if (y==1){
        return x;
    }
    else if (y==0){
        return 1;
    }
    else {
        std::cout << "Power function failure" << std::endl;
        return 0;
    }
}

// Take in a vector of 2 element double vectors take each first element raised to the power of the second (rounded)
std::vector<double> PowerXYvec(std::vector<std::vector<double>> xy){

    std::vector<double> PowerResult;

    for (auto xyElem: xy){
        PowerResult.push_back(RecursivePower(xyElem[0],std::round(xyElem[1])));
    }

    return PowerResult;

}




