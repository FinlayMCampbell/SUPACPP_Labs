#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include "CustomFunctions.h"


int main(){

    
std::vector<std::vector<double>> xy;
xy = ImportDataToVec("input2D_float.txt");



std::string UserInput;
std::string Nlines;

while (true){

// prompt user for which function they need to use
std::cout << "Which function do you want to use?" <<std::endl;
std::cout << "A) print N lines" <<std::endl;
std::cout << "B) calculate and print magnitudes" <<std::endl;
std::cout << "C) Find and print the least squares fit formula" <<std::endl;
std::cout << "D) Find and print x^y (with great power comes great responsibility)" <<std::endl;
std::cout << "X) Exit Program" <<std::endl;

std::cin >> UserInput;



if (UserInput == "A"){
    

    std::cout << "How many lines do you want printed? Input an integer (0 for all lines):" <<std::endl;

    std::cin >> Nlines;
    std::cout << "Printing Data:" <<std::endl;

    printVec(xy,stoi(Nlines));

}
else if (UserInput == "B"){

    std::vector<double> Mags = CalcMagnitudes(xy);

    std::cout << "How many lines do you want printed to terminal? Input an integer (0 for all lines):" <<std::endl;
    std::cin >> Nlines;
    std::cout << "Printing magnitudes:" <<std::endl;
    printVec(Mags,stoi(Nlines));
    printVec(Mags,"Magnitudes.txt");

}
else if (UserInput == "C"){
    LeastSquaresFit();
}
else if (UserInput == "D"){
    std::vector<double> Powers = PowerXYvec(xy);
    std::cout << "How many lines do you want printed to terminal? Input an integer (0 for all lines):" <<std::endl;
    std::cin >> Nlines;
    std::cout << "Printing powers:" <<std::endl;
    printVec(Powers,stoi(Nlines));
    printVec(Powers,"Powers.txt",0);


}
else if (UserInput == "X"){
    std::cout << "Exiting" <<std::endl;
    break;
}

else {
    std::cout << "Choose a valid input or exit program" <<std::endl;
}

std::cout << "Would you like to use another function? Press Y to choose another function or any other input to exit." <<std::endl;

std::cin >> UserInput;
if (!(UserInput == "Y")){
    std::cout << "Exiting" <<std::endl;
    break;
}

}

return 0;  
}



