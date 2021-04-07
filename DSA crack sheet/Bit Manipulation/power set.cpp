#include <iostream>
using namespace std;
#include "vector"
#include "algorithm"
#include "string"

void printVector(vector<string> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "At Index " << i << " Vector have : " << vec[i] << endl;
    }
    cout << endl;
}

vector<string> power(string s)
{
    //foro storing data
    vector<string> ans;
    //  if size is zero then return null ans
    if (s.size() == 0)
    {
        return ans;
    }
    // get max possibilityes can be calculated
    int max_number = 1 << s.size();
    // iterate upto max number of possibiliteis

    /*
                that is 
                for "ab"
                00    ""
                01    "a"
                10    "b"
                11    "ab"
            */
    // so accrding to on bit just add char to string
    for (int i = 1; i < max_number; i++)
    {
        int temp = i;
        string st = "";
        int j = 0;
        while (temp)
        {
            int set_bit = temp & 1;
            if (set_bit)
            {
                st += s[j];
            }
            temp = temp >> 1;
            j++;
        }
        ans.push_back(st);
    }
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<string> ans = power("akash");
    printVector(ans);
}