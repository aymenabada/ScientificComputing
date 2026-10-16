#include <iostream>
int main()
{
    double sum = 0.0;
    int n_terms = 1000;
    int i = 1;      
    while (i <= n_terms)
    {
        sum+= 1.0/(i*i*i);
        i++; // increase i by 1
    }
    std::cout << "The sum of the series after " << n_terms << " terms is " << sum << std::endl;

    return 0;

}