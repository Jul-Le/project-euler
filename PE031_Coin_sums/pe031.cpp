#include <stdio.h>

int bruteForceIsLove_bruteForceIsLife()
{
    int _200 = 0;
    int _100 = 0;
    int _50 = 0;
    int _20 = 0;
    int _10 = 0;
    int _5 = 0;
    int _2 = 0;
    int _1 = 0;
    int sum = 0;

    for (_200 = 0; _200 * 200 <= 200; _200++)
    {
        for (_100 = 0; _100 * 100 <= 200; _100++)
        {
            for (_50 = 0; _50 * 50 <= 200; _50++)
            {
                for (_20 = 0; _20 * 20 <= 200; _20++)
                {
                    for (_10 = 0; _10 * 10 <= 200; _10++)
                    {
                        for (_5 = 0; _5 * 5 <= 200; _5++)
                        {
                            for (_2 = 0; _2 * 2 <= 200; _2++)
                            {
                                for (_1 = 0; _1 * 1 <= 200; _1++)
                                {
                                    if (_200 * 200 + _100 * 100 + _50 * 50 + _20 * 20 + _10 * 10 + _5 * 5 + _2 * 2 + _1 * 1 == 200)
                                        sum++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return sum;
}

int main()
{
    printf("%d\n", bruteForceIsLove_bruteForceIsLife());

    return 0;
}
