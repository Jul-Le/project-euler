#include <iostream>

using namespace std;

int main()
{

    unsigned long long grid[21][21];
    // Initialize array to 1
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            grid[i][j] = 1;
        }
    }


    for (int x = 1; x < 21; x++)
    {
        for (int y = 1; y < 21; y++)
        {
            grid[x][y] = grid[x][y - 1] + grid[x - 1][y];
        }
    }

    cout << grid[20][20] << endl;

    return 0;
}
