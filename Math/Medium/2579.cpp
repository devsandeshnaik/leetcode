#include <iostream>

using namespace std;
/*
There exists an infinitely large two-dimensional grid of uncolored unit cells.
You are given a positive integer n, indicating that you must do the following routine
for n minutes:

At the first minute, color any arbitrary unit cell blue.
Every minute thereafter, color blue every uncolored cell that touches a blue cell.
*/

long long coloredCells(int n)
{
    if (n == 1)
    {
        return 1;
    }
    long long coloredBlocks = 1;
    for (int i = 2; i <= n; i++)
    {
        coloredBlocks += 4 * (i - 1);
    }
    return coloredBlocks;
}

int main()
{

    long long res = coloredCells(6);
    cout << res << endl;
    return 0;
}
