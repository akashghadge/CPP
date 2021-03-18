#include <iostream>
using namespace std;
#include "string"
#include "stack"
// declring structure
struct Node
{
    int data;
    struct Node *rightNode;
    struct Node *leftNode;
};
typedef struct Node *Link;
Link root;
Link createNewNode(int data)
{
    Link newnode = (Link)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->leftNode = NULL;
    newnode->rightNode = NULL;
    return newnode;
}
Link create_bt(string str, int *i, stack<char> &st)
{
    cout << " at position " << *i << " character is :" << *(str.begin() + *i) << endl;

    if (*(str.begin() + *i) == '(')
    {
        st.push('(');
        *i = *i + 1;
        cout << "The value of i is :" << *i << endl;

        create_bt(str, i, st);
    }
    else if (*(str.begin() + *i) == ')')
    {
        char cheack = st.top();
        st.push(')');
        if (cheack == '(')
        {
            return NULL;
        }
    }
    else
    {
        if (st.top() == NULL)
        {
            *i++;
            create_bt(str, i, st);
        }

        if (st.top() == '(')
        {
            Link newnode = createNewNode(int(*(str.begin() + *i)) - 48);
            *i = *i + 1;
            newnode->leftNode = create_bt(str, i, st);
            newnode->rightNode = create_bt(str, i, st);
            return newnode;
        }
    }
}

int preOrder(Link root)
{
    if (root == NULL)
    {
        return 0;
    }
    cout << root->data << " " << endl;
    preOrder(root->leftNode);
    preOrder(root->rightNode);
}

int main()
{
    string str;
    cout << "Please Enter String :  " << endl;
    cin >> str;
    int i = 0;
    stack<char> st;
    // int *m = &i;
    // cout << *(str.begin() + *m) << endl;

    Link root = create_bt(str, &i, st);
    preOrder(root);
}