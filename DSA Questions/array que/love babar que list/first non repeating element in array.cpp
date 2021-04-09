#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int size;
        cin >> size;
        int arr[size];
        int i;
        for (i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
        int flag = 0;
        int j;
        for (i = 0; i < size; i++)
        {

            for (j = 0; j < size; j++)
            {
                if (i != j)
                {
                    if (arr[i] == arr[j])
                    {
                        flag = 1;
                        
                    }
                }
            }
            if (flag == 0)
            {
                cout << arr[i];
                break;
            }
            flag = 0;
        }
    }
}