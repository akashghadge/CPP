// A C++ program to generate palindromic numbers
// less than n.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// A utility for creating palindrome
const ll CHEF = 1e8 + 7;
ll chefora[CHEF];
ll createPalindrome(ll input, ll b, ll isOdd)
{
    ll n = input;
    ll palin = input;

    // checks if number of digits is odd or even
    // if odd then neglect the last digit of input in
    // finding reverse as in case of odd number of
    // digits middle element occur once
    if (isOdd)
        n /= b;

    // Creates palindrome by just appending reverse
    // of number to itself
    while (n > 0)
    {
        palin = palin * b + (n % b);
        n /= b;
    }
    return palin;
}

// Function to print decimal palindromic number
void generatePalindromes(ll n)
{
    ll number;
    ll i = 1;
    while ((number = createPalindrome(i, 10, 1)) < n)
    {
        chefora[i] = number;
        i++;
    }
    cout << i << endl;
}
void printVector(vector<ll> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " " << endl;
    }
    cout << endl;
}
int main()
{
    ll n = 1e9 + 7;
    generatePalindromes(n);
    cout << chefora[99999] << endl;
    return 0;
}
