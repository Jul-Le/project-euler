#include <iostream>
#include <math.h>
#include "isprime.h"
#include "progressbar.h"

int removeFirstDigit(int num, int digits);
int getmsd(int num, int digits);
int numberOfDigits(int num);

bool hasEvenDigits(int num);
bool isCircular(int num);

void rotate(int &num);

bool hasEvenDigits(int num)
{
    // Check if any digit is
    // divisable by 2 or 5

    int digits = numberOfDigits(num);
    int x = 0;
    for (int i = 10; x < digits; i *= 10)
    {// 255653
        if (!((num % i / (i / 10)) % 2) || !((num % i / (i / 10)) % 5))
        {
            return true;
        }
        x++;
    }
    return false;
}

int removeFirstDigit(int num, int digits)
{
    return num %= static_cast<int>(pow(10, digits - 1));
}

int getmsd(int num, int digits)
{
    // return first digit of a number
    return num / static_cast<int>(pow(10, digits - 1));
}

int numberOfDigits(int num)
{
    int digits = 1;

    for (int x = 10; x <= 1000000; x *= 10)
    {
        if (x > num)
        {
            return digits;
        }
        digits++;
    }
    return 0;
}

void rotate(int &num)
{
    // Get number of digits
    int numOfDigits = numberOfDigits(num);

    // Most Signigicant Digit
    int msd = getmsd(num, numOfDigits);

    // Remove first digit
    num = removeFirstDigit(num, numOfDigits);

    // Add MSD to the front
    num *= 10;
    num += msd;
}

bool isCircular(int num)
{
    int original = num;

    if (num > 10)
    {
        if (hasEvenDigits(num))
        {
            return false;
        }
    }

    do
    {
        rotate(num);

        if (!isPrime(num))
        {
            return false;
        }

    } while (num != original);

    return true;
}

int main()
{
    ProgressBar *bar = new ProgressBar;

    int primes = 0;

    for (int i = 2; i < 1000000; i++)
    {
        if (isPrime(i))
        {
            if (isCircular(i))
            {
                primes++;
            }
        }
        bar->update(i, 999999);
    }

    delete bar;

    std::cout << std::endl << primes << std::endl;
    return 0;
}
