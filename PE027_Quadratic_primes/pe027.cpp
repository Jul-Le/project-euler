#include <iostream>
#include "isprime.h"

using namespace std;

int main()
{
    int n = 0;
    int numberOfPrimes = 0;
    int maximumNumberOfPrimes = 0;
    int answer = 0;

    for (int a = -999; a < 1000; a++)
    {
        for (int b = -1000; b <= 1000; b++)
        {
            n = 0;
            while (true)
            {
                if ((n * n + (a * n) + b) > 0)
                {
                    if (isPrime(n * n + (a * n) + b))
                    {
                        n++;
                        numberOfPrimes++;
                        if (numberOfPrimes > maximumNumberOfPrimes)
                        {
                            maximumNumberOfPrimes = numberOfPrimes;
                            answer = a * b;
                        }
                    }
                    else
                    {
                        n++;
                        break;
                    }
                }
                else
                {
                    n++;
                }
            }
            numberOfPrimes = 0;
        }
    }

    cout << answer << endl;

    return 0;
}
