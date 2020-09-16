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
void display(LINK);
LINK split();
int main()
{
    create_list1();
    display(head);
    LINK new_head1 = split();
    cout << "FIRST HALF" << endl;

    display(head);
    cout << "SECOND HALF" << endl;

    display(new_head1);
}
void create_list1()
{
    LINK newnode;
    int i;
    i = 6;
    int j = 1;
    while (i--)
    {
        newnode = (LINK) new (struct Node);
        newnode->data = j * 10;
        j++;
        newnode->next = head;
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

void display(LINK head)
{
    LINK temp_display;
    temp_display = head;
    while (temp_display->next != head)
    {
        cout << temp_display->data;
        cout << endl;
        temp_display = temp_display->next;
    }
    cout << temp_display->data << endl;
}
LINK split()
{
    LINK temp_head = head;
    int count = 1;
    temp_head = temp_head->next;
    while (temp_head->next != head)
    {
        count++;
        temp_head = temp_head->next;
    }

    temp_head = head;
    temp_head = temp_head->next;
    count = count / 2;
    count--;
    LINK new_head;
    while (count--)
    {
        temp_head = temp_head->next;
    }
    new_head = temp_head->next;
    temp_head->next = head;
    temp = new_head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = new_head;
    return new_head;
}