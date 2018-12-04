#include <iostream>

using namespace std;

int main()
{
    unsigned long long answer = 0;
    unsigned long long product;

    for (int i = 1; i <= 1000; i++)
    {
        product = 1;
        for (int j = 0; j < i; j++)
        {
            product *= i;
            {
                while (product > 999999999999999)
                {
                    product -= 1000000000000000;
                }
            }
        }
        answer += product;
    }

    cout << answer << endl;

    return 0;
}
