#include <iostream>
#include <cmath>

void quadraticroots(double a, double b, double c)
{
    double delta = b*b - 4*a*c;
    if(delta >0)
    {
        double x1 = (-b + sqrt(delta))/(2*a);  
        double x2 = (-b - sqrt(delta))/(2*a);
        std::cout <<"The roots of the quadratic are "<< x1<< " and " << x2<< "." <<  std::endl;
    }

    else if(delta == 0)
    {
        double x = -b/(2*a);
        std::cout << "The root of the quadratic is "<< x<< "." << std::endl;
    }

    else 
    {
        double A = -b/(2*a);
        double B = sqrt(-delta/(2*a));
        std::cout << "The complex roots of the quadratic are "<< A << "+i" << B << " and " << A << "-i." <<  std::endl;
    }

}

int main() 
{
    quadraticroots(1,2,3);
    return 0;
}