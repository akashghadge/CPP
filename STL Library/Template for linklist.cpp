#include <iostream>
using namespace std;

// linked list class
template <class T>
class LinkList
{
protected:
    struct Node
    {
        T data;
        struct Node *next;
    };
    typedef struct Node *Link;
    Link head = NULL;
    Link temp = NULL;

public:
    LinkList()
    {
        cout << "Linked list is started" << endl;
    }
    void createList()
    {
        int terminate = 1;
        while (terminate)
        {
            Link newnode = (Link)malloc(sizeof(struct Node));
            cout << "Please enter data :" << endl;
            T data;
            cin >> data;
            newnode->data = data;
            newnode->next = NULL;
            if (this->head == NULL)
            {
                this->head = newnode;
                this->temp = newnode;
            }
            else
            {
                this->temp->next = newnode;
                this->temp = newnode;
            }
            cout << "Would you like to continue 0 for no" << endl;
            cin >> terminate;
        }
    }
    void display()
    {
        Link displayTemp = this->head;
        while (displayTemp != NULL)
        {
            cout << "The element is :" << displayTemp->data << endl;
            displayTemp = displayTemp->next;
        }
    }
};

int main()
{
    LinkList<string> l;
    l.createList();
    l.display();
}