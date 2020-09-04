#include <iostream>
using namespace std;
int power_of_2(int num);
int main()
{
    int num;
    cin >> num;
    int result;
    result = power_of_2(num);
    cout << result;
}
int power_of_2(int num)
{
    int i;
    i = 0;
    int num_temp = num;
    while (num)
    {
        if (num % 2 == 0)
        {
            num = num / 2;
        }
        else if (num == 1 && num != num_temp)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}