#include<iostream>         //understanding XOR
using namespace std;

int main(){                  //uniq element

     int n;
    cout<<"Enter size: ";
  cin>>n;

    int arr[n],ans=0;
    for(int a=0;a<n;a++){
      cout<<"element "<< a+1 << ":";
      cin>>arr[a];
    }
    
    for(int i=0;i<n;i++){
      ans = ans^arr[i];                     // a^a = 0
    }                                       // 0^a = a
    cout<<"Ans is "<<ans<<endl;
    return 0;
}