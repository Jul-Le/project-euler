#include <iostream>
#include <string>
#include "progressbar.h"

#define SIZE 80

struct cell
{
    int up;
    int left;
    int down;
};

cell matrix[SIZE][SIZE]{ 0 };

const int originalMatrix[SIZE][SIZE]
{
    #include "matrix.txt"
};

cell path[SIZE][SIZE]{ 0 };

//int total = matrix[0][0].up;
int x = 0;
int y = 0;

char pathDrawingThingy[SIZE][SIZE]{ ' ' };

bool pathNotFound()
{
    // ---- If rightmost column not reached ---- //
    for (int i = 0; i < SIZE; i++)
    {
        if (!(matrix[SIZE - 1][i].left))
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

    ProgressBar *bar = new ProgressBar;

    while (pathNotFound())
    {
        for (x = 0; x < SIZE; x++)
        {
            for (y = 0; y < SIZE; y++)
            {
                if (!x && matrix[x][y].left)
                {
                    if (!(--matrix[x][y].left))
                        path[x][y].left = 1;
                }

                // ---- If cell has been reached ---- //
                if (!matrix[x][y].up || !matrix[x][y].left || !matrix[x][y].down)
                {

                    // ---- If cell to the right has not been reached ---- //

                    if (x + 1 < SIZE && matrix[x + 1][y].left
                                     && matrix[x + 1][y].up
                                     && matrix[x + 1][y].down)
                    {
                        // ---- Decrement it, if it reaches ---- //
                        // ------- zero, mark it as path ------- //
                        if (!(--matrix[x + 1][y].left))
                        {
                            path[x + 1][y].left = 1;
                            bar->update(x+1, SIZE);
                            //std::cout << "(" << x + 1 << ", " << y << ")" << std::endl;
                        }
                    }

                    // ---- If cell below not reached ---- //

                    if (y + 1 < SIZE && matrix[x][y + 1].left
                                     && matrix[x][y + 1].up
                                     && matrix[x][y + 1].down)
                    {
                        // ---- Decrement it, if it reaches ---- //
                        // ------- zero, mark it as path ------- //
                        if (!(--matrix[x][y + 1].up))
                        {
                            path[x][y + 1].up = 1;
                            //std::cout << "(" << x << ", " << y + 1 << ")" << std::endl;
                        }
                    }

                    // ---- If cell above not reached ---- //

                    if (y - 1 >= 0 && matrix[x][y - 1].left
                                   && matrix[x][y - 1].up
                                   && matrix[x][y - 1].down)
                    {
                        // ---- Decrement it, if it reaches ---- //
                        // ------- zero, mark it as path ------- //
                        if (!(--matrix[x][y - 1].down))
                        {
                            path[x][y - 1].down = 1;
                            //std::cout << "(" << x << ", " << y - 1 << ")" << std::endl;
                        }
                    }
                } // endif reached
            } // end for y
        } // end for x
    } // end while
    delete bar;
}

void printPathTotal()
{
    for (int a=0; a<SIZE; a++)
    {
        for (int b=0; b<SIZE; b++)
        {
            pathDrawingThingy[a][b] = ' ';
        }
    }
    // ---- Reverse direction ---- //
    x = SIZE - 1;
    for (int i = 0; i < SIZE; i++)
    {
        if (!matrix[x][i].left)
        {
            y = i;
            break;
        }
    }

    int total = originalMatrix[y][x]; // xy swap
    pathDrawingThingy[x][y] = '*';

    while (x)
    {
        if (path[x][y].left)
            x--;
        else if (path[x][y].up)
            y--;
        else if (path[x][y].down)
            y++;

        total += originalMatrix[y][x]; // xy swap
        pathDrawingThingy[x][y] = '*';
    }

    std::cout << "Total sum: " << total << std::endl;

    for (int i = 0; i < 2 * SIZE; i++)
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
            // ---- Got dimensions wrong, swap xy ---- //
            matrix[x][y].left = originalMatrix[y][x];
            matrix[x][y].up = originalMatrix[y][x];
            matrix[x][y].down = originalMatrix[y][x];
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
