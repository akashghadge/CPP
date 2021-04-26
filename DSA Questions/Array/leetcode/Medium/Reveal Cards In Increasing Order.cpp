/*
In a deck of cards, every card has a unique integer.  You can order the deck in any order you want.

Initially, all the cards start face down (unrevealed) in one deck.

Now, you do the following steps repeatedly, until all cards are revealed:

Take the top card of the deck, reveal it, and take it out of the deck.
If there are still cards in the deck, put the next top card of the deck at the bottom of the deck.
If there are still unrevealed cards, go back to step 1.  Otherwise, stop.
Return an ordering of the deck that would reveal the cards in increasing order.

The first entry in the answer is considered to be the top of the deck.

 

Example 1:

Input: [17,13,11,2,3,5,7]
Output: [2,13,3,11,5,17,7]
Explanation: 
We get the deck in the order [17,13,11,2,3,5,7] (this order doesn't matter), and reorder it.
After reordering, the deck starts as [2,13,3,11,5,17,7], where 2 is the top of the deck.
We reveal 2, and move 13 to the bottom.  The deck is now [3,11,5,17,7,13].
We reveal 3, and move 11 to the bottom.  The deck is now [5,17,7,13,11].
We reveal 5, and move 17 to the bottom.  The deck is now [7,13,11,17].
We reveal 7, and move 13 to the bottom.  The deck is now [11,17,13].
We reveal 11, and move 17 to the bottom.  The deck is now [13,17].
We reveal 13, and move 17 to the bottom.  The deck is now [17].
We reveal 17.
Since all the cards revealed are in increasing order, the answer is correct.
 

Note:

1 <= A.length <= 1000
1 <= A[i] <= 10^6
A[i] != A[j] for all i != j

*/

#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <deque>
// basically here approch use deque and while loop
// sort vec
// push front last elem of vec
// then pop last elment and push it to first place
// also add next last elemnt to queue
// image here we do reverse engineering type process
void printDeq(deque<int> vec)
{
    for (int i : vec)
    {
        cout << i << " ";
    }
    cout << endl;
}
vector<int> deckRevealedIncreasing(vector<int> &deck)
{
    vector<int> res;
    sort(deck.begin(), deck.end());
    if (deck.size() <= 2)
    {
        return deck;
    }
    deque<int> d;
    int n = deck.size();
    int c = n - 1;
    printDeq(d);
    d.push_front(deck[c--]);
    d.push_front(deck[c]);
    printDeq(d);
    while (c--)
    {

        printDeq(d);
        int t = deck[c];
        int back = d.back();
        d.pop_back();
        d.push_front(back);
        d.push_front(t);
        printDeq(d);
    }
    for (int i : d)
    {
        res.push_back(i);
    }
    return res;
}

void printVector(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "At Index " << i << " Vector have : " << vec[i] << endl;
    }
    cout << endl;
}
int main()
{
    vector<int> sam = {17, 13, 11, 2, 3, 5, 7};
    sam = deckRevealedIncreasing(sam);
    printVector(sam);
}