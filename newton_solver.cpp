// c++ includes
#include <iostream>

// Include code for Newton solver
#include "analysis_exercise2.h"

// The function whose zero we're trying to find: f(x)
double function(double x)
{
 return 9.0*x*x*x*x - 42.0*x*x*x - 1040.0*x*x + 5082.0*x - 5929;
}

// The derivative f'(x) of the function whose zero we're
// trying to find.
double derivative(double x)
{
 return 4.0*9.0*x*x*x - 3.0*42.0*x*x - 2.0*1040.0*x + 5082.0;
}


// Driver code
int main()
{ 
 // Provide initial guess
 double x_init=0.0;
 std::cout
  << "Please enter an initial guess for the Newton method: ";
 std::cin >> x_init;

 // Call the Newton solver with 100 iterations and a
 // tolerance of 10^-6. Note how the two (global) functions,
 // function(...) and derivative(...) are passed to the solver.
 unsigned max_iter=100;
 double tol=1.0e-6;
 double x = newton_solver(function, derivative,
                          x_init, max_iter, tol, "iterations_history_filename.txt");

 // Tell us what we got
 std::cout << "We converged to a solution x = " << x
           << " for which |F(x)| = " << std::abs(function(x))
           << std::endl;

 // Done
 return 0;
}
