#include <iostream>
using namespace std;
class PLANE
{
protected:
    int total_seats_first;
    int total_seats_buss;
    int total_seats_eco;
    int tickets_rem_first;
    int tickets_sell_first;
    int tickets_rem_buss;
    int tickets_sell_buss;
    int tickets_rem_eco;
    int tickets_sell_eco;
    int ticket_prizze_buss;
    int ticket_prizze_eco;
    int ticket_prizze_first;
    string name;
    const int index_no = 1;
    void setValue()
    {
        cout << "ENETER THE NAME OF THE PLANE" << endl;
        cin >> name;

        cout << "ENTER THE TOTAL SEATS IN THE FIRST CLASS" << endl;
        cin >> total_seats_first;

        cout << "ENTER THE TOTAL SEATS IN THE BUSS CLASS" << endl;
        cin >> total_seats_buss;

        cout << "ENTER THE TOTAL SEATS IN THE ECO CLASS" << endl;
        cin >> total_seats_eco;
    }
    void ticketRem()
    {
        tickets_rem_eco = total_seats_eco - tickets_sell_eco;
        tickets_rem_buss = total_seats_buss - tickets_sell_buss;
        tickets_rem_first = total_seats_first - tickets_sell_first;
        cout << "TICKETS REMAINING IN ECO CLASS IS " << tickets_rem_eco << endl;
        cout << "TICKETS REMAINING IN BUSS CLASS IS " << tickets_rem_buss << endl;
        cout << "TICKETS REMAINING IN FIRST CLASS IS " << tickets_rem_first << endl;
    }
    void setPrize()
    {
        cout << "SET FIRST CLASS TICKET PRIZE TO :" << endl;
        cin >> ticket_prizze_first;

        cout << "SET BUSS CLASS TICKET PRIZE TO :" << endl;
        cin >> ticket_prizze_buss;

        cout << "SET ECO CLASS TICKET PRIZE TO :" << endl;
        cin >> ticket_prizze_eco;
    }
    void getSellinfo()
    {
        cout << "ECO SELL TICKES ARE :" << tickets_sell_eco << endl;
        cout << "ECO SELL TICKES ARE :" << tickets_sell_buss << endl;
        cout << "ECO SELL TICKES ARE :" << tickets_sell_first << endl;
    }

public:
};
int main()
{
}