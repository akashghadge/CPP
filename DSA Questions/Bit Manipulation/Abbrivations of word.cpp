#include <iostream>
using namespace std;
#include "vector"
#include "string"
// abrivation is write count on zeroth bit i.c if str =pep and for 010 1e1 for 110 2p for 110 pe1
// here important note is we calculate from msb i.e 1000 from 1 not from lsb
vector<string> abbrivation(string str)
{
    int size = str.size();
    vector<string> ans;
    for (int i = 0; i < (1 << size); i++)
    {
        string Ansstr = "";
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            int bit = i & (1 << size - j - 1);
            if (bit == 0)
            {
                if (count == 0)
                {
                    Ansstr.push_back(str[j]);
                }
                else
                {
                    Ansstr += to_string(count);
                    Ansstr.push_back(str[j]);
                    count = 0;
                }
            }
            else
            {
                count++;
            }
        }
        if (count > 0)
        {
            Ansstr += to_string(count);
        }
        ans.push_back(Ansstr);
    }
    return ans;
}
void printVector(vector<string> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }
    cout << endl;
}
int main()
{
    string str;
    cin >> str;
    vector<string> ans = abbrivation(str);
    printVector(ans);
}