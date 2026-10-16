#include <iostream>
double pi = 3.141592653589793;

int main()
{
    for (double r = 0.0; r<=10.0; r++)
    {
        double area = pi*r*r;
        double circumference = 2*pi*r;
        std::cout << "The area of a circle with radius r = " << r << " is " << area << std::endl;
        std::cout << "The circumference of a circle of radius r = " << r<< " is " << circumference<< std::endl;
    }
    return 0;

}

