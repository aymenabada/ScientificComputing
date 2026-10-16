#include <iostream>

int i = 1;
int j = 2;

int main2()
{
    std::cout << i << j << std::endl;
    return 0;
}

int main()
{
    int i = 5;
    int j = 6;
    int k = 7;

    std::cout << i << j << std::endl;

    main2();  // calls main2()
}