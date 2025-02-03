#include <iostream>

using namespace std;

// Merge Strings Alternately

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string result = "";
        int i = 0;
        while (i < word1.length() || i < word2.length())
        {
            if (i < word1.length())
            {
                result += word1[i];
            }
            if (i < word2.length())
            {
                result += word2[i];
            }
            i++;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    cout << "abc & pqr : " << sol.mergeAlternately("abc", "pqr") << endl;
    cout << "ab & pqrs : " << sol.mergeAlternately("ab", "pqrs") << endl;
    cout << "abcd & pq : " << sol.mergeAlternately("abcd", "pq") << endl;
    return 0;
}
