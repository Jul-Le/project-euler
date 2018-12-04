#include <iostream>
#include "isprime.h"

int main()
{
    // The final answer
    int answer = 0;
    // Temp answer
    int num = 0;
    // Number of consecutive primes
    int consecutivePrimes = 0;
    // ^^Temp
    int temp = 0;
    // Count how many consecutive primes
    int counter = 0;
    // How many to find before test the answer
    int terms = 21;

    int i;
    int a = 2;
    while (a < 10)
    {
        terms = 21;

        // 547 of smallest consecutive primes add up to over a million
        while (terms < 547)
        {
            num = 0;
            temp = 0;
            counter = 0;

            for (i = a; i < 500000; i++)
            {
                if (isPrime(i))
                {
                    num += i;
                    counter++;
                    temp++;

                    if (counter >= terms)
                    {
                        if (isPrime(num))
                        {
                            if (temp > consecutivePrimes && num < 1000000)
                            {
                                consecutivePrimes = temp;
                                answer = num;
                            }
                        }
                        else
                        {
                            terms++;
                            std::cout << answer << " is a sum of " << consecutivePrimes
                                << " consecutive primes." << std::endl;
                            break;
                        }
                    }
                }
            }
        }
        a++;
    }
}
