#include <stdio.h>
#include <stdint.h>

#define PRECISION 2000

short getCycleLength(uint8_t *decimals);

int main()
{
    int divide;
    int multiply;
    int subtract;
    int takeDown;

    short cycleLengths[1000] { 0 };
    uint8_t d[1000][PRECISION];
    int i, n;

    for (i = 2; i < 1000; i++)
    {
        divide = 1 / i;
        d[i][0] = (uint8_t)divide;
        multiply = i * divide;
        subtract = 1 - multiply;
        takeDown = subtract * 10;

        for (n = 1; n < PRECISION; n++)
        {
            divide = takeDown / i;
            d[i][n] = (uint8_t)divide;
            multiply = i * divide;
            subtract = takeDown - multiply;
            takeDown = subtract * 10;
        }
    }

    int denom = 0;
    int longest = 0;

    for (i = 2; i < 1000; i++)
    {
        cycleLengths[i] = getCycleLength(d[i]);
        if (cycleLengths[i] > longest)
        {
            longest = cycleLengths[i];
            denom = i;
        }
    }

    printf("1 / %d has a recurring cycle length of %d\n", denom, longest);

    return 0;

}

short getCycleLength(uint8_t *decimals)
{
    // Start from 50th digit, because first few
    // digits might not be part of the pattern
    int i = 50;
    bool found;

    // Try to find same digits with repeating intervals
    for (int n = 1; i+n < PRECISION; n++)
    {
        // If after certain interval we find a same digit
        if (decimals[i] == decimals[i+n])
        {
            found = true;
            // Try if same digits always repeat with same interval
            for (int k = 1; i+n+k < PRECISION; k++)
            {
                if (decimals[i+k] != decimals[i+n+k])
                {
                    found = false;
                    break;
                }
            }
            if (found) return n;
        }
    }
    // Irrational
    return -1;
}
