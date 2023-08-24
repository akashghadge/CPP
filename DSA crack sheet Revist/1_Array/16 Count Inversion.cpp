/*
Observation:

Let’s build the intuition for this approach using a modified version of the given question.

Assume two sorted arrays are given i.e. a1[] = {2, 3, 5, 6} and a2[] = {2, 2, 4, 4, 8}. Now, we have to count the pairs i.e. a1[i] and a2[j] such that a1[i] > a2[j].

In order to solve this, we will keep two pointers i and j, where i will point to the first index of a1[] and j will point to the first index of a2[]. Now in each iteration, we will do the following:

If a1[i] <= a2[j]: These two elements cannot be a pair and so we will move the pointer i to the next position. This case is illustrated below:

Why we moved the i pointer: We know, that the given arrays are sorted. So, all the elements after the pointer j, should be greater than a2[j]. Now, as a1[i] is smaller or equal to a2[j], it is obvious that a1[i] will be smaller or equal to all the elements after a2[j]. We need a bigger value of a1[i] to make a pair and so we move the i pointer to the next position i.e. next bigger value.
If a1[i] > a2[j]: These two elements can be a pair and so we will update the count of pairs. Now, here, we should observe that as a1[i] is greater than a2[j], all the elements after a1[i] will also be greater than a2[j] and so, those elements will also make pair with a2[j]. So, the number of pairs added will be n1-i (where n1 = size of a1[ ]). Now, we will move the j pointer to the next position. This case is also illustrated below:

The above process will continue until at least one of the pointers reaches the end.

Until now, we have figured out how to count the number of pairs in one go if two sorted arrays are given. But in our actual question, only a single unsorted array is given. So, how to break it into two sorted halves so that we can apply the above observation?


We can think of the merge sort algorithm that works in a similar way we want. In the merge sort algorithm, at every step, we divide the given array into two halves and then sort them, and while doing that we can actually count the number of pairs.


*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef long long ll;
    ll merge_sort(ll arr[], ll l, ll h)
    {
        ll cn = 0;
        if (l >= h)
        {
            return cn;
        }
        ll mid = l + (h - l) / 2;
        cn += merge_sort(arr, l, mid);
        cn += merge_sort(arr, mid + 1, h);
        cn += merge(arr, l, mid, h);
        return cn;
    }
    ll merge(ll arr[], ll l, ll mid, ll r)
    {
        vector<ll> temp(r - l + 1);
        int k = 0;
        int i = l;
        int j = mid + 1;
        ll inv = 0;
        while (i <= mid and j <= r)
        {
            if (arr[i] <= arr[j])
            {
                temp[k++] = arr[i++];
            }
            else
            {
                temp[k++] = arr[j++];
                inv += (mid - i + 1);
            }
        }
        while (i <= mid)
        {
            temp[k++] = arr[i++];
        }
        while (j <= r)
        {
            temp[k++] = arr[j++];
        }
        for (int id = l; id <= r; id++)
        {
            arr[id] = temp[id - l];
        }
        return inv;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        ll ans = merge_sort(arr, 0, N - 1);
        // for(int i=0;i<N;i++)
        //     cout<<arr[i]<<endl;
        return ans;
    }
};
int main()
{
}