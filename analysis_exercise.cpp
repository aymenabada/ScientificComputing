#include <iostream>

int main()
{
    double alpha = 3.62;
    double xn = 0.5;

    for (unsigned n = 0; n <= 50; n++)
    {
        std::cout << n << " " << xn << std::endl;

        xn = alpha * xn * (1.0 - xn);
    }

    return 0;
}