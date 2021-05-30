/*
Given a string str, we need to print reverse of individual words.
Examples: 
 

Input : Hello World
Output : olleH dlroW
 
Input :  Geeks for Geeks
Output : skeeG rof skeeG
 

Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Method 1 (Simple): Generate all words separated by space. One by one reverse words and print them separated by space. 
Method 2 (Space Efficient): We use a stack to push all words before space. As soon as we encounter a space, we empty the stack. 
Method 3(stringstream):
*/

#include <bits/stdc++.h>
using namespace std;

void printWords(string str)
{
    // word variable to store word
    string word;

    // making a string stream
    stringstream iss(str);

    // Read and print each word.
    while (iss >> word)
    {
        reverse(word.begin(), word.end());
        cout << word << " ";
    }
}

// Driver code
int main()
{
    string s = "GeeksforGeeks is good to learn";
    printWords(s);
    return 0;
}
// This code is contributed by Nikhil Rawat
