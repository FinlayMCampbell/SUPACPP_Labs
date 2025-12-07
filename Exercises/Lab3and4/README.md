# Assignment 2

The makefile provided should complile the program to an executable called TestFiniteFunctions from FiniteFunctions.cxx, CustomFunctions.cxx and TestFiniteFunctions.cxx plus the associated header files.

The program is hard coded to use MysteryData11110.txt to change this the file would need to be changed to replace the import of this data


## Edits

I have edited FiniteFunctions to add the integrator. I have used the tapezoid rule to integrate an arbitary function.
I have added CustomFunctions.cxx and the header file to create classes for each function asked for. The metropolis algorithm is also defined here so I have added a metropolis algorithm to the finite functions header file.
I have added TestFiniteFunctions.cxx to impliment a user interface to use the different functionality.

## User guide

When running the program there are several options to choose to explore the possibilities.
Option A plots the already coded default function with the data but this is just there for completeness as it doesn't do much.

Option B allows the user to specify any parameters for the normal function then plots them with the data under the name NormalFunction.png.

Option C allows the user to specify any parameters for the Cauchy Lorentz function then plots them with the data under the name CauchyLorentzFunction.png.

Option D allows the user to specify any parameters for the Crystal Ball function then plots them with the data under the name CrystalBallFunction.png. 

Options B-D are designed allow replotting to get close to matching the data.

Option E plots all of the above functions as close a match to the data as I could get. This option is designed to show how I decided what the real data was sampled from. It plots each function as (function)CloseFit.png. The best fit is Cauchy Lorentz function with mean -2 and standard deviation 0.75.

Option F uses the closesest fit to the data (Cauchy Lorentz function with mean -2 and standard deviation 0.75) and resamples this function then plots it with the original and resampled data. It names the output CauchyLorentzFunctionBestFitResampled.png

Option G allows any parameters for any of the three functions to be selected then sampled with the metropolis algorithm. This is to show the code can resample the functions for general parameters. Here since I had no particular outputs in mind the user must input the file name. This is also plotted without the mystery data as it doesn't correspond to that.

## Notes

For the crystal ball function it is defined unnormalised as the integrator is used to normalise it later and normalising it by hand had a lot of steps to find C,D given in the assignment.

The metropolis algorith method returns a vector<double> of all of the data. I do not save this to a file but I do include a function PrintVec(vector<double>,string Filename,int Nlines) which would print Nlines of this to a file with the name given by the string filenameg. Nlines=0 defaults to printing the whole vector. 

In option F the metropolis algorithm uses an arbitrary standard deviation of 1 as this seemed to work well but in option G the user can specify this.

The metropolis takes a seed for the random number generator if seed is set to zero it produces a random number for the seed which is printed in case the results need to be exactly reproduced.

In general the code should prompt the user for anything they want to do.


## Calculate Pi

make CalculatePi compiles CalculatePi.cxx to CalculatePi.
Running this with two command line arguments in order Radius and NRandom estimates Pi using a sample of random numbers

The radius actually doesn't matter but is used in the calculation. More samples gets a more accurate answer but I didn't get to 10 decimal places because it was too slow.

The program basically randomly generates points in a square from -radius to radius then tests if each point is in the circle and counts how many are in the circle.

The ratio of points in circle to total sampled points is related to Pi




