#include <iostream>
#include <vector>
#include <math.h>
#include "progressbar.h"

using namespace std;

int fifthPower3digits(int num)
{
    int num1, num2, num3;
    num1 = num / 100;
    num2 = (num / 10) % 10;
    num3 = num % 10;

    return pow(num1, 5) + pow(num2, 5) + pow(num3, 5);
}
int fifthPower4digits(int num)
{
    int num1, num2, num3, num4;
    num1 = num / 1000;
    num2 = (num / 100) % 10;
    num3 = (num / 10) % 10;
    num4 = num % 10;

    return pow(num1, 5) + pow(num2, 5) + pow(num3, 5) + pow(num4, 5);
}
int fifthPower5digits(int num)
{
    int num1, num2, num3, num4, num5;
    num1 = num / 10000;
    num2 = (num / 1000) % 10;
    num3 = (num / 100) % 10;
    num4 = (num / 10) % 10;
    num5 = num % 10;

    return pow(num1, 5) + pow(num2, 5) + pow(num3, 5) + pow(num4, 5) + pow(num5, 5);
}
int fifthPower6digits(int num)
{
    int num1, num2, num3, num4, num5, num6;
    num1 = num / 100000;
    num2 = (num / 10000) % 10;
    num3 = (num / 1000) % 10;
    num4 = (num / 100) % 10;
    num5 = (num / 10) % 10;
    num6 = num % 10;

    return pow(num1, 5) + pow(num2, 5) + pow(num3, 5) + pow(num4, 5) + pow(num5, 5) + pow(num6, 5);
}
int fifthPower7digits(int num)
{
    int num1, num2, num3, num4, num5, num6, num7;
    num1 = num / 1000000;
    num2 = (num / 100000) % 10;
    num3 = (num / 10000) % 10;
    num4 = (num / 1000) % 10;
    num5 = (num / 100) % 10;
    num6 = (num / 10) % 10;
    num7 = num % 10;

    return pow(num1, 5) + pow(num2, 5) + pow(num3, 5) + pow(num4, 5) + pow(num5, 5) + pow(num6, 5) + pow(num7, 5);
}

int main()
{
    vector<int> numbers;

    ProgressBar *bar = new ProgressBar();
    int max = 9999999;

    for (int i = 100; i < 1000; i++)
    {
        if (fifthPower3digits(i) == i)
        {
            numbers.push_back(i);
        }
        bar->update(i, max);
    }

    for (int i = 1000; i < 10000; i++)
    {
        if (fifthPower4digits(i) == i)
        {
            numbers.push_back(i);
        }
        bar->update(i, max);
    }

    for (int i = 10000; i < 100000; i++)
    {
        if (fifthPower5digits(i) == i)
        {
            numbers.push_back(i);
        }
        bar->update(i, max);
    }

    for (int i = 100000; i < 1000000; i++)
    {
        if (fifthPower6digits(i) == i)
        {
            numbers.push_back(i);
        }
        bar->update(i, max);
    }

    for (int i = 1000000; i < 10000000; i++)
    {
        if (fifthPower7digits(i) == i)
        {
            numbers.push_back(i);
        }
        bar->update(i, max);
    }

    int answer = 0;
    for (int i : numbers)
    {
        answer += i;
    }

    cout << endl << answer << endl;

    delete bar;

    return 0;
}
