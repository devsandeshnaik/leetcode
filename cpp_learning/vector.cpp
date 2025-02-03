#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
    // creating vector
    vector<int> vec = {1, 2, 3, 4, 5};
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }

    vector<int> v1;
    // creates vector of size 5 with default value 9 at all indexes
    vector<int> v2(5, 9);

    // accessing elements in vector
    cout << vec[3] << endl;
    cout << vec.at(3) << endl;

    // modifying
    vec[3] = 5;
    vec.at(2) = 67;

    // Inserting new ele in vector
    vec.push_back(31);
    vec.insert(vec.begin() + 4, 12);

    // Deleting ele
    vec.pop_back();
    vec.erase(vec.begin() + 2);

    // Other operations
    vec.empty();                               // whether vector is empty
    vec.size();                                // size of vector
    vec.resize(57);                            // resizes the vector to make it of size 57
    reverse(vec.begin(), vec.end());           // reverses vector
    sort(vec.begin(), vec.end());              // ascending order
    sort(vec.begin(), vec.end(), greater<>()); // descending order
    v1.swap(v2);                               // swap two vectors

    // remove duplicate from vectors
    // auto: automatically detectes the data type and assign it to the variable
    // unique: moved the duplicate values to the end of vector and returns forward iterator
    // pointing at begining of duplicate values
    auto it = unique(vec.begin(), vec.end());
    vec.erase(it, vec.end());

    // removing duplicates with unordered sets
    unordered_set<int> us;
    // create iterator pointing at begining of vector
    auto iterator = vec.begin();

    while (iterator != vec.end())
    {
        if (us.find(*it) != us.end())
        {
            it = vec.erase(it);
        }
        else
        {
            us.insert(*it);
            it++;
        }
    }
    return 0;
}