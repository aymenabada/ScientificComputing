// Header file containing the code for the Newton solver

// C++ includes
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

// Find the root of the function f(x), starting from an
// initial guess x_init. At most max_iter iterations are
// performed, and the iteration is deemed to have converged
// if |f(x)| < tol. The first two arguments of the function
// are "function pointers" which specify the function f(x)
// (a C++ function that takes a double as an argument and
// returns a double) and its derivative, f'(x) (which has the
// same C++ "signature"). 
double newton_solver(double fct(double),
                     double deriv(double),
                     double x_init,
                     unsigned max_iter,
                     double tol, 
                     std::string convergence_history_filename)
{
    std :: ofstream outfile ( convergence_history_filename . c_str ()); // Open a file to write the convergence history to
 // Initialise the iterate
 double x=x_init;
 
 // Keep iterating until we converge (in which case we
 // return early) or until we've used up all available
 // iterations
 for (unsigned iter=0; iter<max_iter; iter++)
  {
   // Perform Newton iteration step; note how we're using the
   // functions that were passed in through the function's
   // arguments. 
   x -= fct(x)/deriv(x);
   outfile << iter << " " << x << " " << fct(x) << std::endl; // Write the current iteration number, iterate, and function value to the file
   
   // If |f(x)| < tol, we are close enough to the root,
   // so return x
   if (std::abs(fct(x)) < tol) return x;
  }
 
 // If we have not returned already, the iteration has not
 // converged and we bail out and abort the program. 
 std::cout << "ERROR: Iteration did not converge." << std::endl;
 abort();
}
