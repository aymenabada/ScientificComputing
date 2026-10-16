// C++ headers for input/output
#include <iostream>

// Sqrt comes from here
#include <cmath>


int main()
{
 // Let's denote the n-th Fibonacci number by f_n, where n=0,1,2...
 // With this enumeration, we want the first 15 values
 unsigned n_wanted = 15; 

 // We're starting with the computation of f_2, given the
 // the current value (f_1) and the previous one (f_0);
 unsigned n_current=1;
 
 // Current value (initialised for the first step which advances to f_2)
 unsigned f_current = 1;
 
 // Previous value (initialised for the first step which advances to f_2)
 unsigned f_previous = 1;


 // Parameters for the explicit result from
 // https://en.wikipedia.org/wiki/Fibonacci_sequence#Closed-form_expression
 double psi=(1.0-sqrt(5.0))/2.0;
 double phi=-1.0/psi;
            
 
 // Output (index, result by iteration, explict result;
 // the latter obviously the same during the intitialisation)
 // the first two values 
 
 // Zeroth step
 unsigned n=0;
 double f=f_previous;
 std::cout << n << " " << f << " " << f << " " << std::endl;
 
 // First step
 n=1;
 f=f_current;
 std::cout << n << " " << f << " " << f << " " << std::endl;

 
 // Now loop to advance to the next one
 while (n_current < n_wanted) 
  {
   // Back up current value
   unsigned backup_f_current = f_current;
   
   // Move to the next one
   n_current++;
   f_current = f_current + f_previous;

   // Explicit result from Wikipedia
   double f_explicit=
    (pow(phi,n_current+1)-pow(psi,n_current+1))/(phi-psi);
   
   // Show us the result: index, result by iteration, result from explicit
   // expression
   std::cout << n_current  << " "
             << f_current  << " "
             << f_explicit << " "
             << std::endl;
   
   // Update the previous one
   f_previous = backup_f_current;
  }
 
 return 0;
}
