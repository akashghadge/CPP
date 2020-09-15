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
int check();
int main()
{
    create_list1();
    display();
    int result;
    result = check();
    cout << result;
}
void create_list1()
{
    LINK newnode;
    int i;
    i = 10;
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

void display()
{
    LINK temp_display;
    temp_display = head;
    while (temp_display->next != head)
    {
        cout << temp_display->data;
        cout << endl;
        temp_display = temp_display->next;
    }
}
int check()
{
    LINK temp_traverse = head;
    while (temp_traverse->next != head)
    {
        if (temp_traverse->next == NULL)
        {
            return 0;
            break;
        }
        temp_traverse = temp_traverse->next;
    }
    return 1;
}