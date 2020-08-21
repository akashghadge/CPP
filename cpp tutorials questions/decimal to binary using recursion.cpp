#include <iostream>
using namespace std;
int num;
int result[32];
int i = 0;
int main()
{
    if (i == 0)
    {
        for (i = 0; i < 32; i++)
        {
            result[i] = EOF;
        }
        i = 0;
        cout << "PLEASE ENTER THE DECIMAL NO :" << endl;
        cin >> num;
        i++;
    }
    if (num == 1)
    {
        result[i] = 1;
        for (i = 31; i >= 1; i--)
        {
            if (result[i] != EOF)
            {
                cout << result[i];
            }
        }
        return 0;
    }
    else
    {
        result[i] = num % 2;
        num = num / 2;
        i++;
        main();
    }
}