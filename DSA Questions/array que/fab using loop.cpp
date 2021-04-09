#include <iostream>
using namespace std;
int fab(int);
int main()
{
    int result;
    result = fab(7);
    cout << result;
}
int fab(int num)
{
    int sum = 1;
    if (num == 0)
    {
        return 0;
    }
    else if (num == 1)
    {
        return 1;
    }
    else
    {
        int i = 1;
        int prev = 1;
        int prev_pre = 0;
        while (i <= num)
        {
            sum = prev_pre + prev;
            prev_pre = prev;
            prev = sum;
            i++;
        }
        return sum;
    }
}