#include <iostream>

int main()
{
    int product;
    int digits[6];
    int largestPalindrome = 0;

    for (int i = 100; i < 1000; i++)
    {
        for (int n = 100; n < 1000; n++)
        {
            product = i * n;

            if(product > 100000)
            {
                digits[0] = product / 100000;
                digits[1] = (product % 100000) / 10000;
                digits[2] = (product % 10000) / 1000;
                digits[3] = (product % 1000) / 100;
                digits[4] = (product % 100) / 10;
                digits[5] = (product % 10);

                if (digits[0] == digits[5] && digits[1] == digits[4] && digits[2] == digits[3])
                {
                    if (product > largestPalindrome)
                    {
                        largestPalindrome = product;
                    }
                }
            }
        }
    }
    std::cout << largestPalindrome << std::endl;

    return 0;
}
