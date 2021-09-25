/*
Given K sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.
Example 1:

Input:
K = 3
arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
Output: 1 2 3 4 5 6 7 8 9
Explanation:Above test case has 3 sorted
arrays of size 3, 3, 3
arr[][] = [[1, 2, 3],[4, 5, 6], 
[7, 8, 9]]
The merged list will be 
[1, 2, 3, 4, 5, 6, 7, 8, 9].
Example 2:

Input:
K = 4
arr[][]={{1,2,3,4}{2,2,3,4},
         {5,5,6,6},{7,8,9,9}}
Output:
1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9 
Explanation: Above test case has 4 sorted
arrays of size 4, 4, 4, 4
arr[][] = [[1, 2, 2, 2], [3, 3, 4, 4],
[5, 5, 6, 6]  [7, 8, 9, 9 ]]
The merged list will be 
[1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 
6, 6, 7, 8, 9, 9 ].
Your Task:
You do not need to read input or print anything. Your task is to complete mergeKArrays() function which takes 2 arguments, an arr[K][K] 2D Matrix containing K sorted arrays and an integer K denoting the number of sorted arrays, as input and returns the merged sorted array ( as a pointer to the merged sorted arrays in cpp, as an ArrayList in java, and list in python)

Expected Time Complexity: O(K2*Log(K))
Expected Auxiliary Space: O(K)

Constraints:
1 <= K <= 100


3
4
10 20 30 40
5
5 9 12 18 32
3
11 15 17
*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Solution
{
public:
    //Function to merge k sorted arrays.
    struct ListData
    {
        int index;
        int val;
        int list_num;
        ListData(int num, int i, int v)
        {
            index = i;
            val = v;
            list_num = num;
        }
    };

    class cmpListData
    {
    public:
        bool operator()(ListData &p1, ListData &p2)
        {
            return p1.val > p2.val;
        }
    };
    vector<int> mergeKArrays(vector<vector<int>> lists, int k)
    {
        //code here
        vector<int> mergedList;
        priority_queue<ListData, vector<ListData>, cmpListData> pq;
        for (int i = 0; i < k; i++)
        {
            ListData *lnew = new ListData(i, 0, lists[i][0]);
            pq.push(*lnew);
        }
        while (pq.size() > 0)
        {
            ListData l = pq.top();
            pq.pop();
            mergedList.push_back(l.val);
            l.index++;
            if (l.index < k)
            {
                l.val = lists[l.list_num][l.index];
                pq.push(l);
            }
        }

        return mergedList;
    }
};
void printVector(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "At Index " << i << " Vector have : " << vec[i] << endl;
    }
    cout << endl;
}
struct ListData
{
    int index;
    int val;
    int list_num;
    ListData(int num, int i, int v)
    {
        index = i;
        val = v;
        list_num = num;
    }
};

class cmpListData
{
public:
    bool operator()(ListData &p1, ListData &p2)
    {
        return p1.val > p2.val;
    }
};
vector<int> kSorted(vector<vector<int>> &lists)
{
    int k = lists.size();
    vector<int> mergedList;
    priority_queue<ListData, vector<ListData>, cmpListData> pq;
    for (int i = 0; i < lists.size(); i++)
    {
        ListData *lnew = new ListData(i, 0, lists[i][0]);
        pq.push(*lnew);
    }
    while (pq.size() > 0)
    {
        ListData l = pq.top();
        pq.pop();
        // cout << l->val << " ";
        mergedList.push_back(l.val);
        l.index++;
        if (l.index < lists[l.list_num].size())
        {
            l.val = lists[l.list_num][l.index];
            pq.push(l);
        }
    }
    return mergedList;
}
int main()
{
    FAST;
    int n;
    cin >> n;
    vector<vector<int>> lists;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        vector<int> list(m);
        for (int j = 0; j < m; j++)
        {
            cin >> list[j];
        }
        lists.push_back(list);
    }
    vector<int> sorted = kSorted(lists);
    printVector(sorted);
    return 0;
}