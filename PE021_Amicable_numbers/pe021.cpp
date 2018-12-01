#include <iostream>

using namespace std;

int main()
{
    int a = 220;
    int d = 0;
    int d2 = 0;
    int sum = 0;

    while (a != 10000)
    {
        for (int i = 1; i <= a / 2; i++)
        {
            if (a % i == 0)
            {
                d += i;
            }
        }

        for (int i = 1; i <= d / 2; i++)
        {
            if (d % i == 0)
            {
                d2 += i;
            }
        }

        if (a == d2 && a != d)
        {
            sum += d;
        }
        a++;
        d = 0;
        d2 = 0;
    }

    cout << sum << endl;

    return 0;
}
