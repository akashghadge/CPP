#include <iostream>
using namespace std;
void creat_list();
void display_ll();
void append_ll(int);
void in_ll();
int len();
void reverse();
void del();
struct node
{
    int data;
    struct node *next;
};
typedef struct node *LINK;
LINK head_node = NULL;
LINK temp_node = NULL;
LINK temp_create = NULL;
int endpoint = 0;
int leng = 1;
int main()
{
    int choice;
    int terminate = 1;

    int error = 1;
    while (terminate)
    {
        printf("\n\nRUNNING PROGRAMME........\n");
        printf("!!!!!!!!!MENU!!!!!!!!!!\n");
        printf("1)CREATE A NEW LIST\n");
        printf("2)DISPLAY THE LIST\n");
        printf("3)INSERT ELEMENT IN THE LIST\n");
        printf("4)DELETE ELEMENT IN THE LIST\n");
        printf("5)REVERSE THE LIST\n");
        printf("6) EXIT.\n ");
        printf("PLEASE ENTER YOUR RESPONSE\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            creat_list();
            break;

        case 2:
            display_ll();

            break;
        case 3:
            if (head_node == NULL)
            {
                printf("PLEASE MAKE LIST FIRST!!!!!!!!!!");
            }
            else
            {
                in_ll();
            }

            break;
        case 4:
            del();
            printf("DELETE IS COMPLETED!!!!\n");
            break;
        case 5:
            printf("REVERSING THE LIST......\n");
            reverse();
            break;

        case 6:
            terminate = 0;

            break;

        default:
            printf("PLEASE ENTER THE VALIED INPUT ;)\n");

            break;
        }
        error++;
        if (error > 1000)
        {
            break;
        }
    }
}
void creat_list()
{
    int terminate = 1;
    LINK newnode;
    while (terminate)
    {
        newnode = (LINK) new (struct node);
        cout << "PLEASE ENTER THE DATA AT THE " << endpoint << " POSITION  : " << endl;
        cin >> newnode->data;
        newnode->next = NULL;
        endpoint++;
        if (head_node == NULL)
        {
            head_node = newnode;
            temp_create = newnode;
        }
        else
        {
            temp_create->next = newnode;
            temp_create = newnode;
        }
        cout << "WOULD YOU LIKE TO CONTINUE ENTER 1 FOR YES AND 0 FOR NO " << endl;
        cin >> terminate;
    }
}
void display_ll()
{
    LINK temp_display;
    temp_display = head_node;
    int i = 0;
    while (temp_display != NULL)
    {

        cout << "THE DATA AT THE " << i << "  POSITION IS THE " << temp_display->data << endl;
        temp_display = temp_display->next;
        i++;
    }
}
void append_ll(int element)
{
    do
    {
        LINK newnode;
        newnode = (LINK) new (struct node);
        newnode->data = element;
        newnode->next = NULL;
        endpoint++;
        if (head_node == NULL)
        {
            head_node = newnode;
            temp_create = newnode;
        }
        else
        {
            temp_create->next = newnode;
            temp_create = newnode;
        }
    } while (false);
}
void in_ll()
{
    // struct node *temp_insert = NULL;
    LINK temp_insert = NULL;
    temp_insert = (struct node *)malloc(sizeof(struct node));
    int choice_insert;
    int pos_insert;
    int j;
    cout << "WE ARE LOADING YOUR LIST......" << endl;
    cout << "AT WHICH POSITION YOU WANT TO INSERT DATA.." << endl;
    cout << "!!!!!!MENU OF INSERTION!!!!!!" << endl;
    cout << "1)INSERT DATA AT BEGINING:" << endl;
    cout << "2)INSERT DATA AT ENDING:" << endl;
    cout << "3)INSERT DATA AT SPECIFIC POSITION:" << endl;
    cout << "PLEASE ENTER YOUR OPERATION:" << endl;
    cin >> choice_insert;
    cout << choice_insert << " IS YOUR CHOICE" << endl;
    switch (choice_insert)
    {
    case 1:
        cout << "PLEASE ENTER THE DATA:" << endl;
        cin >> temp_insert->data;
        cout << "YOU ENTER " << temp_insert->data << endl;
        temp_insert->next = head_node;
        head_node = temp_insert;

        break;
    case 2:

        temp_insert = head_node;
        LINK newnode_insert;
        newnode_insert = (LINK)malloc(sizeof(struct node));
        cout << "PLEASE ENTER THE DATA:" << endl;
        cin >> newnode_insert->data;
        cout << "YOU ENTER : " << newnode_insert->data << endl;
        // printf("NEW NODE HAVE BASE ADRESS:%u\n ", newnode_insert->next);
        j = 1;

        while (temp_insert->next != NULL)
        {
            temp_insert = temp_insert->next;
        }
        newnode_insert->next = temp_insert->next;
        temp_insert->next = newnode_insert;

        break;
    case 3:
        cout << "PLEASE ENTER WHICH POSITION YOU LIKE TO ADD YOUR DATA:" << endl;
        cin >> pos_insert;
        cout << "YOU WANT TO INSERT THE DATA AT" << pos_insert << " POSITION" << endl;
        len();
        if (pos_insert > leng)
        {
            cout << "POSITION IS INVAILID!!!!!" << endl;
        }
        else
        {
            int i = 2;
            temp_insert = head_node;
            while (pos_insert > i)
            {
                temp_insert = temp_insert->next;
                i++;
            }
            LINK newnode_insert;
            newnode_insert = (LINK)malloc(sizeof(struct node));
            cout << "PLEASE ENTER THE DATA:" << endl;
            cin >> newnode_insert->data;
            cout << "YOU ENTER : " << newnode_insert->data << endl;
            newnode_insert->next = temp_insert->next;
            temp_insert->next = newnode_insert;
        }

        break;
    default:
        cout << "PLEASE ENTER THE VAILID INPUT :-0" << endl;

        break;
    }
}
int len()
{
    leng = 1;
    LINK temp_len;
    temp_len = head_node;
    while (temp_len != NULL)
    {
        temp_len = temp_len->next;
        leng++;
    }
    cout << "THE LIST HAVE THE " << leng << "LENGTH" << endl;
    return (leng);
}
void reverse()
{
    LINK temp_reverse;
    temp_reverse = (LINK)malloc(sizeof(struct node));
    LINK prevnode_reverse;
    prevnode_reverse = (LINK)malloc(sizeof(struct node));
    LINK nextnode_reverse;
    nextnode_reverse = (LINK)malloc(sizeof(struct node));
    nextnode_reverse = head_node;
    temp_reverse = head_node;
    prevnode_reverse = NULL;
    cout << "WE ARE REVERSING YOUR LIST......" << endl;

    while (nextnode_reverse != NULL)
    {
        nextnode_reverse = nextnode_reverse->next;
        temp_reverse->next = prevnode_reverse;
        prevnode_reverse = temp_reverse;
        temp_reverse = nextnode_reverse;
    }
    head_node = prevnode_reverse;
}
void del()
{
    int pos_delete;
    int choice_delete;
    LINK temp_delete;
    int count_choice2;
    temp_delete = (LINK)malloc(sizeof(struct node));
    LINK prevnode_delete;
    prevnode_delete = (LINK)malloc(sizeof(struct node));

    LINK nextnode_delete;
    nextnode_delete = (LINK)malloc(sizeof(struct node));
    cout << "WE ARE LOADING YOUR LIST......" << endl;
    cout << "AT WHICH POSITION YOU WANT TO INSERT DATA.." << endl;
    cout << "!!!!!!MENU OF DELETION!!!!!!" << endl;
    cout << "1)DELETE DATA AT BEGINING:" << endl;
    cout << "2)DELETE DATA AT ENDING:" << endl;
    cout << "3)DELETE DATA AT SPECIFIC POSITION:" << endl;
    cout << "PLEASE ENTER YOUR OPERATION:" << endl;
    cin >> choice_delete;
    cout << choice_delete << "IS YOUR CHOICE" << endl;
    switch (choice_delete)
    {
    case 1:
        cout << "WE ARE DELETING DATA FROM THE BEGINING......" << endl;

        temp_delete = head_node;
        head_node = head_node->next;
        free(temp_delete);

        break;

    case 2:
        cout << "WE ARE DELETING DATA FROM THE ENDING......" << endl;

        temp_delete = head_node;
        while (temp_delete->next != NULL)
        {
            prevnode_delete = temp_delete;
            temp_delete = temp_delete->next;
        }
        prevnode_delete->next = NULL;
        free(temp_delete);

        break;

    case 3:
        cout << "WE ARE DELETING DATA FROM THE ENDING....." << endl;
        temp_delete = head_node;
        prevnode_delete = head_node;
        cout << "PLEASE ENTER NODE NO WHICH WILL DELETE:" << endl;
        cin >> pos_delete;
        cout << "YOU ENTRED : " << pos_delete << endl;

        len();
        if (pos_delete > leng)
        {
            cout << "POSITION IS INVAILID!!!!!" << endl;
        }
        else
        {
            int i = 1;
            int j;
            while ((pos_delete - 1) > i)
            {
                temp_delete = temp_delete->next;
                i++;
            }
            nextnode_delete = temp_delete->next;
            temp_delete->next = nextnode_delete->next;
            free(nextnode_delete);
        }

        break;

    default:
        break;
    }
}
