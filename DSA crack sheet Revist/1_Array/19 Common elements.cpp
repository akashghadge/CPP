/*

*/
#include <bits/stdc++.h>
using namespace std;
vector<int> commonElements(int A[], int B[], int C[], int a, int b, int c)
{
    // code here.
    vector<int> ans;
    int i = 0, j = 0, k = 0;
    while (i < a and j < b and k < c)
    {
        if (A[i] == B[j] and B[j] == C[k])
        {
            if (!(ans.size() and ans.back() == A[i]))
                ans.push_back(A[i]);
            i++;
        }
        else
        {
            if (A[i] <= B[j] and A[i] <= C[k])
            {
                i++;
            }
            else if (B[j] <= A[i] and B[j] <= C[k])
            {
                j++;
            }
            else
            {
                k++;
            }
        }
    }
    return ans;
}
int main()
{
}