#include <iostream>
using namespace std;
class YEAR
{
public:
    YEAR()
    {
    }
    YEAR(int y)
    {
        cout << "YOU ENTER THE YEAR IN THE INT FORMAT:" << y << endl;
    }
    YEAR(string Y)
    {
        cout << "YOU ENTER THE YEAR  IN STRING FORMAT:" << Y << endl;
    }
};
int main()
{
    int y;
    string Y;
    cout << "PLEASE ENTER THE YEAR ";
    cin >> y;
    YEAR o1(y);
    cout << "THE NEXT TYPE " << endl;
    cout << "PLEASE ENTER THE YEAR";
    cin >> Y;
    YEAR o2(Y);
}