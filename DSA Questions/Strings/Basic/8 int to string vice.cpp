#include <bits/stdc++.h>
#define en "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str = "123";
    // string to int
    int a = stoi(str);
    a += 2;
    cout << a << en;

    // char array to int
    char arr[] = {'1', '2', '1'};
    int b = atoi(arr);
    b += 4;
    cout << b << en;

    // int to string
    string s = to_string(a + b);
    cout << s << en;
    return 0;
}