#include <iostream>

int main()
{
    int a = 1;  // smaller number
    int b = 1;  // larger number
    int c;      // sum
    int d;      // old value
    int sum = 0;

    while (b <= 4000000)
    {
        c = a + b;
        d = b;
        b = c;
        a = d;

        if (a % 2 == 0)
        {
            sum += a;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
