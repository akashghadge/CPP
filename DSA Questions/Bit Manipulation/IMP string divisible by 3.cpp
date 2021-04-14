#include <iostream>
using namespace std;
// here already one concept exists i.e. if difference betwen even and odd is divisible by 11 then number is divisible by 3(decimal)
bool divisible(string str)
{
    int odd = 0;
    int even = 0;
    for (int i = 0; i < str.size(); i++)
    {
        int bit = (int(str[i])) - 48;
        // cout << bit;
        if ((i & 1) == 0)
        {
            even += bit;
        }
        else
        {
            odd += bit;
        }
    }
    int res = even - odd;
    if (res % 11 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    string str;
    cin >> str;
    cout << divisible(str);
}