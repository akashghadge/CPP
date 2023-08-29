/*
Diffrent Appraoches are their like
priority queue, heap, sort and find
but binary search is best among them

Note:-
********
https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/solutions/85182/my-solution-using-binary-search-in-c/comments/89974

First, consider the
case. In this case, there're less than () elements that are no greater than mid, which means there could be elements that are all smaller than, or there could be at least one element among those count elements that is equal to If it's the former case, it means is NOT in the matrix[][]; if it's the latter case, it means can't be the answer because there's at least one element that is equal to and that element is greater than less than elements in matrix[][], so the smallest possible answer must be greater than That's why we have
Then, we consider the
case. In this case, at least elements are no greater than So must be the upper bound of the answer. Now the question is, should we include see why we would set as our possible answer? Yes. We'll
Similarly, if there're no element in matrix[][] that is equal to it means is not in matrix[][] and is greater than elements in matrix[][]. So the answer must be smaller than In this case. If there's at least one element equal to, then we consider two cases: 1. In this case, could still be the answer because if there are more than one element that is equal to may be the answer. For example, And there're two elements that are equal to Then would be the 8 smallest and 9th smallest, so is the answer. 2. In this case, may also be the answer. For example, And there's one element equal to Then is greater than elements, so is the final answer.
In conclusion, when
the answer may be equal to or less than Combining these two statements, we so we should set keep narrowing the range towards the correct answer until

*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
}