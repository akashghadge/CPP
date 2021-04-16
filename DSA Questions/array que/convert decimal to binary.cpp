#include <iostream>
using namespace std;
void convertBinaryToDecimal(int, int *);

int main()
{
    int num;
    cout << "PLEASE ENTER THE NO:;" << endl;

    cin >> num;
    static int *result = new int[32];
    int i;
    for (i = 0; i < 31; i++)
    {
        result[i] = 0;
    }

    convertBinaryToDecimal(num, result);
    // cout << "HIIIIIII" << endl;
    for (i = 31; i >= 0; i--)
    {
        cout << result[i];
    }
}

void convertBinaryToDecimal(int num, int *result)
{
    int i;
    // int num_temp = num;
    i = 0;
    while (num)
    {
        result[i] = num % 2;
        num = num / 2;
        i++;
    }
}