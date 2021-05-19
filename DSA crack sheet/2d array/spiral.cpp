#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
    {
        // code here
        // int total = c * r;
        // vector<int> res(c * r);
        // int minR = 0;
        // int minC = 0;
        // int maxC = c - 1;
        // int maxR = r - 1;
        // int index = 0;
        // while (index<total)
        // {
        //     // cout << "hello" << endl;
        //     // printf("hello\n");
        //     for (int i = minC; i <= maxC; i++)
        //     {
        //         res[index] = matrix[minR][i];
        //         index++;
        //     }
        //     if(minR != maxR)
        //     {
        //         minR++;
        //     }
        //     for (int i = minR; i <= maxR; i++)
        //     {
        //         res[index] = matrix[i][maxC];
        //         index++;
        //     }
        //     if(minC != maxC)
        //     {
        //         maxC--;
        //     }
        //     for (int i = maxC; i >= minC; i--)
        //     {
        //         res[index] = matrix[maxR][i];
        //         index++;
        //     }
        //     if(minR != maxR)
        //     {
        //         maxR--;
        //     }
        //     for (int i = maxR; i >= minR; i--)
        //     {
        //         res[index] = matrix[i][minC];
        //         index++;
        //     }
        //     if(minC != maxC)
        //     {
        //         minC++;
        //     }
        // }
        // return res;
        int n = 0;
        int x = 0;
        int y = 0;
        int total = r * c;
        vector<int> output;
        while (n != total)
        {
            // right traversal
            for (int i = 0; i < c; i++)
            {
                if (n == total)
                    break;
                output.push_back(matrix[x][y]);
                y++;
                n++;
            }
            y--;
            c--;
            r--;
            x++;

            // down traversal
            for (int i = 0; i < r; i++)
            {
                if (n == total)
                    break;
                output.push_back(matrix[x][y]);
                x++;
                n++;
            }
            x--;
            r--;
            y--;

            // left traversal
            for (int i = 0; i < c; i++)
            {
                if (n == total)
                    break;
                output.push_back(matrix[x][y]);
                y--;
                n++;
            }
            y++;
            c--;
            x--;

            // up traversal
            for (int i = 0; i < r; i++)
            {
                if (n == total)
                    break;
                output.push_back(matrix[x][y]);
                x--;
                n++;
            }
            x++;
            y++;
        }
        return output;
    }
};
class Solution
{
public:
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
    {
        // code here
        int total = c * r;
        vector<int> res(c * r);
        int minR = 0;
        int minC = 0;
        int maxC = c - 1;
        int maxR = r - 1;
        int index = 0;
        while (minR <= maxR && minC <= maxC)
        {
            // cout << "hello" << endl;
            // printf("hello\n");
            for (int i = minC; i <= maxC; i++)
            {
                res[index] = matrix[minR][i];
                index++;
            }
            minR++;
            for (int i = minR; i <= maxR; i++)
            {
                res[index] = matrix[i][maxC];
                index++;
            }
            maxC--;
            for (int i = maxC; i >= minC; i--)
            {
                res[index] = matrix[maxR][i];
                index++;
            }
            maxR--;
            for (int i = maxR; i >= minR; i--)
            {
                res[index] = matrix[i][minC];
                index++;
            }
            minC++;
        }
        return res;
    }
};
int main()
{
    int r = 4, c = 4;
    int matrix[r][c] = {{1, 2, 3, 4},
                        {5, 6, 7, 8},
                        {9, 10, 11, 12},
                        {13, 14, 15, 16}};
    int total = c * r;
    vector<int> res(c * r);
    int minR = 0;
    int minC = 0;
    int maxC = c - 1;
    int maxR = r - 1;
    int index = 0;
    while (index < total)
    {
        // cout << "hello" << endl;
        // printf("hello\n");
        for (int i = minC; i <= maxC; i++)
        {
            res[index] = matrix[minR][i];
            index++;
        }
        minR++;
        for (int i = minR; i <= maxR; i++)
        {
            res[index] = matrix[i][maxC];
            index++;
        }
        maxC--;
        for (int i = maxC; i >= minC; i--)
        {
            res[index] = matrix[maxR][i];
            index++;
        }
        maxR--;
        for (int i = maxR; i >= minR; i--)
        {
            res[index] = matrix[i][minC];
            index++;
        }
        minC++;
    }
    for (int i = 0; i < r * c; i++)
    {
        cout << res[i] << endl;
    }
}

// 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
