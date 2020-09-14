#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
typedef struct node *LINK;
LINK head = NULL;
LINK temp = NULL;
void create_list();
void display();
void reverse();
int main()
{
    create_list();
    reverse();
    display();
}
void create_list()
{
    LINK newnode;
    int terminate = 1;
    int endpoint = 0;
    while (terminate)
    {
        newnode = (LINK) new (struct node);
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
void display()
{
    LINK temp_display;
    temp_display = head;
    while (temp_display != NULL)
    {
        cout << temp_display->data;
        cout << endl;
        temp_display = temp_display->next;
    }
}
void reverse()
{
    LINK prev = NULL;
    LINK current = head;
    LINK nextnode = head;

    while (nextnode != NULL)
    {
        nextnode = nextnode->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    }
    head = prev;
}