/*
Notes
** ASCII of 'a'- 97,'z'- 123,'A'- 65,'Z'- 90,'0'- 48,'9'- 57
*/

/*Basic Include */
#include <bits/stdc++.h>
using namespace std;

/* Functions*/
#define forn(i, a, b) for (int i = (a); i < (b); i++)
#define prn(a) cout << a << endl

/* Inputs */
#define var(n) \
    ll n;      \
    cin >> n;
#define var2(a, b) \
    ll a, b;       \
    cin >> a >> b;
#define varv(a, n)             \
    vi a(n);                   \
    for (ll i = 0; i < n; i++) \
        cin >> a[i];
/* Shortcuts */
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define fbo find_by_order // fbo(K) -> Kth element in a Set (counting from zero).
#define ook order_of_key  // ook(K) -> Number of items strictly smaller than K.
#define FAST()                        \
    {                                 \
        ios_base::sync_with_stdio(0); \
        cin.tie(0);                   \
    }
#define en "\n"
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<string> vvs;
typedef vector<ii> vii;
typedef vector<char> vch;
typedef vector<string> vs;
/*
2
2 2
12 12
*****
2
705432
*/
int solve(int m, int n)
{
    vector<int> prev(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                temp[j] = 1;
                continue;
            }

            int up = 0;
            int left = 0;

            if (i > 0)
                up = prev[j];
            if (j > 0)
                left = temp[j - 1];

            temp[j] = up + left;
        }
        prev = temp;
    }

    return prev[n - 1];
}
void sol()
{
    var2(n, m);
    int ans = solve(n, m);
    prn(ans);
}

int main()
{
    FAST();
    ll TEST_CASE = 1;
    cin >> TEST_CASE;
    forn(_, 0, TEST_CASE)
    {
        sol();
    }
    return 0;
}
