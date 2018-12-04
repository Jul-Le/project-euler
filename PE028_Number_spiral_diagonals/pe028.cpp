#include <iostream>

enum DIRECTION
{
    RIGHT,
    DOWN,
    LEFT,
    UP
};

int spiral[1001][1001]{ 0 };

void move(int direction, int &x, int &y)
{
    switch (direction)
    {
        case RIGHT: x++; break;
        case DOWN:  y++; break;
        case LEFT:  x--; break;
        case UP:    y--; break;
    }
}

void fillSpiral()
{
    int x = 500;
    int y = 500;
    int i = 1;
    int direction = RIGHT;
    int lastMove = RIGHT;

    // Fill middle with 1
    spiral[x][y] = i++;

    // Move cursor to the right
    move(direction, x, y);

    lastMove = direction;

    // Fill with 2
    spiral[x][y] = i++;

    // Loop until full
    while (i <= 1001 * 1001)
    {
        switch (lastMove)
        {
            case RIGHT:
                if (spiral[x][y + 1] == 0)
                    direction = DOWN;
                break;
            case DOWN:
                if (spiral[x - 1][y] == 0)
                    direction = LEFT;
                break;
            case LEFT:
                if (spiral[x][y - 1] == 0)
                    direction = UP;
                break;
            case UP:
                if (spiral[x + 1][y] == 0)
                    direction = RIGHT;
                break;
        }

        move(direction, x, y);

        lastMove = direction;

        spiral[x][y] = i++;
    }
}

int getDiagonalSum()
{
    int sum = 0;

    for (int i = 0; i < 1001; i++)
    {
        sum += spiral[i][i];
    }

    for (int x = 1000; x >= 0; x--)
    {
        sum += spiral[x][1000 - x];
    }

    return --sum;
}



int main()
{
    int sum;

    fillSpiral();

    sum = getDiagonalSum();

    std::cout << sum << std::endl;

    return 0;
}
