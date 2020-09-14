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
void reverseTheGroup(int, int);
int main()
{
    create_list();
    reverseTheGroup(1, 10);
    display();
}
void create_list()
{
    LINK newnode;
    // int terminate = 1;
    int endpoint = 0;
    // while (terminate)
    // {
    //     newnode = (LINK) new (struct node);
    //     cout << "PLEASE ENTER THE DATA IN THE LIST:" << endl;
    //     cin >> newnode->data;
    //     newnode->next = NULL;
    //     endpoint++;
    //     if (head == NULL)
    //     {
    //         head = newnode;
    //         temp = newnode;
    //     }
    //     else
    //     {
    //         temp->next = newnode;
    //         temp = newnode;
    //     }

    //     cout << "ARE YOU WANT TO CONTINUE:" << endl;
    //     cin >> terminate;
    // }
    //scripted loog
    int i;
    i = 10;
    int j = 1;
    while (i--)
    {
        newnode = (LINK) new (struct node);
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
void reverseTheGroup(int start, int endpoint)
{
    int currentpoint = 1;
    LINK current = head;
    if (start == 1)
    {
        LINK prev = head;
        LINK current = head;
        LINK nextnode = current->next;
        LINK stop_point = current;
        current = nextnode;
        while (currentpoint != endpoint)
        {
            nextnode = nextnode->next;
            current->next = prev;
            prev = current;
            current = nextnode;
            currentpoint++;
        }
        stop_point->next = current;
        head = prev;
    }
    else
    {

        while (currentpoint != start - 1)
        {
            current = current->next;
            currentpoint++;
        }
        // cout << current->data << endl;

        LINK prev = current;
        LINK nextnode = current->next;
        LINK stop_point = current;
        current = nextnode;
        // cout << prev->data << endl;
        // nextnode = nextnode->next;
        // prev = current;
        // current = nextnode;
        while (currentpoint != endpoint)
        {
            nextnode = nextnode->next;
            current->next = prev;
            prev = current;
            current = nextnode;
            currentpoint++;
        }

        // current->next = stop_point;
        stop_point->next->next = current;
        stop_point->next = prev;
    }
}