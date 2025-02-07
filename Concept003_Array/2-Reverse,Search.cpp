#include<iostream>
using namespace std;

int reverse(int arr[],int n){            //Reverse Array
  
  int start = 0;
  int end = n-1;
  while(start<=end){
    swap(arr[start],arr[end]);              //Swap
    start++;
    end--;
  }
  return 0;
}

int printArray(int arr[],int n){
  
  for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
    }

    return 0;
}


bool search(int arr[],int n,int key){          //linear search
  
  for(int i=0;i<n;i++){
    if(arr[i]==key){
      return 1;
    }
    }
    return 0;
}

int main(){

    int n,key;
    cout<<"Enter size: ";
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++){
      cout<<"Enter arr["<<i<<"]: ";
        cin>>arr[i];
    }
    // cout<<"Enter element to find: ";
    // cin>>key;
    
    // if(search(arr,n,key)){
    //   cout<<"present";
    // }
    // else{
    //   cout<<"Not present";
    // }
    
    
    reverse(arr,n);
    printArray(arr,n);
    return 0;
}