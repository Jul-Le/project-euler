#include <iostream>

using namespace std;

int abs(int);

int main()
{
    int sumOfTheSquares = 0;
    int squareOfTheSum = 0;

    for (int i = 1; i <= 100; i++)
    {
        sumOfTheSquares += i * i;
        squareOfTheSum += i;
    }

    squareOfTheSum = squareOfTheSum * squareOfTheSum;

    cout << abs(sumOfTheSquares - squareOfTheSum) << endl;

    return 0;
}

int abs(int n)
{
    if (n >= 0)
        return n;
    else
        return -n;
}
