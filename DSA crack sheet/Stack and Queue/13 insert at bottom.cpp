/*
static void insert_at_bottom(char x){

    if(st.isEmpty())
        st.push(x);

    else{
         All items are held in Function Call Stack until we
           reach end of the stack. When the stack becomes
           empty, the st.size() becomes 0, the
           above if part is executed and the item is inserted
           at the bottom 

        char a = st.peek();
        st.pop();
        insert_at_bottom(x);

        //push all the items held in Function Call Stack
        //once the item is inserted at the bottom
        st.push(a);
    }
}
In the above code, I have a question about this step:

if(st.isEmpty())
        st.push(x);
Don't we require a return statement after st.push(x)?

I mean that in recursion stack when that condition is satisfied i.e. when the stack is empty, it would push x into the stack, but how would it return to the previous call without the return statement?

java
recursion
return
Share
Improve this question
Follow
edited Jul 16 '17 at 16:35

melpomene
79.8k66 gold badges7070 silver badges128128 bronze badges
asked Jul 16 '17 at 15:47

vvv
17311 gold badge22 silver badges1313 bronze badges
1
What language is this? – melpomene Jul 16 '17 at 15:55
Java language it is – vvv Jul 16 '17 at 16:20
the push is the final statement as only the else part of the if statement follows. So it return at the call site. – Joop Eggen Jul 16 '17 at 18:38 
In this question you are not required to add a return because the flow of code will either execute the if block or else block in each recursion call. – Rahul May 24 at 20:33
Add a comment
9 Answers

4

The insert_at_bottom is a void function. This type of function does not need a return statement. So, as soon as it executes:

if(st.isEmpty())
  st.push(x);
It does not have anything to return, does not have anything else to execute and stops its recursion. To illustrate, the execution order would be something like this.


*/