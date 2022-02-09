/*
Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.

Note:
The initial and the target position co-ordinates of Knight have been given accoring to 1-base indexing.



Example 1:

Input:
N=6
knightPos[ ] = {4, 5}
targetPos[ ] = {1, 1}
Output:
3
Explanation:

Knight takes 3 step to reach from
(4, 5) to (1, 1):
(4, 5) -> (5, 3) -> (3, 2) -> (1, 1).




Your Task:
You don't need to read input or print anything. Your task is to complete the function minStepToReachTarget() which takes the inital position of Knight (KnightPos), the target position of Knight (TargetPos) and the size of the chess board (N) as an input parameters and returns the minimum number of steps required by the knight to reach from its current position to the given target position.



Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(N2).



Constraints:
1 <= N <= 1000
1 <= Knight_pos(X, Y), Targer_pos(X, Y) <= N


*/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int> &k, vector<int> &Tar, int N)
    {
        queue<pair<int, int>> q;
        int dir[8][2] = {{-2, -1}, {2, 1}, {-1, -2}, {1, 2}, {2, -1}, {-2, 1}, {-1, 2}, {1, -2}};
        vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false));
        q.push({k[0], k[1]});
        // visited[k[0]][k[1]]=true;
        int count = 0;

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int curi = q.front().first;
                int curj = q.front().second;
                q.pop();
                visited[curi][curj] = true;

                if (curi == Tar[0] && curj == Tar[1])
                    return count;

                for (int k = 0; k < 8; k++)
                {
                    int dx = dir[k][0];
                    int dy = dir[k][1];

                    int nbri = curi + dx;
                    int nbrj = curj + dy;

                    if (nbri <= 0 || nbri > N || nbrj <= 0 || nbrj > N || visited[nbri][nbrj])
                    {
                        continue;
                    }
                    q.push({nbri, nbrj});
                    visited[nbri][nbrj] = true;
                }
            }
            count++;
        }
        return count;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        vector<int> KnightPos(2);
        vector<int> TargetPos(2);
        int N;
        cin >> N;
        cin >> KnightPos[0] >> KnightPos[1];
        cin >> TargetPos[0] >> TargetPos[1];
        Solution obj;
        int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends