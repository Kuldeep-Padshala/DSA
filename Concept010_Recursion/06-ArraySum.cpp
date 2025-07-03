#include <iostream>
using namespace std;

int sum(int arr[], int size) {

    //base case
    if(size == 0)
    return 0;
    
    if(size == 1)
    return arr[0];
    
    return arr[0]+sum(arr+1,size-1);
   
}



int main(){
    
    int arr[5] = {2,4,9,8,9};
    int size = 5;
    
    int SUM = sum(arr,size);
    cout<<"Sum is "<<SUM;

    return 0;
}