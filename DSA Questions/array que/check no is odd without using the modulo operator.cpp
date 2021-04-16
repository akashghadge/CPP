#include <iostream>
using namespace std;
int is_odd_without_modulo(int);
int main()
{
    int num;
    cin >> num;
    int result = is_odd_without_modulo(num);
    result ? cout << "No is odd " << endl : cout << "No is even" << endl;
}
int is_odd_without_modulo(int num)
{
    if (num & 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}