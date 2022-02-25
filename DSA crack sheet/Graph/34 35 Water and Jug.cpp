/*
You are given an m liter jug and a n liter jug. Both the jugs are initially empty. The jugs don’t have markings to allow measuring smaller quantities. You have to use the jugs to measure d liters of water where d is less than n.

(X, Y) corresponds to a state where X refers to the amount of water in Jug1 and Y refers to the amount of water in Jug2
Determine the path from the initial state (xi, yi) to the final state (xf, yf), where (xi, yi) is (0, 0) which indicates both Jugs are initially empty and (xf, yf) indicates a state which could be (0, d) or (d, 0).

The operations you can perform are:

Empty a Jug, (X, Y)->(0, Y) Empty Jug 1
Fill a Jug, (0, 0)->(X, 0) Fill Jug 1
Pour water from one jug to the other until one of the jugs is either empty or full, (X, Y) -> (X-d, Y+d)
Examples:

Input : 4 3 2
Output : {(0, 0), (0, 3), (3, 0), (3, 3), (4, 2), (0, 2)}
Recommended: Please try your approach on {IDE} first, before moving on to the solution.
We have discussed the optimal solution in The Two Water Jug Puzzle. In this post, a BFS based solution is discussed.

Here, we keep exploring all the different valid cases of the states of water in the jug simultaneously until and unless we reach the required target water.

As provided in the problem statement, at any given state we can do either of the following operations:

1. Fill a jug

2. Empty a jug

3. Transfer water from one jug to another until either of them gets completely filled or empty.

Running of the algorithm:

We start at an initial state in the queue where both the jugs are empty. We then continue to explore all the possible intermediate states derived from the current jug state using the operations provided.

We also, maintain a visited matrix of states so that we avoid revisiting the same state of jugs again and again.

Cases	Jug 1	Jug 2	Is Valid
Case 1	Fill it	Empty it	✔
Case 2	Empty it	Fill it	✔
Case 3	Fill it	Fill it	Redundant case
Case 4	Empty it	Empty it	Already visited (Initial State)
Case 5	Unchanged	Fill it	✔
Case 6	Fill it	Unchanged	✔
Case 7	Unchanged	Empty	✔
Case 8	Empty	Unchanged	✔
Case 9	Transfer water from this 	Transfer water into this	✔
Case 10	Transfer water into this 	Transfer water from this 	✔
From the table above, we can observe that the state where both the jugs are filled is redundant as we won’t be able to continue ahead / do anything with this state in any possible way.

So, we proceed, keeping in mind all the valid state cases (as shown in the table above) and we do a BFS on them.

In the BFS, we firstly skip the states which was already visited or if the amount of water in either of the jugs exceeded the jug quantity.

If we continue further, then we firstly mark the current state as visited and check if in this state, if we have obtained the target quantity of water in either of the jugs, we can empty the other jug and return the current state’s entire path.

But, if we have not yet found the target quantity, we then derive the intermediate states from the current state of jugs i.e. we derive the valid cases, mentioned in the table above (go through the code once if you have some confusion).

We keep repeating all the above steps until we have found our target or there are no more states left to proceed with.


*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
void printpath(map<pii, pii> mp, pii u)
{
    if (u.first == 0 && u.second == 0)
    {
        cout << 0 << " " << 0 << endl;
        return;
    }
    printpath(mp, mp[u]);
    cout << u.first << " " << u.second << endl;
}
void BFS(int a, int b, int target)
{
    map<pii, int> m;
    bool isSolvable = false;
    vector<tuple<int, int, int>> path;
    map<pii, pii> mp;

    queue<pii> q;

    q.push(make_pair(0, 0));
    while (!q.empty())
    {

        auto u = q.front();
        // cout<<u.first<<" "<<u.second<<endl;
        q.pop();
        if (m[u] == 1)
            continue;

        if ((u.first > a || u.second > b || u.first < 0 || u.second < 0))
            continue;
        // cout<<u.first<<" "<<u.second<<endl;

        m[{u.first, u.second}] = 1;

        if (u.first == target || u.second == target)
        {
            isSolvable = true;

            printpath(mp, u);
            if (u.first == target)
            {
                if (u.second != 0)
                    cout << u.first << " " << 0 << endl;
            }
            else
            {
                if (u.first != 0)
                    cout << 0 << " " << u.second << endl;
            }
            return;
        }
        // completely fill the jug 2
        if (m[{u.first, b}] != 1)
        {
            q.push({u.first, b});
            mp[{u.first, b}] = u;
        }

        // completely fill the jug 1
        if (m[{a, u.second}] != 1)
        {
            q.push({a, u.second});
            mp[{a, u.second}] = u;
        }

        // transfer jug 1 -> jug 2
        int d = b - u.second;
        if (u.first >= d)
        {
            int c = u.first - d;
            if (m[{c, b}] != 1)
            {
                q.push({c, b});
                mp[{c, b}] = u;
            }
        }
        else
        {
            int c = u.first + u.second;
            if (m[{0, c}] != 1)
            {
                q.push({0, c});
                mp[{0, c}] = u;
            }
        }
        // transfer jug 2 -> jug 1
        d = a - u.first;
        if (u.second >= d)
        {
            int c = u.second - d;
            if (m[{a, c}] != 1)
            {
                q.push({a, c});
                mp[{a, c}] = u;
            }
        }
        else
        {
            int c = u.first + u.second;
            if (m[{c, 0}] != 1)
            {
                q.push({c, 0});
                mp[{c, 0}] = u;
            }
        }

        // empty the jug 2
        if (m[{u.first, 0}] != 1)
        {
            q.push({u.first, 0});
            mp[{u.first, 0}] = u;
        }

        // empty the jug 1
        if (m[{0, u.second}] != 1)
        {
            q.push({0, u.second});
            mp[{0, u.second}] = u;
        }
    }
    if (!isSolvable)
        cout << "No solution";
}

int main()
{
    int Jug1 = 5, Jug2 = 7, target = 3;
    cout << "Path from initial state "
            "to solution state ::\n";
    BFS(Jug1, Jug2, target);
    return 0;
}
