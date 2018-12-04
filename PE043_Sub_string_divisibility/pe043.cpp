#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    vector<int> number(0);
    bool hasProperty = true;
    long long answer = 0;
    long long sum = 0;
    long long multiply = 1000000000;
    int index = 0;
    int primes[7]{ 2, 3, 5, 7, 11, 13, 17 };

    // Initialize vector values to 0123456789
    for (int i = 0; i < 10; i++)
    {
        number.push_back(i);
    }
    swap(*number.begin(), *(number.begin() + 1)); // 1023456789

    for (int i = 1; i < 10000000; i++)
    {
        //  Find the largest index k such that a[k] < a[k + 1].
        for (int k = 8; k >= 0; k--)
        {
            if (number[k] < number[k + 1])
            {
                //  Find the largest index l greater than k such that a[k] < a[l].
                for (int l = 9; l != k; l--)
                {
                    if (number[l] > number[k])
                    {
                        //  Swap the value of a[k] with that of a[l].
                        swap(number[l], number[k]);
                        break;
                    }
                }
                //  Reverse the sequence from a[k + 1] up to and including the final element a[n].
                vector<int>::iterator it = begin(number) + k + 1;
                reverse(it, end(number));
                hasProperty = true;
                index = 0;

                for (vector<int>::iterator itr = number.begin() + 1; itr < number.end() - 2; itr++)
                {
                    int num = 0;
                    int multiplier = 100;

                    for (int n = 0; n < 3; n++)
                    {
                        num += *(itr + n) * multiplier;
                        multiplier /= 10;
                    }
                    if (num % primes[index] != 0)
                    {
                        hasProperty = false;
                        break;
                    }
                    index++;
                }
                sum = 0;
                multiply = 1000000000;

                if (hasProperty)
                {
                    for (int x : number)
                    {
                        sum += x * multiply;
                        multiply /= 10;
                    }
                    cout << sum << endl;
                    answer += sum;
                }
                break;
            }
        }
    }
    cout << "Total: " << answer << endl;

    return 0;
}
