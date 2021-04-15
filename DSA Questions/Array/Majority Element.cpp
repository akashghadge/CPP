#include <iostream>
using namespace std;

int majority(int *arr,int size){
    int n=size/2;
    // there are n no of approch there first is you can count each numbers count to get majority
    // time o(n^2)
    // sort it and adjusant are majority elements
    // time o(nlogn)
    // use hash map for counter
    // time and space o(n);
    int count=0;
    int currentNumber=arr[0];
    for(int i=0;i<size;i++){
        if(currentNumber==arr[i]){
            count++;
        }
        else if(count<=0){
            currentNumber=arr[i];
            count=1;
        }
        else{
            count--;
        }
        cout<<currentNumber<<endl;
        
    }
    int finalCount=0;
    for(int i=0;i<size;i++){
        if(currentNumber==arr[i]){
            finalCount++;
        }
    }
    if(finalCount>n){
        return currentNumber;
    }
    else{
        return -1;
    }
    
}
int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int res=majority(arr,size);
    cout<<"Majority :  "<<res<<endl;
    
}