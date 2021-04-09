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

LINK exchangeFirstToLast(LINK head)
{
    // if list is empty
    if (head == NULL)
    {
        return NULL;
    }
    // if list have only one node
    else if (head->next == NULL)
    {
        return head;
    }
    else if (head->next->next == NULL)
    {
        // firstly save second node
        LINK temp = head->next;
        // make it circular by connecting it to head
        temp->next = head;
        // disconnet head from second element
        head->next = NULL;
        // return second element as head
        return temp;
    }

    else
    {
        LINK temp_tail = head;
        LINK temp_tailPre = NULL;
        while (temp_tail->next != NULL)
        {
            temp_tailPre = temp_tail;
            temp_tail = temp_tail->next;
        }
        // firstly set last node next to first node next
        temp_tail->next = head->next;
        // then make head to last node
        head->next = NULL;
        temp_tailPre->next = head;
        // make it global head
        head = temp_tail;
        // here passing head to function passes only copy of it not actual head so return it and update it in main function
        return head;
    }
}

int main()
{
    create_list1();
    display();
    head = exchangeFirstToLast(head);
    display();
}
void create_list1()
{
    LINK newnode;
    int i;
    i = 3;
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
        cout << " ";
        temp_display = temp_display->next;
    }
    cout << endl;
}