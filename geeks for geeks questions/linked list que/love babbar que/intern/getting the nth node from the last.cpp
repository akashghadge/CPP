#include <iostream>
using namespace std;
int endpoint;
struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node *LINK;
LINK head;
LINK temp;
void create_list1();
void serch_list(int target);
int main()
{
    int target;
    create_list1();
    cout << "PLEASE ENTER THE NUMBER OF THE NODE :" << endl;
    cin >> target;
    target = endpoint - target;
    cout << "the target have the value:" << target << endl;
    cout << "the value of the endpoint is the :" << endpoint << endl;

    if (target < 0)
    {
        cout << "THE LIST DOES NOT HAVE THE NODE :" << endl;
    }
    else
    {
        serch_list(target);
    }

    return 0;
}
void create_list1()
{
    LINK newnode;
    int terminate = 1;
    endpoint = 0;
    while (terminate)
    {
        newnode = (LINK) new (struct Node);
        cout << "PLEASE ENTER THE DATA IN THE LIST:" << endl;
        cin >> newnode->data;
        newnode->next = NULL;
        endpoint++;
        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        cout << "ARE YOU WANT TO CONTINUE:" << endl;
        cin >> terminate;
    }
}
void serch_list(int target)
{
    LINK temp_traverse;
    temp_traverse = head;
    int flag_present = 1;
    int current_node_no = 0;
    while (temp_traverse != NULL)
    {
        current_node_no++;
        if (current_node_no == target)
        {
            cout << "THE DATA IS PRESENT IN THE LIST AT THE " << current_node_no << " POSITION IS " << temp_traverse->data << endl;
            flag_present = 0;
            break;
        }
        temp_traverse = temp_traverse->next;
    }
    if (flag_present)
    {
        cout << "THE INDEX IS NOT PRESENT IN THE LIST :" << endl;
    }
}