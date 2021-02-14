#include <iostream>
using namespace std;
#include "list"
#include "vector"
#include "string"

void displayList(list<int> &ls)
{
    list<int>::iterator itr;
    for (itr = ls.begin(); itr != ls.end(); itr++)
    {
        cout << "Element of List :" << *itr << endl;
    }
}

int main()
{
    list<int> ls;
    ls.push_back(10);
    list<int>::iterator start;
    start = ls.begin();
    ls.push_back(20);
    ls.push_back(30);
    ls.push_back(40);
    ls.push_back(50);
    cout << sizeof(ls) << endl;
    // it will assign no of first parameter to value of second paramenter
    // ls.assign(2, 10);

    // list cant store data lineary
    // cout << &ls.front() << endl;
    // cout << *(&ls.front() + 3);

    // ls.insert(start, 5, 5);

    // it will give the max size of memory
    cout << ls.max_size() << endl;

    list<int> lsS;
    lsS.push_back(1);
    lsS.push_back(2);
    lsS.push_back(3);

    // it will merge list at last after merging it will erase all second list elementss
    // ls.merge(lsS);

    lsS.push_back(1);
    lsS.push_back(2);
    lsS.push_back(3);

    ls.sort();

    //erasing the elements
    start = ls.begin();
    start++;
    start++;
    ls.erase(start);

    // memory allocation of the list element container which is completely different form list
    int *p;
    p = ls.get_allocator().allocate(5);
    for (int i = 0; i < 5; i++)
    {
        p[i] = (i + 1) * 100;
    }
    for (int i = 0; i < 5; i++)
    {
        cout << "Array element :" << p[i] << endl;
    }

    ls.get_allocator().deallocate(p, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << "array element is :" << p[i] << endl;
    }

    // it will move all list elements to second list
    lsS.splice(start, ls, lsS.begin());

    ls.remove(10);

    //getting size of the first list
    cout
        << "Size of an list :" << ls.size() << endl;
    cout << "Total size of list :" << sizeof(ls) << endl;

    cout << "Second list" << endl;
    displayList(lsS);
    cout << "First list" << endl;
    displayList(ls);
}
