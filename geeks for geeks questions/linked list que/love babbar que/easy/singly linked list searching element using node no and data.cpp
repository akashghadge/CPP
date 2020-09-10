#include <iostream>
using namespace std;
void create_list1();
struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node *LINK;
LINK head = NULL;
LINK temp = NULL;
void serch_list(int target, int a = 1)
{
    LINK temp_traverse;
    temp_traverse = head;
    int flag_present = 1;
    int current_node_no = 0;
    if (a)
    {
        while (temp_traverse->next != NULL)
        {
            current_node_no++;
            if (temp_traverse->data == target)
            {
                cout << "THE DATA IS PRESENT IN THE LIST AT THE " << current_node_no << " POSITION " << endl;
                flag_present = 0;
            }
            temp_traverse = temp_traverse->next;
        }
        if (flag_present)
        {
            cout << "THE DATA IS NOT PRESENT IN THE LIST :" << endl;
        }
    }
    else
    {
        while (temp_traverse->next != NULL)
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
}
int main()
{
    create_list1();
    serch_list(30);
    serch_list(3, 0);
    serch_list(100);
    serch_list(10, 0);
}
void create_list1()
{
    LINK newnode;
    int terminate = 1;
    while (terminate)
    {
        newnode = (LINK) new (struct Node);
        cout << "PLEASE ENTER THE DATA IN THE LIST:" << endl;
        cin >> newnode->data;
        newnode->next = NULL;
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