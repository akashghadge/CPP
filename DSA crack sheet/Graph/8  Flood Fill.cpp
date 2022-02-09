/*
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.

Return the modified image after performing the flood fill.



Example 1:


Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 2
Output: [[2,2,2],[2,2,2]]


Constraints:

m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], newColor < 216
0 <= sr < m
0 <= sc < n
Accepted
344,375
Submissions
598,161

*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define ll long long
#define v vector
#define vi vector<int>
#define vll vector<ll>
#define vii vector<vector<int>>
#define pii pair<int, int>
#define vpi vector<pair<int, int>>
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Solution
{
public:
    void dfs(vector<vector<int>> &image, int sr, int sc, int newColor, vector<vector<int>> &visited, int start)
    {
        int n = image.size();
        int m = image[0].size();
        if (sr < 0 || sc < 0 || sr >= n || sc >= m || image[sr][sc] != start || visited[sr][sc])
            return;

        visited[sr][sc] = true;
        image[sr][sc] = newColor;
        dfs(image, sr + 1, sc, newColor, visited, start);
        dfs(image, sr - 1, sc, newColor, visited, start);
        dfs(image, sr, sc + 1, newColor, visited, start);
        dfs(image, sr, sc - 1, newColor, visited, start);
    }
    vector<vector<int>> floodFill(vector<vector<int>> image, int sr, int sc, int newColor)
    {
        int n = image.size();
        int m = image[0].size();
        int start = image[sr][sc];
        vector<vector<int>> visited(n, vector<int>(m, 0));
        dfs(image, sr, sc, newColor, visited, start);
        return image;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    FAST;

    return 0;
}