/*
The game is simple. You initially have ‘H’ amount of health and ‘A’ amount of armor. At any instant you can live in any of the three places - fire, water and air. After every unit time, you have to change your place of living. For example if you are currently living at fire, you can either step into water or air.

If you step into air, your health increases by 3 and your armor increases by 2

If you step into water, your health decreases by 5 and your armor decreases by 10

If you step into fire, your health decreases by 20 and your armor increases by 5

If your health or armor becomes <=0, you will die instantly

Find the maximum time you can survive.

Input:

The first line consists of an integer t, the number of test cases. For each test case there will be two positive integers representing the initial health H and initial armor A.


Output:

For each test case find the maximum time you can survive.

 

Note: You can choose any of the 3 places during your first move.

 

Input Constraints:

1 <= t <= 10
1 <= H, A <= 1000

Example:

Sample Input:

3
2 10
4 4
20 8
Sample Output:

1
1
5

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
int sol(int health, int armor)
{
    int time = 0;
    while (1)
    {
        if (health <= 0 || armor <= 0)
            break;

        if (time % 2 == 0)
        {
            health += 3;
            armor += 2;
        }
        else
        {
            if (armor > 10)
            {
                health -= 5;
                armor -= 10;
            }
            else
            {
                health -= 20;
                armor += 5;
            }
        }
        time++;
    }
    return time - 1;
}
int main()
{
    FAST;
    int T;
    cin >> T;
    while (T--)
    {
        int health, armour;
        cin >> health >> armour;
        cout << sol(health, armour) << en;
    }

    return 0;
}