#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    struct node
    {
        int data;
        node *next;
    };
    struct node *reverse(struct node *head, int k)
    {
        // Complete this method
        if (!head)
            return NULL;
        node *current = head;
        node *next = NULL;
        node *prev = NULL;
        int count = 0;

        /*reverse first k nodes of the linked list */
        while (current != NULL && count < k)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }

        if (next)
            head->next = reverse(next, k);
        return prev;
    }
};
int main()
{
    FAST;

    return 0;
}