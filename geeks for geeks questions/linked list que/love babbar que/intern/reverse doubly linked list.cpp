#include <iostream>
#include <stdio.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void create();
void display();
void rev();
struct node *head = NULL, *temp, *newnode;

typedef struct node *LINK;
LINK tail;
int choice;
int terminate = 1;
int main()
{
    create();
    display();
    rev();
    display();
}
void create()
{
    int end_create = 1;
    int i = 1;
    printf("CREATING THE NEW NODE IN THE LIST\n");
    while (end_create)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        // printf("PLEASE ENTER DATA IN THE LIST\n");
        // scanf("%d", &newnode->data);
        // printf("YOU ENTER THE :%d\n", newnode->data);
        newnode->data = i * 10;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
            tail = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
            tail = temp;
        }
        i++;
        if (i == 5)
        {
            end_create = 0;
        }
        // printf("WOULD YOU WANT TO CONTINUE ENTER 1 OR FOR END ENTER 0:\n");
        // scanf("%d", &end_create);
        // printf("YOU ENTERED:%d\n", end_create);
    }
}
void display()
{
    int count = 1;
    struct node *temp_display;
    temp_display = head;
    printf("WE ARE LOADING YOUR LIST.......\n");
    if (head == NULL)
    {
        printf("PLEASE CREATE THE LIST FIRST AND THEN SEE IT \n :)\n");
    }
    else
    {
        while (temp_display != NULL)
        {
            printf("AT THE %d POSITION DATA IS : %d \n", count, temp_display->data);
            temp_display = temp_display->next;
            count++;
            if (count >= 100)
            {
                break;
            }
        }
    }
}
void rev()
{
    LINK current;
    LINK nextnode;
    current = head;
    while (nextnode != NULL)
    {
        nextnode = current->next;
        current->next = current->prev;
        current->prev = nextnode;
        current = nextnode;
    }
    current = head;
    head = tail;
    tail = current;
}