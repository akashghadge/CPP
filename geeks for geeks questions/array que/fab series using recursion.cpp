#include <iostream>
using namespace std;
int fab(int num);
static long long int count;
int main()
{
    long long int result;
    result = fab(10);
    cout << "THE FINAL RESULT IS THE " << result << " AFTER THE " << count << " COUNTS ." << endl;
}
int fab(int num)
{
    count++;
    long int sum;
    if (num < 0)
    {
        exit(0);
    }

    else if (num == 0)
    {
        return 0;
    }
    else if (num == 1)
    {
        return 1;
    }
    sum = fab(num - 1) + fab(num - 2);
    return sum;
}