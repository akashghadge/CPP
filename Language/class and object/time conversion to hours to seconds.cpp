#include <iostream>
using namespace std;
class TIME
{
    long int sec_time;
    long int sec_time_temp;
    short int hour;
    int minutes;

public:
    void conversion()
    {
        sec_time_temp = sec_time;
        hour = sec_time / 3600;
        sec_time = sec_time % 3600;
        minutes = sec_time / 60;
        sec_time = sec_time % 60;
    }
    void display()
    {
        cout << "AFTER CONVERSION THE TIME IS ......" << endl;
        cout << "IT HAVE  " << hour << " HOURS  " << minutes << " MINUTES AND THE REMAINIG " << sec_time << " SECONDS" << endl;
    }
    void get()
    {
        cout << "PLEASE ENTER THE TIME (IN SECONDS)" << endl;
        cin >> sec_time;
        conversion();
        display();
    }
};
int main()
{
    TIME a;
    a.get();
}