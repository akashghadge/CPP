/*
A flock of chickens are running east along a straight, narrow road. Each one is running with its own constant speed. Whenever a chick catches up to the one in front of it, it has to slow down and follow at the speed of the other chick. You are in a mobile crane behind the flock, chasing the chicks towards the barn at the end of the road. The arm of the crane allows you to pick up any chick momentarily, let the chick behind it pass underneath and place the picked up chick back down. This operation takes no time and can only be performed on a pair of chicks that are immediately next to each other, even if 3 or more chicks are in a row, one after the other.

Given the initial locations (Xi) at time 0 and natural speeds (Vi) of the chicks, as well as the location of the barn (B), what is the minimum number of swaps you need to perform with your crane in order to have at least K of the N chicks arrive at the barn no later than time T?

You may think of the chicks as points moving along a line. Even if 3 or more chicks are at the same location, next to each other, picking up one of them will only let one of the other two pass through. Any swap is instantaneous, which means that you may perform multiple swaps at the same time, but each one will count as a separate swap.

Input
The first line of the input gives the number of test cases, C. C test cases follow. Each test case starts with 4 integers on a line -- N, K, B and T. The next line contains the Ndifferent integers Xi, in increasing order. The line after that contains the N integers Vi. All distances are in meters; all speeds are in meters per second; all times are in seconds.

Output
For each test case, output one line containing "Case #x: S", where x is the case number (starting from 1) and S is the smallest number of required swaps, or the word "IMPOSSIBLE".

Limits
1 ≤ C ≤ 100;
1 ≤ B ≤ 1,000,000,000;
1 ≤ T ≤ 1,000;
0 ≤ Xi < B;
1 ≤ Vi ≤ 100;
1 ≤ N ≤ 50;
0 ≤ K ≤ N;

All the Xi's will be distinct and in increasing order.

Example
Input:
3
5 3 10 5
0 2 5 6 7
1 1 1 1 4
5 3 10 5
0 2 3 5 7
2 1 1 1 4
5 3 10 5
0 2 3 4 7
2 1 1 1 4

Output:
Case #1: 0
Case #2: 2
Case #3: IMPOSSIBLE

*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
int sol(int pos[], int speed[], int n, int b, int t, int k, int i)
{
    long num = 0;
    long result = 0;
    long swap = 0;

    for (int j = n - 1; j >= 0; j--)
    {
        long long distanceCover = speed[j] * t;
        long long distanceToCover = b - pos[j];

        if (distanceToCover <= distanceCover)
        {
            num++;

            if (swap > 0)
            {
                result += swap;
            }
        }
        else
        {
            swap++;
        }

        if (num == k)
            break;
    }

    if (num < k)
    {
        cout << "Case #" << i << ": IMPOSSIBLE\n";
    }
    else
    {
        cout << "Case #" << i << ": " << result << endl;
    }
}
int main()
{
    FAST;
    int T;
    cin >> T;
    int testCase = 1;
    while (T--)
    {
        int N, K, B, T;
        cin >> N >> K >> B >> T;
        int locations[N], speeds[N];
        for (int i = 0; i < N; i++)
            cin >> locations[i];
        for (int i = 0; i < N; i++)
            cin >> speeds[i];
        sol(locations, speeds, N, B, T, K, testCase);
        testCase++;
    }

    return 0;
}

/*
#if 1
#include <iostream>
#include <cstdio>
using namespace std;
#define LL unsigned long long 
const int SZ = 51;
LL startPT[SZ];
LL speed[SZ];
int main()
{
#ifdef _WIN32
	freopen("GCJ101BB.txt", "r", stdin);
#endif
	int T;
	cin >> T;
	int t = 1;
	while (T--)
	{
		int swap = 0;
		int N, K;
		LL B,T;
		cin >> N >> K >> B >> T;
		for (int i = 1; i <= N; i++)
		{
			cin >> startPT[i];
		}
		for (int i = 1; i <= N; i++)
		{
			cin >> speed[i];
		}
		int count = 0;
		int cantReach = 0;
		for (int i = N; i >= 1; i--)
		{
			LL distance = B - startPT[i];
			//LL time = distance / speed[i];   // this was a mistake time was gettig rounded off
			LL canCover = T*speed[i];
			if (distance <= canCover)
			{
				count++;
				if (cantReach > 0)
				{
					swap = swap + cantReach;
					//cantReach = 0; dont reset it swap has to be done for all
				}
			}
			else
			{
				cantReach++;
			}
			if (count == K)
				break;
		}
		if (count < K)
		{
			cout << "Case #" << t++ << ": " << "IMPOSSIBLE" << endl;
		}
		else
		{
			cout << "Case #" << t++ << ": " << swap << endl;
		}

	}
	return 0;
}
#endif

*/