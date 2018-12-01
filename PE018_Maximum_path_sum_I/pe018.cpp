#include <iostream>
#include <string>

#define SIZE 15

struct cell
{
    int up_left;
    int up_right;
};

cell triangle[SIZE][SIZE]{ 0 };

const int originalTriangle[SIZE][SIZE]
{
    75,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
    95,64,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
    17,47,82,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
    18,35,87,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
    20,4,82,47,65,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
    19,1,23,75,3,34,-1,-1,-1,-1,-1,-1,-1,-1,-1,
    88,2,77,73,7,63,67,-1,-1,-1,-1,-1,-1,-1,-1,
    99,65,4,28,6,16,70,92,-1,-1,-1,-1,-1,-1,-1,
    41,41,26,56,83,40,80,70,33,-1,-1,-1,-1,-1,-1,
    41,48,72,33,47,32,37,16,94,29,-1,-1,-1,-1,-1,
    53,71,44,65,25,43,91,52,97,51,14,-1,-1,-1,-1,
    70,11,33,28,77,73,17,78,39,68,17,57,-1,-1,-1,
    91,71,52,38,17,14,91,43,58,50,27,29,48,-1,-1,
    63,66,4,68,89,53,67,30,73,16,69,87,40,31,-1,
    4,62,98,27,23,9,70,98,73,93,38,53,60,4,23
};

int invertedTriangle[SIZE][SIZE]{ 0 };

cell path[SIZE][SIZE]{ 0 };

int x = 0;
int y = 0;

char pathDrawingThingy[SIZE][SIZE]{ ' ' };

bool pathNotFound()
{
    // ---- If bottom row not reached ---- //
    for (int i = 0; i < SIZE; i++)
    {
        if (!(triangle[i][SIZE - 1].up_left && triangle[i][SIZE - 1].up_right))
        {
            return false;
        }
    }
    return true;
}

void findPath()
{
    x = 0;
    y = 0;
    // ---- Clear first cell ---- //
    triangle[x][y].up_left = 0;
    triangle[x][y].up_right = 0;

    while (pathNotFound())
    {
        for (x = 0; x < SIZE; x++)
        {
            for (y = 0; y < SIZE; y++)
            {
                // ---- If cell has been reached ---- //
                if (!triangle[x][y].up_left || !triangle[x][y].up_right)
                {

                    // ---- If lower left cell has not been reached ---- //

                    if (triangle[x][y + 1].up_left
                        && triangle[x][y + 1].up_right)
                    {
                        // ---- Decrement it, if it reaches ---- //
                        // ------- zero, mark it as path ------- //
                        if (!(--triangle[x][y + 1].up_right))
                        {
                            path[x][y + 1].up_right = 1;
                            //std::cout << "(" << x << ", " << y + 1 << ")" << std::endl;
                        }
                    }

                    // ---- If lower right cell has not been reached ---- //

                    if (triangle[x + 1][y + 1].up_left
                        && triangle[x + 1][y + 1].up_right)
                    {
                        // ---- Decrement it, if it reaches ---- //
                        // ------- zero, mark it as path ------- //
                        if (!(--triangle[x + 1][y + 1].up_left))
                        {
                            path[x + 1][y + 1].up_left = 1;
                            //std::cout << "(" << x + 1 << ", " << y + 1 << ")" << std::endl;
                        }
                    }
                } // endif reached
            } // end for y
        } // end for x
    } // end while
}

void printPathTotal()
{
    // ---- Reverse direction ---- //
    for (int i = 0; i < SIZE; i++)
    {
        if (path[i][SIZE - 1].up_left || path[i][SIZE - 1].up_right)
        {
            x = i;
            break;
        }
    }
    y = SIZE - 1;

    int total = originalTriangle[y][x];
    pathDrawingThingy[x][y] = '*';

    while (y)
    {
        if (path[x][y].up_left)
        {
            x--;
            y--;
        }
        else if (path[x][y].up_right)
            y--;

        total += originalTriangle[y][x];
        pathDrawingThingy[x][y] = '*';
    }
    std::cout << "Total sum: " << total << std::endl;
}

void printPath()
{
    for (y = 0; y < SIZE; y++)
    {
        for (x = 0; x < SIZE; x++)
        {
            std::cout << pathDrawingThingy[x][y] << " ";
        }
        std::cout << std::endl;
    }
}

void init()
{
    for (x = 0; x < SIZE; x++)
    {
        for (y = 0; y < SIZE; y++)
        {
            if (originalTriangle[y][x] != -1)
            {
                invertedTriangle[x][y] = (originalTriangle[y][x] - 100) * (-1);
            }
            else
            {
                invertedTriangle[x][y] = -1;
            }
            triangle[x][y].up_left = invertedTriangle[x][y];
            triangle[x][y].up_right = invertedTriangle[x][y];
        }
    }
}

int main()
{
    // ------- Parse --------- //
    init();
    // ---- Do some magic ---- //
    findPath();
    // --- Calculate total --- //
    printPathTotal();
    // --- Draw fancy path --- //
    printPath();

    return 0;
}
