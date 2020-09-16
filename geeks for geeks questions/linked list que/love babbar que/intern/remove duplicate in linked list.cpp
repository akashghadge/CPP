#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};

typedef struct node *LINK;
LINK head;
LINK temp;
void create();
void display();
void eleDuplicate();
int main()
{
    create();
    display();
    eleDuplicate();
    display();
}
void create()
{
    LINK newnode;
    int terminate = 1;
    int i = 1;
    while (terminate)
    {

        newnode = (LINK) new (struct node);
        cout << "PLEASE ENTER THE DATA:" << endl;
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
        i++;
        if (i == 6)
        {
            terminate = 0;
        }
    }
}
void display()
{
    LINK temp_display;
    temp_display = head;
    int position = 1;
    while (temp_display != NULL)
    {
        cout << "THE DATA AT THE " << position << " IS THE : " << temp_display->data << endl;
        position++;
        temp_display = temp_display->next;
    }
}
void eleDuplicate()
{
    LINK temp_traverse = head;
    LINK temp_traverse_next;
    while (temp_traverse != NULL && temp_traverse->next != NULL)
    {
        temp_traverse_next = temp_traverse;
        while (temp_traverse_next->next != NULL)
        {
            if (temp_traverse->data == temp_traverse_next->next->data)
            {
                temp = temp_traverse_next->next;
                temp_traverse_next->next = temp_traverse_next->next->next;
                delete temp;
            }
            else
            {
                temp_traverse_next = temp_traverse_next->next;
            }
        }
        temp_traverse = temp_traverse->next;
    }
}