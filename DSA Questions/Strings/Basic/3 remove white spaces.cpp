#include <bits/stdc++.h>
#define en "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    getline(cin, str);
    cout << str << en;
    cout << "Removing white spaces " << endl;

    // for removeing white spaces
    for (int i = str.size() - 1; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            // cout << "white space" << en;
            str.erase(str.begin() + i);
        }
    }
    cout << str << en;
    return 0;
}