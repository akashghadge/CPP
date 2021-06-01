/*
You own a Goal Parser that can interpret a string command. The command consists of an alphabet of "G", "()" and/or "(al)" in some order. The Goal Parser will interpret "G" as the string "G", "()" as the string "o", and "(al)" as the string "al". The interpreted strings are then concatenated in the original order.

Given the string command, return the Goal Parser's interpretation of command.

 

Example 1:

Input: command = "G()(al)"
Output: "Goal"
Explanation: The Goal Parser interprets the command as follows:
G -> G
() -> o
(al) -> al
The final concatenated result is "Goal".
Example 2:

Input: command = "G()()()()(al)"
Output: "Gooooal"
Example 3:

Input: command = "(al)G(al)()()G"
Output: "alGalooG"
 

Constraints:

1 <= command.length <= 100
command consists of "G", "()", and/or "(al)" in some order.

*/

#include <bits/stdc++.h>
#define en "\n"
using namespace std;
class Solution
{
public:
    string interpret(string command)
    {
        for (int i = 0; i < command.size(); i++)
        {
            if (command[i] == '(')
            {
                if (command[i + 1] == ')')
                {
                    command.erase(i, 2);
                    command.insert(i, "o");
                }
                else
                {
                    command.erase(i, 4);
                    command.insert(i, "al");
                }
            }
        }
        return command;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}