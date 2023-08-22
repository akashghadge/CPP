#include <iostream>
using namespace std;
template <class T1>
class Array
{
public:
    T1 *arr;
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
        arr = new T1[size];
        static int i_create;
        int terminate = 1;
        for (i_create; i_create < size && terminate; i_create++)
        {
            cout << "PLEASE ENTER THE NO FOR THE " << i_create << " POSITION:" << endl;
            // cin >> *(arr + i_create);
            cin >> arr[i_create];
            end_element++;
            cout << "WOULD YOU LIKE TO CONTINUE ENTER 1 FOR YES AND 0 FOR NO " << endl;
            cin >> terminate;
        }
    }
    void display_array()
    {
        int i;
        T1 *arr_temp = arr;
        for (i = 0; i < end_element; i++)
        {
            cout << "ARRAY HAVE THE " << *(arr_temp + i)
                 << " ON THE " << i
                 << " POSITION" << endl;
        }
    }
    void display_array_full()
    {
        int i;
        T1 *arr_temp = arr;
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
    void swap(T1 *a, T1 *b)
    {
        T1 temp;
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
int main()
{
    Array<int> a1;
    a1.create_array();
    a1.display_array();
}