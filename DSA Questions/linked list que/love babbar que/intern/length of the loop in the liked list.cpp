#include <iostream>
using namespace std;
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
int detectLoop(LINK);
void createLoop();
int calculatLength(LINK);
int main()
{
    create_list1();
    createLoop();
    int result = detectLoop(head);
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
int detectLoop(LINK head)
{
    LINK slowTemp = head;
    LINK fastTemp = head;
    while (slowTemp && fastTemp && fastTemp->next)
    {
        slowTemp = slowTemp->next;
        fastTemp = fastTemp->next->next;
        if (slowTemp == fastTemp)
        {
            return calculatLength(slowTemp);
        }
    }
    return 0;
}
void createLoop()
{
    head->next->next->next = head->next;
}
int calculatLength(LINK stop)
{
    LINK temp = stop;
    int res = 1;
    while (temp->next != stop)
    {
        res++;
        temp = temp->next;
    }
    return res;
}