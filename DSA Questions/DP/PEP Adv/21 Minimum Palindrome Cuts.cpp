/*
Give minimum cuts to cut palindrome pieces
e.g
abccbc
a | bccb | a
*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vii vector<vector<int>>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

/*
here we are using gap strategy and the left right strategy
gap means 
we are using 2 matrix and
for every gap 0 means i==j
for every gap 1 means i+1==j+1
for every gap 2 means i+2==j+2
by doing this we can solve problem firstly
for single charecter a,b,c 
and then for gap 1 means we solving for 2 chars then 3 then 4 and so on ...

left right strategy 
we partitioning strings in left part and right
abccbc
a | bccbc and find answers
*/
int palindrome_cuts(string str)
{
    int n = str.size();
    vii palindroem_table(n, vi(n));
    /*
    here string is palindrome if ends are equal and middle is palindrome i.e table[i+1][j-1];
    */
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; j++, i++)
        {
            if (gap == 0)
                palindroem_table[i][j] = true;
            else if (gap == 1)
            {
                if (str[i] == str[j])
                    palindroem_table[i][j] = true;
            }
            else
            {
                if (str[i] == str[j] && palindroem_table[i + 1][j - 1])
                    palindroem_table[i][j] = true;
            }
        }
    }

    // here we fill the table with gap and left right have time complexity of O(n^3)
    vii cuts_req(n, vi(n));
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; j++, i++)
        {
            if (palindroem_table[i][j])
                cuts_req[i][j] = 0;
            else
            {
                int min_cuts = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    int left_req = cuts_req[i][k];
                    int right_req = cuts_req[k + 1][j];
                    min_cuts = min(min_cuts, left_req + right_req);
                }
                cuts_req[i][j] = min_cuts + 1;
            }
        }
    }
    return cuts_req[0][n - 1];
}

/*
here we are using gap strategy and the suffix part will be check if palindrome or not
gap means 
we are using 2 matrix and
for every gap 0 means i==j
for every gap 1 means i+1==j+1
for every gap 2 means i+2==j+2
by doing this we can solve problem firstly
for single charecter a,b,c 
and then for gap 1 means we solving for 2 chars then 3 then 4 and so on ...

here left right make each call
but using suffix strategy we only going to find answer if suffix is palindroem
*/
int palindrome_cuts_op(string str)
{
    int n = str.size();
    vii palindroem_table(n, vi(n));
    /*
    here string is palindrome if ends are equal and middle is palindrome i.e table[i+1][j-1];
    */
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; j++, i++)
        {
            if (gap == 0)
                palindroem_table[i][j] = true;
            else if (gap == 1)
            {
                if (str[i] == str[j])
                    palindroem_table[i][j] = true;
            }
            else
            {
                if (str[i] == str[j] && palindroem_table[i + 1][j - 1])
                    palindroem_table[i][j] = true;
            }
        }
    }

    // here we getting suffix and then we just check is it palindrome or not if suffix if palindrome then call
    vi cuts_req(n);
    str[0] = 0;
    for (int end = 1; end < n; end++)
    {
        if (palindroem_table[0][end])
            cuts_req[end] = 0;
        else
        {
            int min_cuts = INT_MAX;
            for (int start = end; start >= 1; start--)
            {
                if (palindroem_table[end][start])
                    min_cuts = min(cuts_req[start - 1], min_cuts);
            }
            cuts_req[end] = min_cuts + 1;
        }
    }
    return cuts_req[n - 1];
}

int main()
{
    FAST;
    string str;
    cin >> str;
    cout << palindrome_cuts(str) << en;
    cout << palindrome_cuts_op(str) << en;
    return 0;
}