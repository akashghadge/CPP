#include <iostream>
#include <stdlib.h>
using namespace std;
class ARRAY
{
public:
    int *arr;
    int size;
    int end_element = 0;
    int flag_size = 1;
    ARRAY() {}
    ARRAY(int size_temp)
    {
        size = size_temp;
        flag_size = 0;
    }

    void create_array()
    {
        if (flag_size)
        {
            cout << "PLEASE ENTER THE SIZE OF THE ARRAY:" << endl;
            cin >> size;
        }
        arr = new int[size];
        static int i_create;
        int terminate = 1;
        for (i_create; i_create < size && terminate; i_create++)
        {
            cout << "PLEASE ENTER THE NO FOR THE " << i_create << " POSITION:" << endl;
            cin >> *(arr + i_create);
            end_element++;
            cout << "WOULD YOU LIKE TO CONTINUE ENTER 1 FOR YES AND 0 FOR NO " << endl;
            cin >> terminate;
        }
    }
    void display_array()
    {
        int i;
        int *arr_temp = arr;
        for (i = 0; i < end_element; i++)
        {
            cout << "ARRAY HAVE THE " << *(arr_temp + i)
                 << " ON THE " << i
                 << "POSITION" << endl;
        }
    }
    void display_array_full()
    {
        int i;
        int *arr_temp = arr;
        for (i = 0; i < size; i++)
        {
            cout << "ARRAY HAVE THE " << *(arr_temp + i)
                 << " ON THE " << i
                 << "POSITION" << endl;
        }
    }
    void reverse_array()
    {
        int mid = (end_element - 1) / 2;
        int i = 0;
        int end = end_element;
        for (i = 0; i <= mid; i++)
        {
            end--;
            swap(&arr[i], &arr[end]);
        }
    }
    void swap(int *a, int *b)
    {
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }
    void delete_element(int index)
    {
        if (index >= end_element)
        {
            cout << "PLEASE ENTER THE CORRECT INDEX.:)" << endl;
        }
        else if (index == size - 1)
        {
            delete (&arr[index]);
            end_element--;
        }
        else
        {
            int i;
            int index_next;
            index_next = index + 1;
            for (i = index; i < size; i++)
            {
                swap(&arr[i], &arr[index_next]);
                index_next++;
            }
            delete (&arr[i]);
            end_element--;
        }
    }
    void display_array_one(int index)
    {
        cout << "ARRAY HAVE THE " << arr[index]
             << " ON THE " << index
             << "POSITION" << endl;
    }
    void append_array(int element)
    {
        if (size > end_element)
        {
            arr[end_element] = element;
            end_element++;
        }
        else
        {
            cout << "THE STORAGE IS OVERFLOW :::::::" << endl;
        }
    }
};
class STACK : public ARRAY
{
public:
    void creat_stack(int size_stack)
    {
        size = size_stack;
        create_array();
    }
    void push_stack(int element)
    {
        append_array(element);
    }
    void pop_stack()
    {
        delete_element(end_element - 1);
    }
    int peek_stack()
    {
        cout << "THE TOP OF THE STACK IT HAVE THE ELEMENT: " << arr[end_element - 1] << endl;
        return arr[end_element - 1];
    }
};
class LL_SINGLE
{
public:
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
};
class QUEUE : public ARRAY
{
public:
    int front = -1;
    int rear = -1;
    QUEUE() {}
    void creat_queue(int size_stack)
    {
        size = size_stack;
        create_array();
    }
    void display_queue()
    {
        display_array();
    }
    void enque(int num)
    {
        append_array(num);
    }
    void deque()
    {
        delete_element(0);
    }
    void front_ele()
    {
        display_array_one(0);
    }
};
class QUEUE_CIRCULAR
{
public:
    int LENGTH;
    QUEUE_CIRCULAR() {}
    QUEUE_CIRCULAR(int size)
    {
        LENGTH = size;
    }
    int front = -1;
    int rear = -1;
    int *queue;
    void enque(int num)
    {
        int *queue = new int[LENGTH];
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
            queue[rear] = num;
        }
        else if (front == (rear + 1) % LENGTH)
        {
            printf("QUEUE IS FULL FIRSTLY DEQUE SOME ELEMENTS :)\n");
        }
        else
        {
            rear = (rear + 1) % LENGTH;
            queue[rear] = num;
        }
    }
    void deque()
    {
        if (front == -1 && rear == -1)
        {
            printf("THE QUEUE IS THE EMPTY SO WE COULD NOT DEQUE ANY ELEMENT :P\n");
        }
        else if (front == rear)
        {
            printf("DEQUE ELEMENT IS THE :%d\n", queue[front]);
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % LENGTH;
        }
    }
    int front_element()
    {
        printf("AT THE FRONT THERE %d ELEMENT.\n", queue[front]);
        return queue[front];
    }
    void display()
    {
        int i;
        int j = 1;
        i = front;
        while (i != rear)
        {
            printf("THE ELEMENT OF THE QUEUE %d POSITION IS THE %d. \n", j, queue[i]);
            i = (i + 1) % LENGTH;
            j++;
        }
        printf("THE ELEMENT OF THE QUEUE %d POSITION IS THE %d. \n", j, queue[i]);
    }
};
class DEQUE
{
    struct node
    {
        int data;
        struct node *next;
    };
    typedef struct node *LINK;
    LINK head_node = NULL;
    LINK temp_node = NULL;
    LINK tail_node = NULL;
    void creat()
    {
        int terminate;
        LINK newnode;
        while (terminate)
        {
            newnode = (LINK)malloc(sizeof(struct node));
            cout << "PLEASE ENTER THE DATA: " << endl;
            cin >> newnode->data;
            newnode->next = NULL;
            if (head_node == NULL)
            {
                head_node = newnode;
                temp_node = head_node;
                tail_node = head_node;
            }
            else
            {
                temp_node->next = newnode;
                temp_node = newnode;
                tail_node = newnode;
            }

            cout << "WOULD YOU LIKE TO CONTINUE ENTER 1 FOR YES AND 0 FOR NO " << endl;
            cin >> terminate;
        }
    }
    void display()
    {
        LINK temp_display;
        temp_display = head_node;
        int i;
        i = 0;
        while (temp_display != NULL)
        {
            cout << "THE DATA AT THE " << i << " INDEX IS THE " << temp_display->data << endl;
            i++;
            temp_display = temp_display->next;
        }
    }
    void enque_front(int num)
    {
        if (head_node == NULL)
        {
            creat();
        }
        else
        {
            LINK newnode;
            newnode = (LINK)malloc(sizeof(struct node));
            temp_node = head_node;
            newnode->data = num;
            newnode->next = head_node;
            head_node = newnode;
        }
    }
    void enque_rear(int num)
    {
        if (head_node == NULL)
        {
            creat();
        }
        else
        {
            LINK newnode;
            newnode = (LINK)malloc(sizeof(struct node));
            temp_node = head_node;
            newnode->data = num;
            newnode->next = NULL;
            tail_node->next = newnode;
        }
    }
    void dequeue_front()
    {
        if (head_node == NULL)
        {
            cout << "PLEASE CREATE THE LIST FIRST" << endl;
        }
        else
        {
            temp_node = head_node;
            head_node = head_node->next;
            free(temp_node);
        }
    }
    void dequeue_rear()
    {
        if (head_node == NULL)
        {
            cout << "PLEASE CREATE THE LIST FIRST" << endl;
        }
        else
        {
            int i = 0;
            temp_node = head_node;
            LINK temp_node_prv;
            temp_node_prv = temp_node;
            while (temp_node->next != NULL)
            {
                if (i > 0)
                {
                    temp_node_prv = temp_node_prv->next;
                }
                temp_node = temp_node->next;
                i++;
            }
            temp_node_prv->next = NULL;
            free(temp_node);
        }
    }
};
void bublesort(int *base, int size)
{
    int i;
    int temp;
    for (i = 0; i < size; i++)
    {
        int j = 0;
        for (j = 0; j < size; j++)
        {
            if (base[i] < base[j])
            {
                temp = base[i];
                base[i] = base[j];
                base[j] = temp;
            }
        }
    }
}
void insertion_sort(int *base, int size)
{
    int i = 1;
    int j;
    for (i = 1; i < size; i++)
    {
        int temp = base[i];
        j = i - 1;
        while (j >= 0 && base[j] > temp)
        {
            base[j + 1] = base[j];
            j--;
        }
        base[j + 1] = temp;
    }
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void selection_sort(int *base, int size)
{
    int j;
    int i = 0;
    int min;
    for (i = 0; i < size - 1; i++)
    {
        min = i;

        for (j = i + 1; j < size; j++)
        {
            if (base[j] < base[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(&base[min], &base[i]);
        }
    }
}
bool linear_serch(int *base, int size, int target)
{
    int i;
    bool result;
    for (i = 0; i < size; i++)
    {
        if (base[i] == target)
        {
            cout << "THE ARRAY HAVE THE " << target << " AT THE " << i << " POSITION " << endl;
            result = true;
            return result;
        }
    }
}
void swap_string(string *a, string *b)
{
    string temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
struct EXAM
{
    string name;
    int marks;
};
void string_sorting(struct EXAM *e, int size) // changes shold made befor usinng the alogrithm

{

    int i;
    for (i = 0; i < size; i++)
    {
        int j;
        for (j = 0; j < size; j++)
        {
            if (&e[i].name < &e[j].name)
            {
                swap_string(&e[i].name, &e[j].name);
                swap(&e[i].marks, &e[j].marks);
            }
        }
    }
}
class ARRAY_CHAR
{

public:
    char *arr;
    int size;
    int end_element = 0;
    int flag_size = 1;
    int flag_creat = 1;
    ARRAY_CHAR() {}
    ARRAY_CHAR(int size_temp)
    {
        size = size_temp;
        flag_size = 0;
    }

    void create_array()
    {
        if (flag_size)
        {
            cout << "PLEASE ENTER THE SIZE OF THE ARRAY:" << endl;
            cin >> size;
        }
        arr = new char[size];
        if (flag_creat)
        {
            static int i_create;
            int terminate = 1;
            for (i_create; i_create < size && terminate; i_create++)
            {
                cout << "PLEASE ENTER THE NO FOR THE " << i_create << " POSITION:" << endl;
                cin >> *(arr + i_create);
                end_element++;
                cout << "WOULD YOU LIKE TO CONTINUE ENTER 1 FOR YES AND 0 FOR NO " << endl;
                cin >> terminate;
            }
        }
    }
    void display_array()
    {
        int i;
        char *arr_temp = arr;
        for (i = 0; i < end_element; i++)
        {
            cout << "ARRAY HAVE THE " << *(arr_temp + i)
                 << " ON THE " << i
                 << "POSITION" << endl;
        }
    }
    void display_array_full()
    {
        int i;
        char *arr_temp = arr;
        for (i = 0; i < size; i++)
        {
            cout << "ARRAY HAVE THE " << *(arr_temp + i)
                 << " ON THE " << i
                 << "POSITION" << endl;
        }
    }
    void reverse_array()
    {
        int mid = (end_element - 1) / 2;
        int i = 0;
        int end = end_element;
        for (i = 0; i <= mid; i++)
        {
            end--;
            swap(&arr[i], &arr[end]);
        }
    }
    void swap(char *a, char *b)
    {
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }
    void delete_element(int index)
    {
        if (index >= end_element)
        {
            cout << "PLEASE ENTER THE CORRECT INDEX.:)" << endl;
        }
        else if (index == size - 1)
        {
            cout << arr[index];
            delete (&arr[index]);
            end_element--;
        }
        else
        {
            int i;
            int index_next;
            index_next = index + 1;
            for (i = index; i < size; i++)
            {
                swap(&arr[i], &arr[index_next]);
                index_next++;
            }
            cout << arr[i];
            delete (&arr[i]);
            end_element--;
        }
    }
    void display_array_one(int index)
    {
        cout << "ARRAY HAVE THE " << arr[index]
             << " ON THE " << index
             << "POSITION" << endl;
    }
    void append_array(int element)
    {
        if (size > end_element)
        {
            arr[end_element] = element;
            end_element++;
        }
        else
        {
            cout << "THE STORAGE IS OVERFLOW :::::::" << endl;
        }
    }
};
class STACK_CHAR : public ARRAY_CHAR
{

public:
    STACK_CHAR()
    {
        flag_creat = 0;
    }
    void creat_stack(int size_stack)
    {
        size = size_stack;
        flag_size = 0;
        create_array();
    }
    void push_stack(int element)
    {
        append_array(element);
    }
    void pop_stack()
    {
        delete_element(end_element - 1);
    }
    void pop_stack_not_cout()
    {
        delete (&arr[end_element - 1]);
        end_element--;
    }
    int peek_stack()
    {
        // cout << "THE TOP OF THE STACK IT HAVE THE ELEMENT: " << arr[end_element - 1] << endl;
        return arr[end_element - 1];
    }
    void pop_stack_all()
    {
        while (end_element != 0)
        {
            pop_stack();
        }
    }
    void pop_stack_all_not_cout()
    {
        while (end_element != 0)
        {
            pop_stack_not_cout();
        }
    }
};
int digits(int num, int *digit)
{
    int i = 0;
    while (num)
    {
        digit[i] = num % 10;
        num = num / 10;
        i++;
    }
    return i;
}
int power(long int base, int expo)
{
    int i;
    long int temp_base;
    temp_base = base;
    if (expo == 0)
    {
        return 1;
    }
    else
    {

        for (i = 1; i <= expo; i++)
        {
            base = base * temp_base;
            if (i == 1)
            {
                base = temp_base;
            }
        }
        return base;
    }
}
int retrive_number(int *base, int size)
{
    int i = 0;
    long int multi;
    int num = 0;

    while (i <= size)
    {
        multi = power(10, i);
        num = num + (base[i] * multi);
        i++;
    }
    return num;
}
void convertBinaryToDecimal(int num, int *result)
{
    int i;
    // int num_temp = num;
    i = 0;
    while (num)
    {
        result[i] = num % 2;
        num = num / 2;
        i++;
    }
}
void isDuplicate(int *arr, int size)
{
    int i = 0;
    int j = i + 1;
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                cout << arr[i] << " AT THE " << i << " POSITION AND THE " << arr[j] << " AT THE " << j << " POSITION ARE SAME ." << endl;
            }
        }
    }
}
void reverse_array(int *arr, int size)
{
    int middle = size / 2;
    int i;
    int j;
    j = size - 1;
    for (i = 0; i < middle; i++)
    {
        swap(arr[i], arr[j]);
        j--;
    }
}