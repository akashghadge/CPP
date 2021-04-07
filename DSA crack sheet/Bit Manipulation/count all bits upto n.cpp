#include <iostream>
using namespace std;

// getting msb on  -1
int msb(int n)
{
    int m = 0;
    int i = 1;
    while (n >= (1 << m))
    {
        m++;
    }
    return m - 1;
}
int countSetBits(int n)
{
    // Your logic here
    // brute force approch
    // int total=0;
    // for(int i=1;i<=n;i++){
    //     int temp=i;
    //     while(temp){
    //         temp=temp&(temp-1);
    //         total++;
    //     }
    // }
    // return total;

    // if number is zero then return 0
    if (n == 0)
    {
        return 0;
    }
    // get msb
    int m = msb(n);
    /*
            for bits upto 2^i can calculate easily cause these are complete set
            therefor for 2^0 n/2 bits present
                        2^1 n/4 bits preent 
                        there for basicaaly 
                        m*(2^(m-1)) present
        */
    int bitsUptoM = m * (1 << (m - 1));
    /*
            remaining are after 2^i bits
            i.e. n-2^m +1 (for that number also)
        */
    int bitsAfterM = n - (1 << m) + 1;
    // and rest is remaining nubers
    int rest = n - (1 << m);

    return bitsUptoM + bitsAfterM + countSetBits(rest);
}
int main()
{
}