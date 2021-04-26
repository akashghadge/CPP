/*
Given two arrays of integers nums and index. Your task is to create target array under the following rules:

Initially target array is empty.
From left to right read nums[i] and index[i], insert at index index[i] the value nums[i] in target array.
Repeat the previous step until there are no elements to read in nums and index.
Return the target array.

It is guaranteed that the insertion operations will be valid.

 

Example 1:

Input: nums = [0,1,2,3,4], index = [0,1,2,2,1]
Output: [0,4,1,3,2]
Explanation:
nums       index     target
0            0        [0]
1            1        [0,1]
2            2        [0,1,2]
3            2        [0,1,3,2]
4            1        [0,4,1,3,2]
Example 2:

Input: nums = [1,2,3,4,0], index = [0,1,2,3,0]
Output: [0,1,2,3,4]
Explanation:
nums       index     target
1            0        [1]
2            1        [1,2]
3            2        [1,2,3]
4            3        [1,2,3,4]
0            0        [0,1,2,3,4]
Example 3:

Input: nums = [1], index = [0]
Output: [1]
 

Constraints:

1 <= nums.length, index.length <= 100
nums.length == index.length
0 <= nums[i] <= 100
0 <= index[i] <= i

*/

#include <iostream>
using namespace std;
#include <vector>
vector<int> createTargetArray(vector<int> &nums, vector<int> &index)
{
    // here vector manages all the stuff to adding the numbers
    vector<int> v;
    for (int i = 0; i < nums.size(); i++)
        v.insert(v.begin() + index.at(i), nums.at(i));
    return v;
}
void printVector(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "At Index " << i << " Vector have : " << vec[i] << endl;
    }
    cout << endl;
}
int main()
{
    // invector we must add first element at 0th place and agerer we can addd it any place
    // we must add lower number then only we add next one i.e for adding 5th number we must have 4 elements
    vector<int> vec;
    vec.insert(vec.begin(), 1);
    vec.insert(vec.begin() + 2, 3);
    vec.insert(vec.begin() + 1, 2);
    printVector(vec);
}