#include <iostream>
#include <math.h>
#include "isprime.h"

/**************************************************************
void resetArray(numbers)

Fill an array with zeros
**************************************************************/
void resetArray(int* numbers)
{
    for (int i = 0; i < sizeof(numbers); i++)
    {
        numbers[i] = 0;
    }
}

/**************************************************************
int replaceDigit(
number to replace digits from,
index of digit to replace (1 in a byte),
replace with this number)
**************************************************************/
int replaceDigit(int number, unsigned char replaceIndex, int replaceWith)
{
    // Set to-be-replaced digit to zero
    // I have no idea how I came up with this abomination
    number -= ((number % static_cast<int>(pow(10, static_cast<unsigned char>(log2(replaceIndex)) + 1)))
              - number % static_cast<int>(pow(10, static_cast<unsigned char>(log2(replaceIndex)))));
    // Replace digit
    number += replaceWith * static_cast<int>(pow(10, static_cast<unsigned char>(log2(replaceIndex))));

    return number;
}



/**************************************************************
int getRepeatingDigitsIndexes(number)

Get indexes of repeating digits (0...2) of a number

**************************************************************/
unsigned char getRepeatingDigitsIndexes(int number)
{
    // Indexes of repeating digits[0...2][index]
    int indexes[3][8]{ 0 };
    // How many times 0, 1 and 2 repeat in a number
    int repeatingDigits[3]{ 0 };
    for (int x = 100; x < number * 10; x *= 10)
    {
        // Count number of 0s, 1s and 2s
        for (int i = 0; i < 3; i++)
        {
            if (number % x / (x / 10) == i) // n % 100 / 10; n % 1000 / 100 ...
            {
                indexes[i][repeatingDigits[i]] = static_cast<int>(log10(x)) - 1;
                repeatingDigits[i]++;
            }
        }
    }
    unsigned char index = 0x00;

    if (repeatingDigits[0] > repeatingDigits[1] && repeatingDigits[0] > repeatingDigits[2])
    {
        for (int i = 0; i < repeatingDigits[0]; i++)
        {
            index |= (1 << indexes[0][i]);
        }
    }
    else if (repeatingDigits[1] > repeatingDigits[2])
    {
        for (int i = 0; i < repeatingDigits[1]; i++)
        {
            index |= (1 << indexes[1][i]);
        }
    }
    else
    {
        for (int i = 0; i < repeatingDigits[2]; i++)
        {
            index |= (1 << indexes[2][i]);
        }
    }
    return index;
}



/**************************************************************
int getNonzeroElements(byte)

Get number of 1's on a byte
**************************************************************/
int getNonzeroElements(unsigned char numbers)
{
    int nonzeros = 0;

    for (int i = 0; i < 8; i++)
    {
        if (numbers & (1 << i))
        {
            nonzeros++;
        }
    }
    return nonzeros;
}

int main()
{
    bool found = false;
    int n = 1001;
    int test_n;
    // How many same digits in 'n'
    int sameDigitCount;
    int primesInFamily;
    unsigned char repeatingIndexes;
    unsigned char singleIndex;

    while (!found)
    {
        if (isPrime(n))
        {
            // Check if there are multiple zeros, ones or twos
            // If there are, which ones
            // Then replace those with 00...99

            // Count number of repeating digits
            repeatingIndexes = (getRepeatingDigitsIndexes(n));
            sameDigitCount = getNonzeroElements(repeatingIndexes);

            primesInFamily = 0;

            // Replace repeating digits with 00...99
            if (sameDigitCount > 1)
            {
                test_n = n;
                // Replace digits and test if they are primes
                for (int i = 0; i < 10; i++)
                {
                    // test_n = n but digits replaced by i on each iteration
                    for (int j = 0; j < 8; j++)
                    {
                        if (repeatingIndexes & (1 << j))
                        {
                            singleIndex = (1 << j);
                            test_n = replaceDigit(test_n, singleIndex, i);
                        }
                    }
                    if (isPrime(test_n) && test_n > n / 10)
                    {
                        std::cout << test_n << std::endl;
                        primesInFamily++;
                    }
                }
                std::cout << std::endl;
            }

            if (primesInFamily >= 8)
            {
                found = true;
            }
        }
        n += 2;
    }
    return 0;
}
