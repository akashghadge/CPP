#include <iostream>
using namespace std;
class EMP
{
    int contract_years = 0;
    void setContract(int a)
    {
        contract_years = a;
    }
    void getContract()
    {
        cout << "THE CONTRACT DURATION OF THE EMP IS :" << contract_years << endl;
    }

public:
    EMP() {}
    int id;
    int year_of_join;
    string name;
    float salary;
    void setData()
    {
        cout << "PLEASE ENTER THE ID OF THE EMP" << endl;
        cin >> id;
        cout << "PLEASE ENTER THE NAME OF THE EMP" << endl;
        cin >> name;
        cout << "PLEASE ENTER THE YEAR OF JOINING OF THE EMP" << endl;
        cin >> year_of_join;
        cout << "PLEASE ENTER THE SALARY OF THE EMP" << endl;
        cin >> salary;
    }
    void getData()
    {
        cout << "THE NAME OF THE EMP IS :" << name << endl;
        cout << "THE ID OF THE EMP IS :" << id << endl;
        cout << "THE YEAR OF JOINGING OF THE EMP IS :" << year_of_join << endl;
        cout << "THE SALARY OF THE EMP IS :" << salary << endl;
    }
};
class PROGRAMMER : public EMP
{
public:
    string lang;
    void setLang(string lang_temp)
    {
        lang = lang_temp;
    }
    void getLang()
    {
        cout << "THE LANG OF THE DEVLOPER IS THE :" << lang << endl;
    }
};

int main()
{
    EMP e1;
    // e1.setData();
    // e1.getData();
    PROGRAMMER e2;
    e2.setData();
    e2.setLang("cpp");
    e2.getData();
    e2.getLang();
}