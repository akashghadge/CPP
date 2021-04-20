#include <iostream>
using namespace std;
#include <algorithm>
string d2any(int n, int b)
{
    string str = "";
    while (n)
    {
        string temp = to_string(n % b);
        n = n / b;
        str += temp;
    }
    reverse(str.begin(), str.end());
    return str;
}
int main()
{
    int N;
    int base;
    cin >> N >> base;
    cout << d2any(N, base);
}