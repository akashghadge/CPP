#include <iostream>
using namespace std;
class PLANE
{
    // static int index_no;
public:
    // int *total_seats_first;
    // int *total_seats_buss;
    // int *total_seats_eco;
    // int *tickets_sell_first;
    // int *tickets_sell_buss;
    // int *tickets_sell_eco;
    // int *ticket_prizze_buss;
    // int *ticket_prizze_eco;
    // int *ticket_prizze_first;
    // int *tickets_rem_eco;
    // int *tickets_rem_buss;
    // int *tickets_rem_first;
    int *total_seats_first = new int;
    int *total_seats_buss = new int;
    int *total_seats_eco = new int;
    int *tickets_sell_first = new int;
    int *tickets_sell_buss = new int;
    int *tickets_sell_eco = new int;
    int *ticket_prizze_buss = new int;
    int *ticket_prizze_eco = new int;
    int *ticket_prizze_first = new int;
    int *tickets_rem_eco = new int;
    int *tickets_rem_buss = new int;
    int *tickets_rem_first = new int;
    string name;
    void setName()
    {
        cout << "PLEASE ENTER THE NAME OF THE FLIGHT:" << endl;
        cin >> name;
    }
    void setValue()
    {
        tickets_sell_buss = 0;
        tickets_sell_eco = 0;
        tickets_sell_first = 0;
        cout << "ENTER THE TOTAL SEATS IN THE FIRST CLASS" << endl;
        cin >> *total_seats_first;

        cout << "ENTER THE TOTAL SEATS IN THE BUSS CLASS" << endl;
        cin >> *total_seats_buss;

        cout << "ENTER THE TOTAL SEATS IN THE ECO CLASS" << endl;
        cin >> *total_seats_eco;
    }
    void setPrize()
    {
        cout << "SET FIRST CLASS TICKET PRIZE TO :" << endl;
        cin >> *ticket_prizze_first;

        cout << "SET BUSS CLASS TICKET PRIZE TO :" << endl;
        cin >> *ticket_prizze_buss;

        cout << "SET ECO CLASS TICKET PRIZE TO :" << endl;
        cin >> *ticket_prizze_eco;
    }

public:
    PLANE() {}
    void getSellinfo()
    {
        cout << "ECO SELL TICKES ARE :" << tickets_sell_eco << endl;
        cout << "ECO SELL TICKES ARE :" << tickets_sell_buss << endl;
        cout << "ECO SELL TICKES ARE :" << tickets_sell_first << endl;
    }
    void getName()
    {
        cout << "THE NAME OF THE FLIGHT IS THE :" << name << endl;
    }
    void ticketRem()
    {
        *tickets_rem_eco = *total_seats_eco - *tickets_sell_eco;
        *tickets_rem_buss = *total_seats_buss - *tickets_sell_buss;
        *tickets_rem_first = *total_seats_first - *tickets_sell_first;
        cout << "TICKETS REMAINING IN ECO CLASS IS " << *tickets_rem_eco << endl;
        cout << "TICKETS REMAINING IN BUSS CLASS IS " << *tickets_rem_buss << endl;
        cout << "TICKETS REMAINING IN FIRST CLASS IS " << *tickets_rem_first << endl;
    }
    void getPrize()
    {
        cout << "TICKETS PRIZE OF ECO CLASS IS " << *ticket_prizze_eco << endl;
        cout << "TICKETS PRIZE OF BUSS CLASS IS " << *ticket_prizze_buss << endl;
        cout << "TICKETS PRIZE OF FIRST CLASS IS " << *ticket_prizze_first << endl;
    }
    void decrement(int a)
    {
        if (a == 1)
        {
            tickets_rem_first--;
        }
        else if (a == 2)
        {
            tickets_rem_buss--;
        }
        else if (a == 3)
        {
            tickets_rem_eco--;
        }
    }
};
class ADMIN : public PLANE
{
public:
    ADMIN() {}
    void SetName()
    {
        setName();
    }
    void SetValue()
    {
        setValue();
    }
    void SetPrize()
    {
        setPrize();
    }
};

class CUSTOMER : protected PLANE
{
    int choice;

public:
    CUSTOMER() {}
    void setValue(PLANE &obj)
    {
        this->total_seats_buss = obj.total_seats_buss;
        this->total_seats_eco = obj.total_seats_eco;
        this->total_seats_first = obj.total_seats_first;
        this->tickets_sell_eco = obj.tickets_sell_eco;
        this->tickets_sell_buss = obj.tickets_sell_buss;
        this->tickets_sell_first = obj.tickets_sell_first;
        this->ticket_prizze_eco = obj.ticket_prizze_eco;
        this->ticket_prizze_buss = obj.ticket_prizze_buss;
        this->ticket_prizze_first = obj.ticket_prizze_first;
        this->tickets_rem_eco = obj.tickets_rem_eco;
        this->tickets_rem_buss = obj.tickets_rem_buss;
        this->tickets_rem_first = obj.tickets_rem_first;
    }
    void bookTicket()
    {
        ticketRem();
        getPrize();
        cout << "PLEASE SELECT WHICH ONE WOULD LIKE TO BOOK:" << endl;
        cout << "1)FIRST CLASS" << endl;
        cout << "1)BUSS CLASS" << endl;
        cout << "1)ECO CLASS" << endl;
        cin >> choice;
        if (choice == 1 && tickets_rem_first > 0)
        {
            tickets_rem_first--;
            cout << "YOU SUCCEFULY BOOK THE TICKET..." << endl;
            cout << "THANK YOU FOR CHOOSING US" << endl;
        }

        else if (choice == 2 && tickets_rem_buss > 0)
        {
            tickets_rem_first--;
            cout << "YOU SUCCEFULY BOOK THE TICKET..." << endl;
            cout << "THANK YOU FOR CHOOSING US" << endl;
        }
        else if (choice == 3 && tickets_rem_eco > 0)
        {
            tickets_rem_first--;
            cout << "YOU SUCCEFULY BOOK THE TICKET..." << endl;
            cout << "THANK YOU FOR CHOOSING US" << endl;
        }
        else
        {
            cout << "PLEASE ENTER THE VALIAD OPTION :-)" << endl;
        }
    }
};

int main()
{
    ADMIN a1;
    a1.SetName();
    a1.SetValue();
    a1.SetPrize();
    a1.getName();
    a1.getSellinfo();
    a1.getPrize();
    CUSTOMER c1;
    c1.setValue(a1);
    c1.bookTicket();
}