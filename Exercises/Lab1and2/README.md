# Assignment 1 Work

The files AnalyseData.cxx, CustomFunctions.cxx can be compiled together (Needing CustomFunctions.h) to give the executable DataAnalysisExecutable. 
In order for this to run properly for all functionality it needs a correctly formatted input2D_float.txt and error2D_float.txt in the directory as provided by the class.

The provided makefile should compile these into DataAnalysisExecutable along with removing intermidiate objects using a make clean command.
make cleantarget will remove the executable.

## Use of main executable file

When running the DataAnalysisExecutable it will print text to terminal asking which of 4 core operations the user wishes to use. 
Which function do you want to use?
A) print N lines
B) calculate and print magnitudes
C) Find and print the least squares fit formula
D) Find and print x^y (with great power comes great responsibility)
X) Exit Program

Entering the letter corresponding to each of these tasks will perform that function. When an entire files worth of data will print it will prompt for how many lines to print to the terminal where 0 will print the entire file. Note when making new files these files will always contain every line.

After a non valid input or any of the functions the code will ask if the user wants to choose another option. Entering Y will repeat the process. Any other string input will exit the code.

Option B will create a text file of results called Magnitudes.txt
Option C will create a text file of results called LeastSquaresFit.txt
Option D will create a text file of results called Powers.txt

### Implementation notes 

To create the interface to select an option I used several if ... else if... else if statements. the switch function does a similar thing but does not accept string inputs and I wanted by inputs to be A, B, C ect instead of numbers (or inputs interpreted strictly as characters) so I decided not to use switch. Casting the strings to individual characters would likely have worked but I didn't want to.

## Functions 
The CustomFunctions.cxx and associated CustomFunctions.h header file define all of the functions used.

### printVec
This function takes a first argument as a vector of doubles or a vector of vectors of doubles.
Each of the elements of this vector are printed comma seperated when there is multiple entries per line. 

There is an optional (by function overloading) second argument which is a string. If this string is present the data will print to a text file of that name. Otherwise it will print to terminal.

The last argument is a number of lines to print which is default as 0 which will be interpreted as print every line.

The number of lines argument is checked to make sure it is not larger than the length of the vector and is changed to a default if it is. A value of 0 is also reinterpreted as the size of the number input vector.

### CalcMagnitudes
This function has one argument of a vector of vectors of doubles interpreted as x,y data.

It returns a vector of doubles which is the magnitude calculated from x and y


### ImportDataToVec

This function takes in a string corresponding to a filename of a txt file with rows of two comma seperated values then stores these in a vector where each element is a 2 element vector of doubles to store these values.
Therefore each element of the output corresponds to one row of data stored as a two element vector where index 0 is x data and index 1 is y data.

Note this skips line 1 which contains the text x,y which is not a number


### ChiSquared

The first two arguments are doubles containing p and q respectively for a straight line fitting y=px+q. 
The next two arguments are vectors of vectors of doubles that contain the data that has been fitted and the error in that data.
The only error that comes into the calculation is the error in the y data.

The function returns the final Chi^2 value for the fit

### Least squares fit

The arguments of this function is a filepath for the data to be fitted and a filepath for the error in that data.
These are automatically imported then the data is fit to a straight line and the Chi^2 test is calculated.

The fitting and the value of the chi^2/NDOF test are both formatted as strings then output to the terminal and a file called LeastSquaresFit.txt
This function does its own printing and does not return anything

Note that the number of degrees of freedom is chosen as 23 because there are 25 bits of data and 2 parameters (p and q) fit so 25-2 = 23 independent degrees of freedom.

### RecursivePower

This has a double argument x and an integer argument y and returns the value of x^y as a double


### PowerXYvec

This takes in a vector of vectors of doubles representing x and y data.
The function loops through the outer vector and performs the recursive power function on each of the inner vectors.
The first element is interpreted as a double as x the second element is rounded to an integer and interpreted as y. The function returns a vector of doubles representing x^y. The indices are designed to line up with the input data.






