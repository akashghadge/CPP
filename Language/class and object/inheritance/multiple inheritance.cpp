#include <iostream>
using namespace std;
class FORNT_END
{
protected:
    string lang_static = "HTML";
    string lang_style = "CSS";
    string lang_dynamic;
    int framwork;

public:
    FORNT_END() {}
    FORNT_END(string lang_dynamic_temp, int framwork_temp)
    {
        lang_dynamic = lang_dynamic_temp;
        framwork = framwork_temp;
    }
    void SetData_frontend()
    {
        cout << "PLEASE ENTER THE LANGUAGE FOR THE DYNAMIC VIEW OF THE WEBPAGE:" << endl;
        cin >> lang_dynamic;
        cout << "IF YOU USE ANGULAR ENTER THE 1" << endl;
        cout << "IF YOU USE REACT ENTER THE 2" << endl;
        cout << "IF YOU USE ANOTHER FRAMWORK ENTER THE 3" << endl;
        cin >> framwork;
    }
    void GetData_frontend()
    {
        cout << "THE STATIC VIEW LANGUAGE IS HTML AND STYLE LANGUAGE IS CSS" << endl;
        cout << "THE DYNAMIC VIEW LANGUAGE IS THE " << lang_dynamic << endl;
        cout << "THE FRAMWORK YOU USE IS " << framwork << endl;
    }
};
class BACK_END
{
protected:
    string server_lang;
    string database;

public:
    BACK_END() {}
    BACK_END(string server_lang_temp, string database_temp)
    {
        server_lang = server_lang_temp;
        database = database_temp;
    }
    void SetData_backend()
    {
        cout << "PLEASE ENTER THE LANGUAGE YOU USE IN THE BACKEND:" << endl;
        cin >> server_lang;
        cout << "PLEASE ENTER THE DATABASE TYPE YOU USE :" << endl;
        cin >> database;
    }
    void GetData_backend()
    {
        cout << "YOU USE THE " << server_lang << " LANGUAGE AND THE " << database << " DATABASE IN BACKEND" << endl;
    }
};
class FULLSTACK : public FORNT_END, public BACK_END
{
public:
    FULLSTACK() {}
    FULLSTACK(string lang_dynamic_temp, int framwork_temp, string server_lang_temp, string database_temp)
    {
        lang_dynamic = lang_dynamic_temp;
        framwork = framwork_temp;
        server_lang = server_lang_temp;
        database = database_temp;
    }
    void setAll()
    {
        SetData_frontend();
        SetData_backend();
    }
    void display_all()
    {
        GetData_frontend();
        GetData_backend();
    }
};
int main()
{
    FULLSTACK f1("javascript", 1, "javascript", "mongodb");
    f1.display_all();
}