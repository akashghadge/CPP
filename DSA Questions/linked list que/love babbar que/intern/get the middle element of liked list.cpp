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
int getMiddle();
int main()
{
    create_list1();
    display();
    int result;
    result = getMiddle();
    cout << result;
}
void create_list1()
{
    LINK newnode;
    int i;
    i = 11;
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
int getMiddle()
{
    LINK temp_traverse = head;
    int end = 1;
    int count = 1;
    while (temp_traverse != NULL)
    {
        end++;
        temp_traverse = temp_traverse->next;
    }
    int middle = end / 2;
    temp_traverse = head;
    while (middle != count)
    {
        temp_traverse = temp_traverse->next;
        count++;
    }
    return temp_traverse->data;
}