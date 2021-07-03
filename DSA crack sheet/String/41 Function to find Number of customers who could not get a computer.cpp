/*
Write a function “runCustomerSimulation” that takes following two inputs
a) An integer ‘n’: total number of computers in a cafe and a string:
b) A sequence of uppercase letters ‘seq’: Letters in the sequence occur in pairs. The first occurrence indicates the arrival of a customer; the second indicates the departure of that same customer.

A customer will be serviced if there is an unoccupied computer. No letter will occur more than two times.
Customers who leave without using a computer always depart before customers who are currently using the computers. There are at most 20 computers per cafe.

For each set of input the function should output a number telling how many customers, if any walked away without using a computer. Return 0 if all the customers were able to use a computer.

runCustomerSimulation (2, “ABBAJJKZKZ”) should return 0

runCustomerSimulation (3, “GACCBDDBAGEE”) should return 1 as ‘D’ was not able to get any computer




runCustomerSimulation (3, “GACCBGDDBAEE”) should return 0

runCustomerSimulation (1, “ABCBCA”) should return 2 as ‘B’ and ‘C’ were not able to get any computer.

runCustomerSimulation(1, “ABCBCADEED”) should return 3 as ‘B’, ‘C’ and ‘E’ were not able to get any computer.

Source: Fiberlink (maas360) Interview

We strongly recommend to minimize your browser and try this yourself first.

Below are simple steps to find number of customers who could not get any computer.

1) Initialize result as 0.

2) Traverse the given sequence. While traversing, keep track of occupied computers (this can be done by keeping track of characters which have appeared only once and a computer was available when they appeared). At any point, if count of occupied computers is equal to ‘n’, and there is a new customer, increment result by 1.




The important thing is to keep track of existing customers in cafe in a way that can indicate whether the customer has got a computer or not. Note that in sequence “ABCBCADEED”, customer ‘B’ did not get a seat, but still in cafe as a new customer ‘C’ is next in sequence.

Below are implementations of above idea.


*/

#include <bits/stdc++.h>
#define en "\n"
#define ll long long
using namespace std;
int sol(string str, int n)
{
    int occp = 0;
    // 0 not come any time
    // 1 in cafe not have computer
    // 2 in cafe  have computer
    vector<int> seen(256, 0);
    int notGet = 0;
    for (int i = 0; i < str.size(); i++)
    {
        // user is new comer
        int ind = str[i];
        if (seen[ind] == 0)
        {
            // user come in cafe
            seen[ind] = 1;
            // check for available pc
            if (occp < n)
            {
                seen[ind] = 2;
                occp++;
            }
            else
            {
                notGet++;
            }
        }
        else
        {
            if (seen[ind] == 2)
            {
                occp--;
            }
            seen[ind] = 0;
        }
    }
    return notGet;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    string str;
    int n;
    while (T--)
    {
        cin >> str >> n;
        cout << sol(str, n) << en;
    }

    return 0;
}