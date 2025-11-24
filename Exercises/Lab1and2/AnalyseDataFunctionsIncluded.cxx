#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

void PrintLines(std::vector<std::vector<double>> xy, int N = 0){

    //N=0 allows print lines to print all lines
    if (N==0){
        N = xy.size();
    }
    //If N is larger than the file size print 5 lines and send the warning
    if (N>= xy.size() && xy.size()>=5){
        std::cout << "You have requested more lines than are in the file." << std::endl;
        N = 5;
    }
    else if (N>= xy.size() && xy.size()<5){
        N = xy.size();
    }

    //print lines up to N
    for (int i=0; i<N  ; i++ ){

        std::cout << i+1 << ") x = " << xy[i][0] << ", y = " << xy[i][1] << std::endl;
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


int main(){


//Create a class for input files 
std::ifstream InputFile{"input2D_float.txt"};

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




PrintLines(xy,50);

return 0;  
}



