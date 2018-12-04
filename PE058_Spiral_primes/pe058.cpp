#include <stdio.h>
#include "isprime.h"

int currentValue;
int sideLength;
int totalSum; // Total diagonals
int primeSum; // Diagonals that are prime
int ratio;    // primes / total

void init() // Start with 3x3
{
    currentValue = 9;
    sideLength   = 3;
    totalSum     = 5;
    primeSum     = 3;

    ratio = primeSum * 100 / totalSum;
}

void findAnswer()
{
    while (ratio >= 10)
    {
        for (int i = 0; i < 4; i++) // Add layer
        {
            if (isPrime(currentValue += sideLength + 1))
                primeSum++;
        }
        totalSum += 4;
        sideLength += 2;

        ratio = primeSum * 100 / totalSum;
    }
}

void printAnswer()
{
    printf("Side length: %d\n", sideLength);
}

int main()
{
    init();
    findAnswer();
    printAnswer();

    return 0;
}
