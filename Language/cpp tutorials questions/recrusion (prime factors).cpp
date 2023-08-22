#include <iostream>
using namespace std;
int num;
static int i = 1;
int num_temp;
int main()
{
    if (i == 1)
    {
        cout << "PLEASE ENTER THE NO FOR WHICH WOULD LIKE TO FIND FACTORS ....:" << endl;
        cin >> num;
        num_temp = num;
        i++;
    }
    if (num_temp <= i)
    {
        return 0;
    }

    else
    {
        if (num % i == 0)
        {
            cout << i << endl;
            num = num / i;
        }
        else
        {
            i++;
        }
        main();
    }
    
}
