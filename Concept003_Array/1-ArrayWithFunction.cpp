#include<iostream>
using namespace std;

int array(int arr[], int s){           //Array with functions  (base address)
  
  for(int i=0;i<s;i++){
    arr[i]+=1;
  }
  return 0;
}


int main(){

    int s;
    cout<<"Enter size: ";
    cin>>s;
    
    int arr[s];
    for(int i=0;i<s;i++){
      cout<<"Enter arr["<<i<<"]: ";
      cin>>arr[i];
    }
    
    array(arr,s);
    
    for(int j=0;j<s;j++){
    cout<<arr[j]<<" ";
  }
  
  int size = sizeof(arr)/sizeof(int);            //sizeof
  cout<<endl<<"Size is "<<size;
  
//   int maxi = max(arr[0],arr[4]);          problem
//   cout<<endl<<"Max is "<<maxi;

    return 0;
}
