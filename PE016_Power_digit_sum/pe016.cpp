#include <iostream>

using namespace std;

int main()
{
    int sum = 0;

    // Array to store the big number
    int num[302] = { 0 };
    // 2^0
    num[0] = 1;

    // Multiply by 2 1000 times
    for (int i = 0; i < 1000; i++)
    {

        for (int j = 0; j < 302; j++)
        {
            // Multiply every index by 2
            num[j] *= 2;
        }

        for (int k = 0; k < 302; k++)
        {
            if (num[k] > 9)
            {
                // If number goes above 9, subtract 10 from it...
                num[k] -= 10;
                // ...and add 1 to next index
                num[k + 1] += 1;
            }
        }
    }

    // Print the sum of the digits

    for (int i = 0; i < 302; i++)
    {
        sum += num[i];
    }

    cout << sum << endl;

    return 0;
}
