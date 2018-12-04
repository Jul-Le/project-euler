#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int number = 1;
    vector<int> digits;
    int counter = 0;
    while (counter < 1000000)
    {
        if (number < 10)
        {
            digits.push_back(number);
            ++counter;
        }

        else if (number < 100)
        {
            digits.push_back(number / 10);
            digits.push_back(number % 10);
            counter += 2;
        }

        else if (number < 1000)
        {
            digits.push_back(number / 100);
            digits.push_back((number / 10) % 10);
            digits.push_back(number % 10);
            counter += 3;
        }

        else if (number < 10000)
        {
            digits.push_back(number / 1000);
            digits.push_back((number / 100) % 10);
            digits.push_back((number / 10) % 10);
            digits.push_back(number % 10);
            counter += 4;
        }

        else if (number < 100000)
        {
            digits.push_back(number / 10000);
            digits.push_back((number / 1000) % 10);
            digits.push_back((number / 100) % 10);
            digits.push_back((number / 10) % 10);
            digits.push_back(number % 10);
            counter += 5;
        }

        else if (number < 1000000)
        {
            digits.push_back(number / 100000);
            digits.push_back((number / 10000) % 10);
            digits.push_back((number / 1000) % 10);
            digits.push_back((number / 100) % 10);
            digits.push_back((number / 10) % 10);
            digits.push_back(number % 10);
            counter += 6;
        }

        ++number;
    }

    int num = 9;
    bool firstLoop = true;
    int answer = 1;

    for (vector<int>::iterator it = digits.begin(); it < digits.end(); it += num)
    {
        answer *= *it;

        if (!firstLoop)
        {
            num *= 10;
        }

        firstLoop = false;

        if (num > 1000000)
        {
            break;
        }
    }

    cout << answer << endl;

    return 0;
}
