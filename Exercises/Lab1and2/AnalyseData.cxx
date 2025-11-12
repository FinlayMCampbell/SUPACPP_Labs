#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void PrintLines(std::vector<std::vector<double>> xy, int N = 0){

    if (N==0 || N>= xy.size()){
        N = xy.size();
    }

    for (int i=0; i<N  ; i++ ){

        std::cout << i+1 << ") x = " << xy[i][0] << ", y = " << xy[i][1] << std::endl;
    }

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
    //std::cout << InputLine << std::endl;
    if (i>0){
        CommaPos = InputLine.find(',');
        xy.push_back({std::stod(InputLine.substr(0,CommaPos)),std::stod(InputLine.substr(CommaPos+1))});
        }
    i++;
    
    

    }




PrintLines(xy,50);
/*
for (std::vector<double> xyElem: xy){
        std::cout << "x = " << xyElem.at(0) << ", y = " << xyElem.at(1) << std::endl;
    }*/
return 0;  
}



