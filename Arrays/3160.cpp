#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>> &queries)
    {
        vector<int> balls(limit + 1, 0);
        unordered_set<int> currentColors = {};
        vector<int> distinct = {};
        for (int i = 0; i < queries.size(); i++)
        {
            cout << "Index " << i << endl;
            int ballIndex = queries.at(i).at(0);
            int ballColor = queries.at(i).at(1);

            if (distinct.size() == 0)
            {
                // first query
                balls.at(ballIndex) = ballColor;
                currentColors.insert(ballColor);
                distinct.push_back(1);
            }
            else if (currentColors.find(ballColor) == currentColors.end())
            {
                // color not applied to any ball
                int lastVal = distinct.at((distinct.size() - 1));
                distinct.push_back(lastVal + 1);

                // add color to currentColor
                currentColors.insert(ballColor);
                // color the ball
                balls.at(ballIndex) = ballColor;
            }
            else if (currentColors.find(ballColor) != currentColors.end() && balls.at(ballIndex) == 0)
            {
                // color is applied to ball at current query index
                int lastVal = distinct.at((distinct.size() - 1));
                distinct.push_back(lastVal + 1);
                balls.at(ballIndex) = ballColor;
            }
            else
            {
                int lastVal = distinct.at((distinct.size() - 1));
                distinct.push_back(lastVal);
                balls.at(ballIndex) = ballColor;
            }
        }
        return distinct;
    }
};

int main()
{
    //[0,1],[1,2],[2,2],[3,4],[4,5]
    Solution sol = Solution();
    vector<vector<int>> vec1 = {{1, 4}, {2, 5}, {1, 3}, {3, 4}};
    vector<vector<int>> vec2 = {{0, 1}, {1, 2}, {2, 2}, {3, 4}, {4, 5}};
    vector<int> res = sol.queryResults(4, vec2);
    for (int i = 0; i < res.size(); i++)
    {
        cout << "TTT" << res[i] << endl;
    }
    return 0;
}