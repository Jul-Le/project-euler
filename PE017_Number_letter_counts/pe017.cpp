#include <iostream>

using namespace std;

const int _1 = 3;
const int _2 = 3;
const int _3 = 5;
const int _4 = 4;
const int _5 = 4;
const int _6 = 3;
const int _7 = 5;
const int _8 = 5;
const int _9 = 4;
const int _10 = 3;
const int _11 = 6;
const int _12 = 6;
const int _13 = 8;
const int _20 = 6;
const int _30 = 6;
const int _40 = 5;
const int _50 = 5;
const int _60 = 5;
const int _70 = 7;
const int _80 = 6;
const int _90 = 6;
const int HUNDRED = 7;
const int AND = 3;

int oneToThirteen(int num);
int fourteenToNineteen(int num);
int twentyToNinety(int num);
int threeDigitNumber(int num);

int main()
{
    int letters = 0;

    for (int i = 1; i <= 1000; i++)
    {
        // 1-13
        if (i <= 13)
        {
            letters += oneToThirteen(i);
        }
        // 14-19
        else if (i < 20)
        {
            letters += fourteenToNineteen(i);
        }
        // 20, 30, 40, 50, 60, 70, 80, 90
        else if (i % 10 == 0 && i < 100)
        {
            letters += twentyToNinety(i);
        }
        // 100, 200, 300...900
        else if (i % 100 == 0 && i < 1000)
        {
            letters += oneToThirteen(i / 100) + HUNDRED;
        }
        // 21, 22, 23...98, 99
        else if (i < 100)
        {
            letters += twentyToNinety(i / 10 * 10) + oneToThirteen(i % 10);
        }
        // 1000
        else if (i == 1000)
        {
            letters += 11;
        }
        // 101, 102, 103...998, 999
        else
        {
            letters += threeDigitNumber(i) + AND + HUNDRED;
        }
    }

    cout << letters << endl;

    return 0;
}

int oneToThirteen(int num)
{
    switch (num)
    {
    case 1:
        return _1;
    case 2:
        return _2;
    case 3:
        return _3;
    case 4:
        return _4;
    case 5:
        return _5;
    case 6:
        return _6;
    case 7:
        return _7;
    case 8:
        return _8;
    case 9:
        return _9;
    case 10:
        return _10;
    case 11:
        return _11;
    case 12:
        return _12;
    case 13:
        return _13;
    default:
        return 0;
    }
}

int fourteenToNineteen(int num)
{
    switch (num)
    {
    case 14:
        return _4 + 4;
    case 15:
        return _5 + 3;
    case 16:
        return _6 + 4;
    case 17:
        return _7 + 4;
    case 18:
        return _8 + 3;
    case 19:
        return _9 + 4;
    default:
        return 0;
    }
}

int twentyToNinety(int num)
{
    switch (num)
    {
    case 20:
        return _20;
    case 30:
        return _30;
    case 40:
        return _40;
    case 50:
        return _50;
    case 60:
        return _60;
    case 70:
        return _70;
    case 80:
        return _80;
    case 90:
        return _90;
    default:
        return 0;
    }
}

int threeDigitNumber(int num)
{
    int value = 0;

    // #01 - #13
    if (num % 100 < 14)
    {
        value += oneToThirteen(num / 100) + oneToThirteen(num % 100);
    }
    // #14 - #19
    else if (num % 100 < 20)
    {
        value += oneToThirteen(num / 100) + fourteenToNineteen(num % 100);
    }
    // #20 - #90
    else if (num % 10 == 0)
    {
        value += oneToThirteen(num / 100) + twentyToNinety(num % 100);
    }
    // #21 - #99
    else
    {
        value += oneToThirteen(num / 100) + twentyToNinety(num / 10 % 10 * 10) + oneToThirteen(num % 10);
    }

    return value;
}
