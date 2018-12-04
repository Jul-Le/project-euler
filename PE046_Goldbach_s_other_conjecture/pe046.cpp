#include <iostream>
#include "isprime.h"

using namespace std;

int main()
{
    int answer = 0;
    bool canBeWritten = true;

    for (int i = 5; answer == 0; i += 2) // Every odd composite number
    {
        if (!isPrime(i))
        {
            for (int j = 2; j < i; j++)
            {
                canBeWritten = false;

                for (int k = 1; k * k < i; k++)
                {
                    if (isPrime(j))
                    {
                        if (j +  (2 * (k * k)) == i)
                        {
                            canBeWritten = true;
                            break;
                        }
                    }
                }
                if (canBeWritten)
                {
                    break;
                }
            }
            if (!canBeWritten)
            {
                answer = i;
            }
        }
    }

    cout << answer << endl;

    return 0;
}
