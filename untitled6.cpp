#include <iostream>

double pi = 3.14159;

int main()
{
    for(double radius=0.0; radius<=10.0; radius++)
    {
        double area = pi*radius*radius;
        double circumference = 2*pi*radius;
        if(radius == 0.0)
        {
            std::cout << "The radius and circumference of a circle with radius " << radius << " are: " << radius << " and " << circumference << ". Obviously since there is no circle!" << std::endl;
        }
        else
        {
            std::cout << "The radius and circumference of a circle with radius " << radius << " are: " << area << " and " << circumference << " respectively." << std::endl;
        }
    }
    return 0;
}
