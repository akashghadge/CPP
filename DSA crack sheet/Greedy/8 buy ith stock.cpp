/*
In a stock market, there is a product with its infinite stocks. The stock prices are given for N days, where arr[i] denotes the price of the stock on the ith day. There is a rule that a customer can buy at most i stock on the ith day. If the customer has an amount of k amount of money initially, find out the maximum number of stocks a customer can buy. 

For example, for 3 days the price of a stock is given as 7, 10, 4. You can buy 1 stock worth 7 rs on day 1, 2 stocks worth 10 rs each on day 2 and 3 stock worth 4 rs each on day 3.

Attention reader! Don’t stop learning now. Get hold of all the important DSA concepts with the DSA Self Paced Course at a student-friendly price and become industry ready.  To complete your preparation from learning a language to DS Algo and many more,  please refer Complete Interview Preparation Course.

In case you wish to attend live classes with experts, please refer DSA Live Classes for Working Professionals and Competitive Programming Live for Students.

Examples: 



Input : price[] = { 10, 7, 19 }, 
              k = 45.
Output : 4
A customer purchases 1 stock on day 1, 
2 stocks on day 2 and 1 stock on day 3 for 
10, 7 * 2 = 14 and 19 respectively. Hence, 
total amount is 10 + 14 + 19 = 43 and number 
of stocks purchased is 4.

Input  : price[] = { 7, 10, 4 }, 
               k = 100.
Output : 6

*/

// C++ program to find maximum number of stocks that
// can be bought with given constraints.
#include <bits/stdc++.h>
using namespace std;

// Return the maximum stocks
int buyMaximumProducts(int n, int k, int price[])
{
    vector<pair<int, int>> ratios;
    for (int i = 0; i < n; i++)
    {
        ratios.push_back({price[i], i + 1});
    }
    sort(ratios.begin(), ratios.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += min(ratios[i].second, k / ratios[i].first);
        k -= ratios[i].first * min(ratios[i].second, k / ratios[i].first);
    }
    return ans;
}

// Driven Program
int main()
{
    int price[] = {10, 7, 19};
    int n = sizeof(price) / sizeof(price[0]);
    int k = 45;

    cout << buyMaximumProducts(n, k, price) << endl;

    return 0;
}
