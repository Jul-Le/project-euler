#include <iostream>
#include <string>
#include "progressbar.h"

#define SIZE 80

struct cell
{
    int up;
    int left;
};

cell matrix[SIZE][SIZE]{0};

const int originalMatrix[SIZE][SIZE]
{
    #include "matrix.txt"
};

cell path[SIZE][SIZE] { 0 };

//int total = matrix[0][0].up;
int x = 0;
int y = 0;

char pathDrawingThingy[SIZE][SIZE]{ ' ' };

bool pathNotFound()
{
    // ---- If last cell not reached ---- //
    return matrix[SIZE - 1][SIZE - 1].up && matrix[SIZE - 1][SIZE - 1].left;
}

void findPath()
{
    x = 0;
    y = 0;
    // ---- Clear first cell ---- //
    matrix[x][y].left = 0;
    matrix[x][y].up = 0;

    ProgressBar *bar = new ProgressBar;

    while (pathNotFound())
    {
        for (x = 0; x < SIZE; x++)
        {
            for (y = 0; y < SIZE; y++)
            {
                // ---- If cell has been reached ---- //
                if (!matrix[x][y].up || !matrix[x][y].left)
                {
                    // ---- If cell to the right has not been reached ---- //
                    if (x + 1 < SIZE && matrix[x + 1][y].left && matrix[x + 1][y].up)
                    {
                        // ---- Decrement it, if it reaches ---- //
                        // ------- zero, mark it as path ------- //
                        if (!(--matrix[x + 1][y].left))
                        {
                            path[x + 1][y].left = 1;
                            bar->update(x, SIZE);
                            //std::cout << "(" << x + 1 << ", " << y << ")" << std::endl;
                        }
                    }
                    // ---- If cell below not reached ---- //
                    if (y + 1 < SIZE && matrix[x][y + 1].left && matrix[x][y + 1].up)
                    {
                        // ---- Decrement it, if it reaches ---- //
                        // ------- zero, mark it as path ------- //
                        if (!(--matrix[x][y + 1].up))
                        {
                            path[x][y + 1].up = 1;
                            //std::cout << "(" << x << ", " << y + 1 << ")" << std::endl;
                        }
                    }
                } // endif reached
            } // end for y
        } // end for x
    } // end while
    std::cout << std::endl;
    delete bar;
}

void printPathTotal()
{
    for(int a=0; a<SIZE; a++)
    {
        for(int b=0; b<SIZE; b++)
        {
            pathDrawingThingy[a][b] = ' ';
        }
    }
    // ---- Reverse direction ---- //
    x = SIZE - 1;
    y = SIZE - 1;

    int total = originalMatrix[x][y];
    pathDrawingThingy[x][y] = '*';

    while (x || y)
    {
        // ---- If final cell was reached from the left ---- //
        if (path[x][y].left)
            x--;
        else // reached from top
            y--;

        total += originalMatrix[x][y];
        pathDrawingThingy[x][y] = '*';
    }
    std::cout << "Total sum: " << total << std::endl;

    for (int i = 0; i < SIZE; i++)
    {
        std::cout << "_";
    }
    std::cout << std::endl;
}

void printPath()
{
    for (y = 0; y < SIZE; y++)
    {
        for (x = 0; x < SIZE; x++)
        {
            std::cout << pathDrawingThingy[x][y];
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
            matrix[x][y].left = originalMatrix[x][y];
            matrix[x][y].up = originalMatrix[x][y];
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
