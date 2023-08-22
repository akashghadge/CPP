#include <iostream>
using namespace std;

int main()
{
    try
    {
        throw 'a';
        3 / 0;
    }
    catch (int a)
    {
        cout << a;
    }
    catch (char c)
    {
        cout << c;
    }
    catch (logic_error f)
    {
    }
}