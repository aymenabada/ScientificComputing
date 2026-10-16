#include <iostream>
double alpha = 3.2;
double xn = 0.5; //define the alpha constant and initial x0 value
int main() // start our function
{
    for(unsigned n=0; n<51; n++) // start for loop iterating 51 times
    {
        double xnplus1 = alpha * xn * (1 - xn); // defining the logistic map function 
        std::cout << n << "" << xn << std::endl; // print the current iteration
        xn = xnplus1; // update the value for xn
    }
return 0; // end the function
}

