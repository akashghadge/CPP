/*
Given N integers and K, find the minimum number of elements that should be removed, such that Amax-Amin<=K. After the removal of elements, Amax and Amin is considered among the remaining elements. 

Examples: 



Input : a[] = {1, 3, 4, 9, 10, 11, 12, 17, 20} 
          k = 4 
Output : 5 
Explanation: Remove 1, 3, 4 from beginning 
and 17, 20 from the end.

Input : a[] = {1, 5, 6, 2, 8}  K=2
Output : 3
Explanation: There are multiple ways to 
remove elements in this case.
One among them is to remove 5, 6, 8.
The other is to remove 1, 2, 5

*/
































// CPP program to find minimum removals
// to make max-min <= K
#include <bits/stdc++.h>
using namespace std;

#define MAX 100
int dp[MAX][MAX];

// function to check all possible combinations
// of removal and return the minimum one
int countRemovals(int a[], int i, int j, int k)
{
	// base case when all elements are removed
	if (i >= j)
		return 0;

	// if condition is satisfied, no more
	// removals are required
	else if ((a[j] - a[i]) <= k)
		return 0;

	// if the state has already been visited
	else if (dp[i][j] != -1)
		return dp[i][j];

	// when Amax-Amin>d
	else if ((a[j] - a[i]) > k) {

		// minimum is taken of the removal
		// of minimum element or removal
		// of the maximum element
		dp[i][j] = 1 + min(countRemovals(a, i + 1, j, k),
						countRemovals(a, i, j - 1, k));
	}
	return dp[i][j];
}

// To sort the array and return the answer
int removals(int a[], int n, int k)
{
	// sort the array
	sort(a, a + n);

	// fill all stated with -1
	// when only one element
	memset(dp, -1, sizeof(dp));
	if (n == 1)
		return 0;
	else
		return countRemovals(a, 0, n - 1, k);
}

// Driver Code
int main()
{
	int a[] = { 1, 3, 4, 9, 10, 11, 12, 17, 20 };
	int n = sizeof(a) / sizeof(a[0]);
	int k = 4;
	cout << removals(a, n, k);
	return 0;
}
