#include <iostream>
#include <string>

using namespace std;

/*
For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t
(i.e., t is concatenated with itself one or more times).
Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.


Example 1:
Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""


Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of English uppercase letters.
*/

// SOLUTION:
/*
    We need to find gcd for both strings
    1. If: both strings are same then we can return string itself
    2. Else: Find gcd for first string and if t
*/
string gcdOfStrings(string str1, string str2)
{
    if (str1 + str2 != str2 + str1)
    {
        return "";
    }

    int len1 = str1.length();
    int len2 = str2.length();

    while (len2 > 0)
    {
        int tempt = len1 % len2;
        len1 = len2;
        len2 = tempt;
    }
    return str1.substr(0, len1);
}

int main()
{
    string str1 = "abcabcabc";
    string str2 = "abcabc";
    cout << gcdOfStrings(str1, str2) << endl;
    return 0;
}