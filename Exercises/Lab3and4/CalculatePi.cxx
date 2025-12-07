#include <vector>
#include <string>
#include <cmath>
#include <random>
#include <iostream>




int main(int argc, char *argv[]){

    if (argc != 3){
        std::cout << "Wrong number of command line arguments" <<std::endl;
        return 1;
    }

    //Take in data
    std::string Input1 = argv[1], Input2 = argv[2];

    int Nrandom = std::stoi(Input2);

    double Radius = std::stod(Input1);

    // create true random seed
    std::random_device rd;

    //Create a pseudo random generator with the seed
    std::mt19937 mtEngine(rd());

    //set up a double to store an x any y coordiate for each step
    double xCoord,yCoord;

    //sample points in a uniform square bounded by +- radius
    std::uniform_real_distribution<double> uniformPDF(-Radius,Radius);


    //set up an integer to count points that are inside the circle
    int CircleCount=0;

    for (int i=0;i<Nrandom;i++){

        //randomly sample in the square
        xCoord = uniformPDF(mtEngine);
        yCoord = uniformPDF(mtEngine);

        //check if point lies in the circle and if it does increment the counter

        if (xCoord*xCoord+ yCoord*yCoord < Radius*Radius){
            CircleCount++;

        }

    }
    /*
    The area of the square is 4*Radius^2 and the area of the circle is Pi*Radius^2
    Since the points are uniformly sampled from the square area the number of samples / number in the circle gives the area ratio between the circle and square
    This should be independent of the radius

    Pi is then given by 4*the number of points in the circle/the number of points sampled
    */

    double Pi_estimate = (4.0*CircleCount)/(Nrandom);

    std::cout << "Pi is approximately: " << Pi_estimate <<std::endl;

    return 0;




}