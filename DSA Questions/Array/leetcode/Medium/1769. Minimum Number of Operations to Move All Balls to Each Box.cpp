#include <cmath>
#include <iostream>
using namespace std;
#include <vector>
// here brute force is very easy to traverse for each ith box and check all jth box which have 1 in it and add abs(i-j);
// for optimiseing we use two extra space vectors
// we collect all balls from left side then right side and add it its our solution
vector<int> minOperations(string boxes)
{
    int n = boxes.size();
    vector<int> ans(n, 0);
    vector<int> l(n, 0);
    vector<int> r(n, 0);
    //         brute force
    // for(int i=0;i<boxes.size();i++)
    // {
    //     int c=0;
    //     for(int j=0;j<boxes.size();j++)
    //     {
    //         if(boxes[j]=='1')
    //         {
    //             c+=abs(i-j);
    //         }
    //     }
    //     ans.push_back(c);
    // }
    // return ans;

    int c = boxes[0] - '0';
    for (int i = 1; i < n; i++)
    {
        l[i] = l[i - 1] + c;
        c += boxes[i] - '0';
    }

    c = boxes[n - 1] - '0';
    for (int i = n - 2; i >= 0; i--)
    {
        r[i] = r[i + 1] + c;
        c += boxes[i] - '0';
    }

    for (int i = 0; i < n; i++)
    {
        ans[i] = l[i] + r[i];
    }
    return ans;
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
    vector<int> ans = minOperations("110");
    printVector(ans);
}