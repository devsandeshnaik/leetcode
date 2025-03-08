#include <iostream>
#include <vector>

using namespace std;

/*
Given two positive integers left and right, find the two integers num1 and num2 such that:

left <= num1 < num2 <= right .
Both num1 and num2 are prime numbers.
num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.
Return the positive integer array ans = [num1, num2]. If there are multiple pairs
satisfying these conditions, return the one with the smallest num1 value. If no such numbers exist,
return [-1, -1].
*/

bool isPrimeNumber(int num)
{
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
            break;
        }
    }
    return true;
}

vector<int> closestPrimes(int left, int right)
{
    vector<int> primes;

    for (int i = left; i <= right; i++)
    {
        if (isPrimeNumber(i))
        {
            primes.push_back(i);
        }
    }

    if (primes.size() <= 1)
    {
        return {-1, -1};
    }
    int minDistance = primes[1] - primes[0];
    vector<int> minPair = {primes[0], primes[1]};
    for (int i = 2; i < primes.size(); i++)
    {
        int tempMD = primes[i] - primes[i - 1];
        if (tempMD < minDistance)
        {
            minDistance = tempMD;
            minPair = {primes[i - 1], primes[i]};
        }
    }
    for (auto it : minPair)
    {
        cout << it << " : ";
    }
    return minPair;
}

int main()
{
    // cout << isPrimeNumber(1) << endl;
    primeNumbersSieve(10, 19);
    return 0;
}