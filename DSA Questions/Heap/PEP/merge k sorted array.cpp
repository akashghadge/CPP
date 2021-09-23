/*
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
void printVector(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "At Index " << i << " Vector have : " << vec[i] << endl;
    }
    cout << endl;
}
class ListData
{
public:
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
bool operator<(ListData &p1, ListData &p2)
{
    return p1.val < p2.val;
}
vector<int> kSorted(vector<vector<int>> &lists)
{
    int k = lists.size();
    vector<int> mergedList;
    priority_queue<ListData *> pq;
    for (int i = 0; i < lists.size(); i++)
    {
        ListData *lnew = new ListData(i, 0, lists[i][0]);
        pq.push(lnew);
    }
    while (!pq.empty())
    {
        cout << pq.top()->val << " ";
        pq.pop();
    }

    while (pq.size() > 0)
    {
        ListData *l = pq.top();
        pq.pop();
        // cout << l->val << " ";
        mergedList.push_back(l->val);
        l->index++;
        if (l->index < lists[l->list_num].size())
        {
            l->val = lists[l->list_num][l->index];
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
    // printVector(sorted);
    return 0;
}