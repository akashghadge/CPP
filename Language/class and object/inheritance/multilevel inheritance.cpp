#include <iostream>
using namespace std;
class EMP
{
protected:
    int EMPid;
    int salary;

public:
    EMP() {}
    string name;
    EMP(int id, int salary_temp, string name_temp)
    {
        EMPid = id;
        salary = salary_temp;
        name = name_temp;
    }
    void setID(int id)
    {
        EMPid = id;
    }
    void setNAME(string name_temp)
    {
        name = name_temp;
    }
    void setSALARY(int salary_temp)
    {
        salary = salary_temp;
    }
    void getData()
    {
        cout << "THE ID OF THE EMP IS THE :" << EMPid << endl;
        cout << "THE NAME OF THE EMP IS THE :" << name << endl;
        cout << "THE SALARY OF THE EMP IS THE :" << salary << endl;
    }
};
class COMPUTER_ENGINEER : public EMP
{
protected:
    string role;

public:
    COMPUTER_ENGINEER() {}
    COMPUTER_ENGINEER(string role_tmep)
    {
        role = role_tmep;
    }

    void setRole(string role_temp)
    {
        role = role_temp;
    }
    void getRole()
    {
        cout << "THE ROLE OF THE COMPUTER ENGINEER IN THE COMPANY IS :" << role << endl;
    }
};
class LANG : public COMPUTER_ENGINEER
{
protected:
    string lang;

public:
    LANG() {}
    LANG(string lang_temp)
    {
        lang = lang_temp;
    }
    void setLang(string lang_temp)
    {
        lang = lang_temp;
    }
    void getLang()
    {
        cout << "THE USED TO LANGUAGE OF THE COMPUTER ENGINEER  IS :" << lang << endl;
    }
    void display_all()
    {
        getData();
        getRole();
        getLang();
    }
};
int main()
{
    LANG l1("CPP");
    l1.setID(1);
    l1.setNAME("Akash");
    l1.setSALARY(50000);
    l1.setRole("FULL_STACK_DEVLOPER");
    l1.display_all();
}