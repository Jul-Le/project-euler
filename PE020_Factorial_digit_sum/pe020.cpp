#include <iostream>

using namespace std;

int main()
{
    int num[300] { 0 };
    int sum = 0;

    num[2] = 1;

    for (int i = 99; i > 1; i--)
    {
        for (int n = 0; n < 300; n++)
        {
            num[n] *= i;
        }

        for (int n = 0; n < 300; n++)
        {
            if (num[n] > 9)
            {
                num[n] -= 10;
                num[n + 1]++;
                n--;
            }
        }
    }

    for (int i = 0; i < 300; i++)
    {
        sum += num[i];
    }

    cout << sum << endl;

    return 0;
}
