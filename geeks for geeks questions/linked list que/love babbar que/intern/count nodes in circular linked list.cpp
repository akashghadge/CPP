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
int countNode();
int main()
{
    create_list1();
    display();
    int result;
    result = countNode();
    cout << result;
}
void create_list1()
{
    LINK newnode;
    int i;
    i = 50;
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
    cout << temp_display->data << endl;
}
int countNode()
{
    int count = 1;
    LINK temp_display;
    temp_display = head;
    while (temp_display->next != head)
    {
        temp_display = temp_display->next;
        count++;
    }
    return count;
}