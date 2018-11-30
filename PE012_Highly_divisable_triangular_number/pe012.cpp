#include <iostream>

using namespace std;

// Slow af
int main()
{
    // Current triangle number
    int sum = 0;
    // Number of factor for that number, every number has factors of 1 and the number itself
    int numberOfFactors = 2;

    // Add numbers to triangle number
    for (int i = 1;; i++)
    {
        sum += i;

        // Skip all odd numbers
        if (sum % 2 == 0)
        {
            // Divide every even triangle number with number from 2 to half of the current number
            for (int n = 2; n <= (sum / 2); n++)
            {
                    if (sum % n == 0)
                    {
                        numberOfFactors++;
                    }
            }

            if (numberOfFactors > 500)
            {
                cout << sum << endl;
                break;
            }

            numberOfFactors = 2;
        }
    }

    return 0;
}
