/*
Bishu went to fight for Coding Club. There were N soldiers with various powers. There will be Q rounds to fight and in each round, Bishu's power will be varied. With power M, Bishu can kill all the soldiers whose power is less than or equal to M(<=M). After each round, All the soldiers who are dead in the previous round will reborn. Such that in each round there will be N soldiers to fight. As Bishu is weak in mathematics, help him to count the number of soldiers that he can kill in each round and the total sum of their powers.

INPUT:

The first line of the input contains N, the number of soldiers.

The second line contains an array of N numbers denoting the power of each soldier

This third line contains Q, which denotes the number of rounds.

Q lines follow, each line having one number denoting the power of Bishu.

OUTPUT:

For each round, the output should be an array of two numbers. The first number should be the number of soldiers that Bishu can beat, and the second number denotes the cumulative strength of all the soldiers that Bishu can beat.

CONSTRAINTS:

1<=N<=10000

1<=power of each soldier<=100

1<=Q<=10000

1<=power of bishu<=100

Sample Input
7
1 2 3 4 5 6 7
3
3
10
2
Sample Output
3 6
7 28
2 3
Time Limit: 1
Memory Limit: 256
Source Limit:
Explanation
There are 7 soldiers, each with the indicated power.

There are 3 rounds.

In the first round, Bishu's power is 3, which is greater than 3 soldiers, with the cumulative power of 6. Hence, the answer is 3 6

Similarly for the next round.


*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define ll long long
#define int long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

int solBrute(vector<ll> &arr, int bishu)
{
    int i = 0;
    for (i = 0; i < arr.size(); i++)
    {
        if (bishu < arr[i])
            break;
    }
    return i;
}
int sol(vector<ll> &arr, int bishu)
{
    int low = 0;
    int high = arr.size() - 1;
    int mid;
    int ans = -1;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (arr[mid] > bishu)
        {
            high = mid - 1;
        }
        else
        {
            ans = mid;
            low = mid + 1;
        }
    }
    return ans + 1;
}
int32_t main()
{
    FAST;
    int N;
    cin >> N;
    vector<ll> sold(N);
    vector<ll> cumlPow(N);
    int cumlSum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> sold[i];
        cumlSum += sold[i];
        cumlPow[i] = cumlSum;
    }
    sort(sold.begin(), sold.end());

    int Q, bishu;
    cin >> Q;
    while (Q--)
    {
        cin >> bishu;
        int pos = sol(sold, bishu);
        cout << pos << " " << cumlPow[pos - 1] << en;
    }

    return 0;
}

/*

#include <iostream>

#include <algorithm>

using namespace std;

typedef long long ll;

 

ll getScore(ll soldiers[],ll n,ll power){

    ll left=0;

    ll right=n-1;

    ll ans=-1;

    while(left<=right){

        ll mid=(right+left)/2;        

       if(soldiers[mid]>power){           

            right=mid-1;

        }

        else{

            ans=mid;

            left=mid+1;

        }

    }

    return ans+1;

};


 

int main() {

    ll num;

    cin >> num;

    ll soldiers[num];                               

    for(ll i=0;i<num;i++){

    cin>>soldiers[i];

    }

    sort(soldiers,soldiers+num);

    //prepocess the array to find cumulative power using prefix sum algorithm

    ll sum[num];

    sum[0]=soldiers[0];

    for(ll i=1;i<num;i++){

        sum[i]=sum[i-1]+soldiers[i];

    }

    ll Q;

    cin>>Q;

    for(ll i=0;i<Q;i++){

        ll q;

        cin>>q;

        ll res=getScore(soldiers,num,q);

        cout<<res<<" "<<sum[res-1]<<endl;

    }

}


*/