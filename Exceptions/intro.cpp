#include <iostream>
using namespace std;

int main()
{
    try
    {
        throw 'a';
    }
    catch (int a)
    {
        cout << a;
    }
    catch (char c)
    {
        cout << c;
    }
}