#include <iostream>
using namespace std;
int main()
{

    int *ptr = new (int[2]);

    *(ptr) = 1;
    *(ptr + 1) = 2;
    // (ptr) = 2;   //you allocate the adress you could not change it
    cout << "THE BASE ADRESS STORE IN THE PTR IS THE" << ptr << endl;
    cout << "THE ADRESS OF THE PTR IS THE" << &ptr << endl;
    cout << "THE BASE ADRESS STORE IN THE PTR IS THE" << *(&ptr) << endl;
    cout << "THE VALUE AT THE PTR IS THE" << *(ptr) << endl;
    cout << "THE BASE ADRESS STORE IN THE PTR NEXT IS THE" << (ptr + 1) << endl;
    cout << "THE VALUE NEXT TO THE PTR IS THE" << *(ptr + 1) << endl;

    // pointer arethmatics//
    cout << "THE VALUE OF THE NEXT POSITION ADDRESS OF THE POINTER." << ptr + 1 << endl; //for int it will alogate the 4 bytes
    cout << "THE VALUE OF THE PREV POSITION ADRESS OF THE POINTER." << ptr - 1 << endl;

    cout << "THE DELETE KEYWORD " << endl;

    //DELETE KEYWORDS IN THE CPP

    delete (ptr);
    cout << "THE VALUE AT THE PTR IS THE" << *ptr << endl;            //it will throw the garbage value cause you delete the privios one
    cout << "THE VALUE NEXT TO THE PTR IS THE" << *(ptr + 1) << endl; //because you destroy the base you could not acces onwords elements

    delete (&ptr + 1);
    cout << "THE VALUE AT THE PTR IS THE" << *(ptr) << endl;
    cout << "THE VALUE NEXT TO THE PTR IS THE" << *(ptr + 1) << endl;
}