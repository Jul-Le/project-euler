#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int longestChain = 0;
    int numberWithLongestChain = 0;
    long long num;

    for (int i = 1; i < 1000000; i++)
    {
        int chain = 0;
        num = i;

        while (num != 1)
        {
            // if even
            if (num % 2 == 0)
            {
                num /= 2;
            }
            // if odd
            else
            {
                num = ((3 * num) + 1);
            }
            chain++;
        };
        if (chain > longestChain)
        {
            longestChain = chain;
            numberWithLongestChain = i;

        }
    }

    cout << numberWithLongestChain << endl;

    return 0;
}
