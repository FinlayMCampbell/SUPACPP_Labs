#include <iostream>
#include <cmath>

void Magnitude(double x, double y){

    double mag = std::sqrt(x*x+y*y);
    std::cout << mag << std::endl;

}


int main(){

    std::cout << "Hello World" <<std::endl;
    double x = 7.5, y=3.4;

    double mag = std::sqrt(x*x+y*y);

    std::cout << mag << std::endl;

    Magnitude(7.5,3.4);

}