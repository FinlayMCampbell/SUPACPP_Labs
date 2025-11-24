#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include "CustomFunctions.h"

void Checker(int x){

    std::cout << x << std::endl;
}


int main(){

    std::cout << std::round(5.4) << ", " << std::round(7.8)<< std::endl;

    Checker(std::round(2.2));


}