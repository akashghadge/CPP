#include <iostream>
using namespace std;
#include <vector>
void printVector(vector<string> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "At Index " << i << " Vector have : " << vec[i] << endl;
    }
    cout << endl;
}
vector<string> subset(string str)
{
    vector<string> ans;
    int n = 1 << str.size();
    for (int i = 0; i < n; i++)
    {

        int temp = i;
        string strT = "";
        int j = 0;
        while (temp)
        {
            if (temp & 1)
            {
                strT += str[j];
            }
            temp >>= 1;
            j++;
        }
        ans.push_back(strT);
    }
    return ans;
}
int main()
{
    string str = "abc";
    vector<string> ans = subset(str);
    printVector(ans);
}