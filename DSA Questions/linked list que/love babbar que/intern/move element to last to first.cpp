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
void display();
void swapFirstLast();
int main()
{
    create_list1();
    display();
    swapFirstLast();
    display();
}
void create_list1()
{
    LINK newnode;
    int i;
    i = 100;
    int j = 1;
    while (i--)
    {
        newnode = (LINK) new (struct Node);
        newnode->data = j * 10;
        j++;
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
void swapFirstLast()
{
    LINK temp_traverse = head;
    temp = head;
    int i = 1;
    while (temp_traverse->next != NULL)
    {
        temp_traverse = temp_traverse->next;
        if (i > 1)
        {
            temp = temp->next;
        }
        i++;
    }
    temp->next = head;
    temp_traverse->next = head->next;
    head->next = NULL;
    head = temp_traverse;
}