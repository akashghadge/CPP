#include <iostream>
using namespace std;
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
int endpoint = 0;
struct node
{
    int data;
    struct node *next;
};
typedef struct node *LINK;
LINK head = NULL;
LINK temp = NULL;
LINK newnode;
struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node *LINK1;
LINK1 head_node = NULL;
LINK1 temp_node = NULL;
void create_list1();
void push(int);
void display();
void pop();
int peek();
void display_list();
int compare();
int main()
{
    create_list1();
    display_list();
    int result;
    result = compare();
    cout << result;
}
void create_list1()
{
    LINK1 newnode;
    int terminate = 1;
    endpoint = 0;
    while (terminate)
    {
        newnode = (LINK1) new (struct Node);
        cout << "PLEASE ENTER THE DATA IN THE LIST:" << endl;
        cin >> newnode->data;
        newnode->next = NULL;
        endpoint++;
        if (head_node == NULL)
        {
            head_node = newnode;
            temp_node = newnode;
        }
        else
        {
            temp_node->next = newnode;
            temp_node = newnode;
        }

        cout << "ARE YOU WANT TO CONTINUE:" << endl;
        cin >> terminate;
    }
}
void push(int target)
{
    newnode = (LINK)malloc(sizeof(struct node));
    newnode->data = target;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        temp = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}
void display()
{
    int i = 0;
    LINK temp_display;
    if (head == NULL)
    {
        printf("STACK IS EMPTY ....\n");
    }
    else
    {
        temp_display = head;
        while (temp_display != NULL)
        {
            printf("THE DATA AT THE %d POSITION IS :%d\n", i, temp_display->data);
            temp_display = temp_display->next;
            i++;
            if (i > 10)
            {
                break;
            }
        }
    }
}
void pop()
{
    LINK temp_pop;
    temp_pop = (LINK)malloc(sizeof(struct node));
    printf("WE ARE POPING THE ELEMENT ......\n");
    if (head == NULL)
    {
        printf("UNDER FLOW CONDITION.....\n");
    }
    else
    {
        temp_pop = head;
        head = head->next;
        printf("WE POP THE %d\n", temp_pop->data);
    }
}
int peek()
{
    LINK temp_peek;
    temp_peek = (LINK)malloc(sizeof(struct node));

    temp_peek = head;
    return temp_peek->data;
}
void display_list()
{
    LINK1 temp_display;
    temp_display = head_node;
    while (temp_display != NULL)
    {
        cout << temp_display->data;
        cout << "" << endl;

        temp_display = temp_display->next;
    }
}
int compare()
{
    int i;
    LINK1 temp_assigne;
    temp_assigne = head_node;
    for (i = 1; i <= endpoint; i++)
    {
        // cout << temp_assigne->data;
        push(temp_assigne->data);
        temp_assigne = temp_assigne->next;
        display();
    }
    int top;
    temp_assigne = head_node;
    int count1 = 0;
    int count2 = 0;
    // LINK temp_stack = head;
    while (temp_assigne != NULL)
    {
        count1++;
        top = peek();
        if (top == temp_assigne->data)
        {
            count2++;
        }
        pop();
        temp_assigne = temp_assigne->next;
    }
    if (count1 == count2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}