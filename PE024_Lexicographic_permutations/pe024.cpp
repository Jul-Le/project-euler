#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> digits(0);

    // Initialize vector values to 0123456789
    for (int i = 0; i < 10; i++)
    {
        digits.push_back(i);
    }

    for (int i = 1; i < 1000000; i++)
    {
        //  Find the largest index k such that a[k] < a[k + 1].
        for (int k = 8; k >= 0; k-- )
        {
            if (digits[k] < digits[k + 1])
            {
                //  Find the largest index l greater than k such that a[k] < a[l].
                for (int l = 9; l != k; l--)
                {
                    if (digits[l] > digits[k])
                    {
                        //  Swap the value of a[k] with that of a[l].
                        swap(digits[l], digits[k]);
                        break;
                    }
                }
                //  Reverse the sequence from a[k + 1] up to and including the final element a[n].
                vector<int>::iterator it = begin(digits) + k + 1;
                reverse(it, end(digits));
                break;
            }
        }
    }

        for (int x : digits)
        {
            cout << x;
        }
        cout << endl;

    return 0;
}
