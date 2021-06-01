/*
Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".

 

Example 1:

Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"
Example 2:

Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"

*/

#include <bits/stdc++.h>
#define en "\n"
using namespace std;
class Solution
{
public:
    string defangIPaddr(string address)
    {
        for (int i = 0; i < address.size(); i++)
        {
            if (address[i] == '.')
            {
                address.erase(i, 1);
                address.insert(i++, "[");
                address.insert(i++, ".");
                address.insert(i++, "]");
            }
        }
        return address;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}