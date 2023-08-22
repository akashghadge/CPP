#include <iostream>
#include <string.h>
using namespace std;

class student_info
{
private:
    int insem_marks[2];
    int endsem_marks[2];
    int dob;
    string catogory;
    int annual_income;

public:
    char name[30];
    int roll_ro;
    int year;
    int prn;
    string addres;
    void get_info()
    {
        cout << "PLEASE ENTER THE NAME " << endl;
        gets(name);
        cout << "PLEASE ENTER THE ROLL NUMBER" << endl;
        cin >> roll_ro;
        cout << "PLEASE ENTER THE YEAR" << endl;
        cin >> year;
        cout << "PLEASE ENTER THE PRN NUMBER" << endl;
        cin >> prn;
        cout << "PLEASE ENTER THE ADDRESS" << endl;
        fflush(stdin);
        cin >> addres;
        cout << "PLEASE ENTER THE CATAGORY" << endl;
        cin >> catogory;
        cout << "PLEASE ENTER THE DATE OF BIRTH" << endl;
        cin >> dob;
        cout << "PLEASE ENTER THE ANNUAL INCOME" << endl;
        cin >> annual_income;
        cout << "PLEASE ENTER THE INSEM 1 MARKS " << endl;
        cin >> insem_marks[1];
        cout << "PLEASE ENTER THE ENDSEM 1 MARKS" << endl;
        cin >> endsem_marks[1];
        cout << "PLEASE ENTER THE INSEM 1 MARKS " << endl;
        cin >> insem_marks[2];
        cout << "PLEASE ENTER THE ENDSEM 1 MARKS" << endl;
        cin >> endsem_marks[2];
        cout << endl;
    }
    void display()
    {
        cout << "NAME :" << name << endl;
        cout << "ADDRESS" << addres << endl;
        cout << "ROLL NUMBER" << roll_ro << endl;
        cout << "PRN:" << prn << endl;
        cout << "CATAGORY:" << catogory << endl;
        cout << "YEAR:" << year << endl;
        cout << "DATE OF BIRTH :" << dob << endl;
        cout << "ANNUAL INCOME:" << annual_income << endl;
        cout << "INSEM 1 MARKS:" << insem_marks[1] << endl;
        cout << "ENDSEM 1 MARSK:" << endsem_marks[1] << endl;
        cout << "INSEM 2 MARKS" << insem_marks[2] << endl;
        cout << "ENDSEM 1 MARSK:" << endsem_marks[2] << endl;
    }
};
int main()
{
    student_info student[2];
    student[1].get_info();
    student[1].display();
}