/*

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

struct Item
{
    int value;
    int weight;
};
struct ItemRatio
{
    int value;
    int weight;
    float ratio;
    ItemRatio(int v, int w, float r)
    {
        value = v;
        weight = w;
        ratio = r;
    }
};
double fractionalKnapsack(int W, Item arr[], int n)
{
    // Your code here
    vector<ItemRatio> items;
    for (int i = 0; i < n; i++)
    {
        float ratio = arr[i].value / arr[i].weight;
        ItemRatio temp = ItemRatio(arr[i].value, arr[i].weight, ratio);
        items.push_back(temp);
    }
    sort(items.begin(), items.end(),
         [](ItemRatio i, ItemRatio j)
         { return i.ratio > j.ratio; });
    double curr_weight = 0;
    double cost = 0;
    for (int i = 0; i < n; i++)
    {
        if (curr_weight + items[i].weight <= W)
        {
            cost += (items[i].weight * items[i].value);
            curr_weight += items[i].weight;
        }
        else
        {
            cost += (double(W - curr_weight) * items[i].value);
            break;
        }
    }
    return cost;
}
int main()
{
    FAST;

    return 0;
}