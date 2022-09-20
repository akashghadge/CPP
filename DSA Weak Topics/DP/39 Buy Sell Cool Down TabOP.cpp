#include <bits/stdc++.h>

using namespace std;

int stockProfit(vector<int> &Arr)
{
    int n = Arr.size();
    vector<int> cur(2, 0);
    vector<int> front1(2, 0);
    vector<int> front2(2, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit;

            if (buy == 0)
            { // We can buy the stock
                profit = max(0 + front1[0], -Arr[ind] + front1[1]);
            }

            if (buy == 1)
            { // We can sell the stock
                profit = max(0 + front1[1], Arr[ind] + front2[0]);
            }

            cur[buy] = profit;
        }

        front2 = front1;
        front1 = cur;
    }

    return cur[0];
}

int main()
{

    vector<int> prices{4, 9, 0, 4, 10};

    cout << "The maximum profit that can be generated is " << stockProfit(prices);
}
