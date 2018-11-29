#include <iostream>

bool isPrime(unsigned long long n)
{
    // Numbers less than 6 are hard-coded
    if (n < 6)
    {
        switch (n)
        {
            case 2:
            case 3:
            case 5:
                return true;
            default:
                return false;
        }
    }

    // Numbers divisable by 2, 3 or 5 are not prime.
    // All prime numbers are 6n + 1 or 6n - 1
    if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0)
    {
        return false;
    }
    // Try if n is divisable with i
    for (unsigned long long i = 5; (i * i) <= n; i += 6)
    {
        if (n % i == 0 || n % (i+2) == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    unsigned long long sum = 0;

    for (int i = 1; i < 2000000; i++)
    {
        if (isPrime(i))
            sum += i;
    }

    std::cout << sum << std::endl;

    return 0;
}
