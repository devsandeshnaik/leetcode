#include <iostream>
#include <vector>
#include <unordered_map>

// Tuple with Same Product

using namespace std;

class Solution
{
public:
    int tupleSameProduct(vector<int> &nums)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                int product = nums.at(i) * nums.at(j);
                map[product] = map[product] + 1;
            }
        }

        int var = 0;
        for (auto it : map)
        {
            int num = it.second - 1;
            int count = ((num * (num + 1)) / 2);
            var += count * 8;
        }
        return var;
    }
};

int main()
{
    vector<int> vec1 = {1, 2, 3, 4, 6, 12};
    vector<int> vec2 = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192};
    Solution sol = Solution();
    cout << sol.tupleSameProduct(vec1) << endl;
    return 0;
}