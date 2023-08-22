/*

*/
#include <bits/stdc++.h>
using namespace std;
int findSum(int A[], int N)
{
    // code here.
    return *min_element(A, A + N) + *max_element(A, A + N);
}
pair<long long, long long> getMinMax(long long a[], int n)
{
    return {*min_element(a, a + n), *max_element(a, a + n)};
}
int main()
{
}