#include <iostream>
unsigned f0 = 1;
unsigned f1 = 1;
int main()
{
    for(unsigned n=0; n<=100; n++)
    {
        if(n>2)
        {
            unsigned next = f0 + f1;
            std::cout << "The " << n << "th Fibonnaci number is "<< next<< "." << std::endl;
            f0 = f1;
            f1 = next; 
        }
    }
}