#include <iostream>
#include <math.h>

using namespace std;

int abc(int a, int b)
{
    return pow(a, 2) + pow(b, 2);
}

int main()
{
    int a, b, c;

    for (a = 0; a < 1000; a++)
    {
        for (b = 0; b < 1000; b++)
        {
            if (a < b)
            {
                for (c = 0; c < 1000; c++)
                {
                    if (b < c)
                    {
                        if (abc(a, b) == pow(c, 2))
                        {
                            if (a + b + c == 1000)
                            {
                                cout << a * b * c << endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
}
