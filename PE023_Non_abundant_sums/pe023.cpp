#include <iostream>

using namespace std;

int isSumOfAbundantNumbers(int num)
{
    for (int j = 1; j < 6965; j++)
    {
        for (int k = 1; k < 6965; k++)
        {
            if (j + k == num)
            {
                return 0;
            }
        }
    }
    return num;
}

int main()
{
    int abundantNumbers[10000]{};
    int sum = 0;
    int j;
    int index = 0;
    int answer = 0;
    bool flag;

    for (int i = 0; i < 10000; i++)
    {
        abundantNumbers[i] = 0;
    }

    for (int i = 1; i < 28123; i++)
    {
        for (j = 1; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                sum += j;
            }
        }

        if (sum > i)
        {
            abundantNumbers[index] = i;
            index++;
        }
        sum = 0;
    }

    for (int i = 1; i < 28123; i++)
    {
        flag = true;
        for (int j = 0; j < 6965; j++)
        {
            if (abundantNumbers[j] > i)
            {
                break;
            }
                for (int k = 0; k < 6965; k++)
                {
                    if (abundantNumbers[j] + abundantNumbers[k] > i)
                    {
                        break;
                    }
                    if (abundantNumbers[j] + abundantNumbers[k] == i)
                    {
                        flag = false;
                        break;
                    }

                }

            if (!flag)
            {
                break;
            }
        }
        if (flag)
        {
            answer += i;
        }

        // Update progress bar
        if((i - 1) % (28123/80) == 0)
        {
            static int progress = 1;
            cout << "\r" << flush << "[";
            for (int z = 0; z < progress-1; z++)
            {
                cout << "=";
            }
            if (progress < 80)
            {
                cout << ">";
                for (int z = 0; z < 79-progress; z++)
                {
                    cout << " ";
                }
            }
            cout << "]";
            progress++;
        }
    }

    cout << endl << "Answer: " << answer << endl;

    return 0;
}
