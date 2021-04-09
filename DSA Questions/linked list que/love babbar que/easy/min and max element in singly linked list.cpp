#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
void MinMax_element(int a);
void create_list();
typedef struct Node *LINK;
LINK head = NULL;
LINK temp = NULL;
int main()
{
    create_list();
    MinMax_element(1);
    return 0;
}
void create_list()
{
    LINK newnode;
    int terminate = 1;
    while (terminate)
    {
        newnode = (LINK) new (struct Node);
        cout << "PLEASE ENTER THE DATA IN THE LIST:" << endl;
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

        cout << "ARE YOU WANT TO CONTINUE:" << endl;
        cin >> terminate;
    }
}
void MinMax_element(int a)
{
    LINK temp_traverse = head;
    LINK storage = head;
    // int flag = 1;
    if (a)
    {
        while (temp_traverse != NULL)
        {
            if (temp_traverse->data > storage->data)
            {
                storage = temp_traverse;
            }

            temp_traverse = temp_traverse->next;
        }
    }
    else
    {
        while (temp_traverse!= NULL)
        {
            if (temp_traverse->data < storage->data)
            {
                storage = temp_traverse;
            }

            temp_traverse = temp_traverse->next;
        }
    }
    cout << "THE ELEMENT IS THE :" << storage->data << endl;
}