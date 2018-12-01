#include <iostream>

using namespace std;

int howManyFirstSundays(int y, int first)
{
    if (y % 4 == 0)
    {
        // These results are calculated by hand
        switch (first)
        {
            case 1: return 2;
            case 2: return 1;
            case 3: return 2;
            case 4: return 2;
            case 5: return 1;
            case 6: return 1;
            case 7: return 3;
        }
    }
    else
    {
        switch (first)
        {
            case 1: return 2;
            case 2: return 2;
            case 3: return 1;
            case 4: return 3;
            case 5: return 1;
            case 6: return 1;
            case 7: return 2;
        }
    }
}

int main()
{
    int year = 1901;
    int firstDayOfTheYear = 2;
    int sundays = 0;

    while (year <= 2000)
    {
        sundays += howManyFirstSundays(year, firstDayOfTheYear);
        if (year % 4 == 0)
        {
            firstDayOfTheYear += 2;
        }
        else
        {
            firstDayOfTheYear++;
        }
        if (firstDayOfTheYear > 7)
        {
            firstDayOfTheYear -= 7;
        }

        year++;
    }

    cout << sundays << endl;

    return 0;
}
/*
Number of sundays in a year, if first day of January is:
Monday:     2
Tuesday:    2
Wednesday:  1
Thursday:   3
Friday:     1
Saturday:   1
Sunday:     2

Leap years:

Monday:     2
Tuesday:    1
Wednesday:  2
Thursday:   2
Friday:     1
Saturday:   1
Sunday:     3


01 02 03 04 05 06 07
08 09 10 11 12 13 14
15 16 17 18 19 20 21
22 23 24 25 26 27 28
29 30 31
         01 02 03 04
05 06 07 08 09 10 11 
12 13 14 15 16 17 18 
19 20 21 22 23 24 25 
26 27 28
         01 02 03 04
05 06 07 08 09 10 11 
12 13 14 15 16 17 18 
19 20 21 22 23 24 25 
26 27 28 29 30 31
                  01
02 03 04 05 06 07 08 
09 10 11 12 13 14 15 
16 17 18 19 20 21 22 
23 24 25 26 27 28 29 
30
   01 02 03 04 05 06
07 08 09 10 11 12 13 
14 15 16 17 18 19 20 
21 22 23 24 25 26 27 
28 29 30 31
            01 02 03
04 05 06 07 08 09 10 
11 12 13 14 15 16 17 
18 19 20 21 22 23 24 
25 26 27 28 29 30
                  01
02 03 04 05 06 07 08
09 10 11 12 13 14 15
16 17 18 19 20 21 22
23 24 25 26 27 28 29
30 31
      01 02 03 04 05
06 07 08 09 10 11 12 
13 14 15 16 17 18 19 
20 21 22 23 24 25 26 
27 28 29 30 31
               01 02
03 04 05 06 07 08 09 
10 11 12 13 14 15 16 
17 18 19 20 21 22 23 
24 25 26 27 28 29 30

01 02 03 04 05 06 07
08 09 10 11 12 13 14
15 16 17 18 19 20 21
22 23 24 25 26 27 28
29 30 31

         01 02 03 04
05 06 07 08 09 10 11
12 13 14 15 16 17 18
19 20 21 22 23 24 25
26 27 28 29 30
               01 02
03 04 05 06 07 08 09
10 11 12 13 14 15 16
17 18 19 20 21 22 23
24 25 26 27 28 29 30
31
*/
