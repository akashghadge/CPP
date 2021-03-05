#include <iostream>
using namespace std;
struct INTERVAL
{
    int start, end;
};
void setInterVals(struct INTERVAL *interval, int intervalCount)
{
    int i;
    for (i = 0; i < intervalCount; i++)
    {
        cin >> interval[i].start;
        cin >> interval[i].end;
    }
}

void getIntervals(struct INTERVAL *interval, int intervalCount)
{
    int i;
    for (i = 0; i < intervalCount; i++)
    {
        cout << "start is :" << interval[i].start << endl;
        cout << "end is :" << interval[i].end << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int interValCount;
        cin >> interValCount;
        INTERVAL i[interValCount];
        setInterVals(i, interValCount);
        getIntervals(i, interValCount);
    }
}

void intervalSort()
{
    
}

void swapStructure(struct INTERVAL *i, struct INTERVAL *j)
{
    int temp1;
    int temp2;
    temp1 = i->start;
    temp2 = j->start;

    i->start = i->end;
    j->start = j->end;

    i->end = temp1;
    j->end = temp2;
}