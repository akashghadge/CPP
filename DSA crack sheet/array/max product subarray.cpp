#include <bits/stdc++.h>
using namespace std;
// editorial solution :)
class Solution
{
public:
    long long maxProduct(int *arr, int n)
    {
        // Variables to store maximum and minimum
        // product till ith index.
        long long minVal = arr[0];
        long long maxVal = arr[0];

        long long maxProduct = arr[0];

        for (int i = 1; i < n; i++)
        {

            // When multiplied by -ve number,
            // maxVal becomes minVal
            // and minVal becomes maxVal.
            if (arr[i] < 0)
                swap(maxVal, minVal);

            // maxVal and minVal stores the
            // product of subarray ending at arr[i].
            maxVal = max(1LL * arr[i], 1LL * maxVal * arr[i]);
            minVal = min(1LL * arr[i], 1LL * minVal * arr[i]);

            // Max Product of array.
            maxProduct = max(maxProduct, maxVal);
        }

        // Return maximum product found in array.
        return maxProduct;
    }
};
// C++ program to find Maximum Product Subarray
/* Returns the product
of max product subarray.
Assumes that the given
array always has a subarray
with product more than 1 */
int maxSubarrayProduct(int arr[], int n)
{
	// max positive product
	// ending at the current position
	int max_ending_here = 1;

	// min negative product ending
	// at the current position
	int min_ending_here = 1;

	// Initialize overall max product
	int max_so_far = 0;
	int flag = 0;
	/* Traverse through the array.
	Following values are
	maintained after the i'th iteration:
	max_ending_here is always 1 or
	some positive product ending with arr[i]
	min_ending_here is always 1 or
	some negative product ending with arr[i] */
	for (int i = 0; i < n; i++)
	{
		/* If this element is positive, update
		max_ending_here. Update min_ending_here only if
		min_ending_here is negative */
		if (arr[i] > 0)
		{
			max_ending_here = max_ending_here * arr[i];
			min_ending_here
				= min(min_ending_here * arr[i], 1);
			flag = 1;
		}

		/* If this element is 0, then the maximum product
		cannot end here, make both max_ending_here and
		min_ending_here 0
		Assumption: Output is alway greater than or equal
					to 1. */
		else if (arr[i] == 0) {
			max_ending_here = 1;
			min_ending_here = 1;
		}

		/* If element is negative. This is tricky
		max_ending_here can either be 1 or positive.
		min_ending_here can either be 1 or negative.
		next max_ending_here will always be prev.
		min_ending_here * arr[i] ,next min_ending_here
		will be 1 if prev max_ending_here is 1, otherwise
		next min_ending_here will be prev max_ending_here *
		arr[i] */

		else {
			int temp = max_ending_here;
			max_ending_here
				= max(min_ending_here * arr[i], 1);
			min_ending_here = temp * arr[i];
		}

		// update max_so_far, if needed
		if (max_so_far < max_ending_here)
			max_so_far = max_ending_here;
	}
	if (flag == 0 && max_so_far == 0)
		return 0;
	return max_so_far;
}

// my approch
int maxProduct(int *arr, int size)
{
    int m = 1;
    int curr = 1;
    int neg = 1;
    bool flag = true;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            curr = 1;
            neg = 1;
            flag = 1;
        }
        else if (arr[i] > 0)
        {
            curr *= arr[i];
            neg *= arr[i];
        }
        else if (arr[i] < 0)
        {
            if (flag)
            {
                flag = false;
                neg *= arr[i];
                curr = 1;
            }
            else
            {
                curr = neg * arr[i];
                neg = curr;
                flag = true;
            }
        }
        // cout << curr << " " << neg << endl;
        m = max(m, curr);
    }
    return m;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << maxProduct(arr, n) << "\n";
    return 0;
}