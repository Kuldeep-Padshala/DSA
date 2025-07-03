#include <iostream>
using namespace std;

bool search(int arr[], int size,int key) {

    //base case
    if(size == 0)
    return false;
    
    if(arr[0]==key){
        return true;
    }
    return search(arr+1,size-1,key);
}



int main(){
    
    int arr[10] = {2,4,9,8,9,3,2,22,40,1};
    int size = 10;
    
    int key;
    cin>>key;
    
    if(search(arr,size,key))
    cout<<"Present";
    
    else
    cout<<"Not present";

    return 0;
}