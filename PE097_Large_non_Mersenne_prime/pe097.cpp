#include <iostream>

int main()
{
    unsigned long long lastDigits = 28433;

    for (int i = 0; i < 7830457; i++)
    {
        lastDigits *= 2;
        lastDigits %= 10000000000;
    }

    std::cout << ++lastDigits << std::endl;

    return 0;
}
