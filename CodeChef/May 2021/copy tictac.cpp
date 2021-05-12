#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <algorithm>
#include <chrono>
#include <cmath>
#include <complex>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef vector<pii> vii;
typedef vector<pll> vll;
ll MOD = 998244353;
double eps = 1e-12;
const int adj[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
#define el "\n"
#define dbg(x) cout << #x << " = " << x << el
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define oo 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
string s[3];
int count_x, count_o, count_space;
void count()
{
    count_x = count_o = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            if (s[i][j] == 'X')
                count_x++;
            if (s[i][j] == 'O')
                count_o++;
        }
    count_space = 9 - count_x - count_o;
}
bool check_win(char symbol)
{
    if (s[0][0] == symbol && s[0][0] == s[1][1] && s[1][1] == s[2][2])
        return 1;
    if (s[0][2] == symbol && s[0][2] == s[1][1] && s[1][1] == s[2][0])
        return 1;
    for (int i = 0; i < 3; i++)
    {
        if (s[i][0] == symbol && s[i][0] == s[i][1] && s[i][1] == s[i][2])
            return 1;
        if (s[0][i] == symbol && s[0][i] == s[1][i] && s[1][i] == s[2][i])
            return 1;
    }
    return 0;
}
int check()
{
    if (count_x < count_o)
        return 3;
    if (count_x > count_o + 1)
        return 3;
    bool x_win = check_win('X');
    bool o_win = check_win('O');
    if (x_win && o_win)
        return 3;
    if (x_win && count_x == count_o)
        return 3;
    if (o_win && count_x > count_o)
        return 3;
    if (x_win || o_win)
        return 1;
    if (count_space == 0)
        return 1;
    return 2;
}
void solve()
{
    for (int i = 0; i < 3; i++)
        cin >> s[i];
    count();
    cout << check() << el;
}
int main()
{
    fast_cin();
    int test_case;
    cin >> test_case;
    for (int i_test = 1; i_test <= test_case; i_test++)
        solve();
    return 0;
}