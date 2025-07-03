#include <iostream>
using namespace std;


void say(string arr[],int n){            //123,12,1,0
    if(n==0)
    return ;
    
    int digit=n%10;
    n=n/10;
    say(arr,n);
    
    cout<<arr[digit]<<" ";
    
}



int main(){
    
    int n;
    cin>>n;
    string arr[]= {"zero","one","two","three","four","five","six","seven","eight","nine"};
    
    say(arr,n);

    return 0;
}