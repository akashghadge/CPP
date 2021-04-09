#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node *LINK;
LINK head;
LINK temp;
void displayCircular();
void makeItCircular();
void create_list1();
int main()
{
    create_list1();
    makeItCircular();
    displayCircular();
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
void displayCircular()
{
    LINK temp_display = head;
    do
    {
        cout << temp_display->data;
        cout << " ";
        temp_display = temp_display->next;
    } while (temp_display != head);
}
void makeItCircular()
{
    LINK temp_traverse = head;
    while (temp_traverse->next != NULL)
    {
        temp_traverse = temp_traverse->next;
    }
    temp_traverse->next = head;
}