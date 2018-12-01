#include <iostream>

using namespace std;

int main()
{
    unsigned long long first = 1;
    unsigned long long second = 1;
    unsigned long long oldFirst;
    unsigned long long oldSecond;
    // Index of fibonacci number, we start from 1, 1...
    int index = 2;
    // Number of digits, every timewe go over 18 digits,
    // divide the number by 10 and add 1 to counter
    int counter = 18;

    while (counter != 1000)
    {
        oldFirst = first;
        oldSecond = second;

        second = oldFirst + oldSecond;
        first = oldSecond;

        if (second > 999999999999999999)
        {
            first /= 10;
            second /= 10;
            counter++;
        }

        index++;
    }

    cout << index << endl;

    return 0;
}
