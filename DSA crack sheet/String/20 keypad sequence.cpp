/*
Given a sentence in the form of a string, convert it into its equivalent mobile numeric keypad sequence. 
 

Mobile-keypad

Examples : 
 

Input : GEEKSFORGEEKS
Output : 4333355777733366677743333557777
For obtaining a number, we need to press a
number corresponding to that character for 
number of times equal to position of the 
character. For example, for character C, 
we press number 2 three times and accordingly.

Input : HELLO WORLD
Output : 4433555555666096667775553
 

Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Follow the steps given below to convert a sentence into its equivalent mobile numeric keypad sequence. 

*/
#include <bits/stdc++.h>
#define en "\n"
using namespace std;
void printVector(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "At Index " << i << " Vector have : " << vec[i] << endl;
    }
    cout << endl;
}
string sol(string &str)
{
    string ans = "";
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
        {
            ans.push_back('0');
        }
        else if (str[i] == 'Z')
        {
            ans.append("9999");
        }
        else
        {
            int position = str[i] - 'A';
            if (position > 17)
                position--;
            int keyCode = (position / 3) + 2;
            int times = 1;
            if (str[i] == 'S')
                times = 4;
            else
            {
                times = (position % 3) + 1;
            }
            string code = to_string(keyCode);
            ans.insert(ans.end(), times, code[0]);
        }
    }
    return ans;
}
string printSequence(string arr[],
                     string input)
{
    string output = "";

    // length of input string
    int n = input.length();
    for (int i = 0; i < n; i++)
    {
        // Checking for space
        if (input[i] == ' ')
            output = output + "0";

        else
        {
            // Calculating index for each
            // character
            int position = input[i] - 'A';
            output = output + arr[position];
        }
    }

    // Output sequence
    return output;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    string str1[] = {"2", "22", "222",
                     "3", "33", "333",
                     "4", "44", "444",
                     "5", "55", "555",
                     "6", "66", "666",
                     "7", "77", "777", "7777",
                     "8", "88", "888",
                     "9", "99", "999", "9999"};
    // cin >> str;
    getline(cin, str);
    cout << sol(str) << en;
    cout << printSequence(str1, str) << en;
    return 0;
}