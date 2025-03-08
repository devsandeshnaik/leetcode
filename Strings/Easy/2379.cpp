#include <iostream>
#include <string>

using namespace std;
/*
You are given a 0-indexed string blocks of length n, where blocks[i] is either 'W' or 'B', representing the color of the ith block. The characters 'W' and 'B' denote the colors white and black, respectively.

You are also given an integer k, which is the desired number of consecutive black blocks.

In one operation, you can recolor a white block such that it becomes a black block.

Return the minimum number of operations needed such that there is at least one occurrence of k consecutive black blocks.


*/
int minimumRecolors(string blocks, int k)
{
    int left = 0;
    int right = k;
    int minWhiteBlock = k;
    while (right <= blocks.size())
    {
        int wBChanges = 0;
        for (int i = left; i < right; i++)
        {
            cout << blocks[i] << endl;
            if (blocks[i] == 'W')
            {
                wBChanges++;
            }
        }
        if (wBChanges == 0)
        {
            return 0;
            break;
        }
        cout << "mWB: " << minWhiteBlock << "cWB: " << wBChanges << endl;
        minWhiteBlock = min(minWhiteBlock, wBChanges);
        left++;
        right++;

        cout << "=======" << endl;
    }
    return minWhiteBlock;
}

int main()
{
    // cout << "MIN: " << minimumRecolors("WBBWWBBWBW", 7) << endl;
    cout << "MIN: " << minimumRecolors("WBWBBBW", 2) << endl;
    return 0;
}