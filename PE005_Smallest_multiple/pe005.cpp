#include <iostream>

bool isDivisable(int num);

using namespace std;

int main()
{
    for (int i = 2520;; i = (i + 20))
    {
        if (isDivisable(i))
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}



bool isDivisable(int num)
{
    for (int n = 2; n <= 20; n++)
    {
        if (num % n != 0)
        {
            return false;
        }
    }
    return true;
}
