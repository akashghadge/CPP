#include <iostream>
using namespace std;
class BASE
{
private:
    int data_private;
    void setData_private(int data)
    {
        data_private = data;
    }
    void getData_private()
    {
        cout << "THE PRIVATE DATA IS THE :" << data_private << endl;
    }

public:
    BASE() {}
    int data_public;
    void setData_public(int data)
    {
        data_public = data;
    }
    void getData_public()
    {
        cout << "THE PUBLIC DATA IS THE :" << data_public << endl;
    }
    void set_and_get_private(int data)
    {
        data_private = data;
        cout << "THE PRIVATE DATA IS THE :" << data_private << endl;
    }
    void set_and_get_protected(int data)
    {
        data_protected = data;
        cout << "THE PROTECTED DATA IS THE :" << data_protected << endl;
    }

protected:
    int data_protected;
    void setData_protected(int data)
    {
        data_protected = data;
    }
    void getData_protected()
    {
        cout << "THE PROTECTED DATA IS THE :" << data_protected << endl;
    }
};

class DER : private BASE
{
private:
    int data_private_der;
    void setData_private__der(int data)
    {
        data_private_der = data;
    }
    void getData_private__der()
    {
        cout << "THE PRIVATE DATA IS THE (der):" << data_private_der << endl;
    }

public:
    int data_public_der;
    void setData_public__der(int data)
    {
        data_public_der = data;
    }
    void getData_public__der()
    {
        cout << "THE PUBLIC DATA IS THE (der):" << data_public_der << endl;
    }
    void set_and_get_private_der(int data)
    {
        data_private_der = data;
        cout << "THE PRIVATE DATA IS THE :" << data_private_der << endl;
    }
    void set_and_get_protected_der(int data)
    {
        data_protected_der = data;
        cout << "THE PROTECTED DATA IS THE :" << data_protected_der << endl;
    }

protected:
    int data_protected_der;
    void setData_protected__der(int data)
    {
        data_protected_der = data;
    }
    void getData_protected__der()
    {
        cout << "THE PROTECTED DATA IS THE (der):" << data_protected_der << endl;
    }
};
int main()
{
    BASE b1;
    b1.setData_public(1);
    b1.getData_public();
    // b1.setData_private(10);         YOU COULD NOT ACCESS THE PRIVATE VARIABLES AND METHADS OUTSIDE THE CLASS
    // b1.getData_private();
    // b1.setData_protected(12);          IT SHOWS THE PROPERTIES OF THE PRIVATE MEMBERS OF THE CLASS .  :)
    // b1.getData_protected();
    b1.set_and_get_protected(2); //THE CLASS METHODS CAN ACCESS THE PROTECTED MEMBERS
    b1.set_and_get_private(3);   //THE CLASS METHODS CAN ACCESS THE PRIVATE MEMBERS

    DER d1;
    //                       CLASS INHERITES METHODS FROM THE BASE CLASS ..
    // HERE ALL THE METHODS OF THE BASE CLASS ARE INHERITES AS THE PROTECTED MODE METHODS SO YOU COULD NOT USE IT DIRECTLY :..(
    // d1.setData_public(10);
    // d1.getData_public();
    // // b1.setData_private(10);
    // b1.getData_private();
    // b1.setData_protected(12);
    // b1.getData_protected();
    // d1.set_and_get_protected(2);
    // d1.set_and_get_private(3);

    //                                      CLASS OWN METHODS SAME AS THE BASE CLASS
    d1.setData_public__der(100);
    d1.getData_public__der();
    // d1.setData_private__der(1000);        YOU COULD NOT ACCESS THE PRIVATE VARIABLES AND METHADS OUTSIDE THE CLASS
    // d1.getData_private__der();
    // d1.setData_protected__der(10000);      IT SHOWS THE PROPERTIES OF THE PRIVATE MEMBERS OF THE CLASS .  :)
    // d1.getData_protected__der();
    d1.set_and_get_protected_der(2); //THE CLASS METHODS CAN ACCESS THE PROTECTED MEMBERS
    d1.set_and_get_private_der(3);   //THE CLASS METHODS CAN ACCESS THE PRIVATE MEMBERS
}

/*       NOTES
1.THE PRIVATE METHODS AND VARIABLES ARE NOT ACCESSIBLE OUTSIDE THE CLASS IT MUST BE ACCESS BY THE CLASS METHODS ONLY AND NOT OUTSIDE .
2. THE PROTECTED METHODS ARE SAME AS THE PRIVATE METHODAS IT CANNOT BE ACCESS OUTSIDE OF THE CLASS.
3.IF WE INHERITE THE CLASS IN THE PUBLIC MODE ITS   I)PUBLIC MEMBERS AND METHODS INHERITES AND BECOMES PUBLIC  .
                                                    II)PRIVATE MEMBERS AND METHODS ARE NOT INHERITES .
                                                    III)PROTECTED MEMBERS AND METHODS ARE INHERITES AND BECOMES THE PROTECTED IN DER. CLASS.
4.IF WE INHERITE THE CLASS IN THE PRIVATE MODE ITS  I)PUBLIC MEMBERS ARE BECOMES PRIVATE.
                                                    II)PRIVATE MEMBERS ARE NOT INHERITES .
                                                    III)PROTECTED MEMBERS ARE INHERITES AS THE PRIVATE.
5.IF WE INHERITES THE CLASS IN THE PROTECTE MODE ITS I)PUBLIC MEMBERS ARE BECOMES PRIVATE.
                                                     II)PRIVATE MEMBERS ARE NOT INHERITES.
                                                     III)PROTECTED MEMBERS ARE INHERITES AS THE PROTECTED .

*/