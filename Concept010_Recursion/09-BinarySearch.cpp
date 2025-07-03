#include<iostream>
using namespace std;

// bool binarySearch(int arr[], int s, int e , int key ) {         //Ordinary

//     //base case

//     //element not found
//     if(s>e)
//         return false;

//     int mid = s + (e-s)/2;

//     //element found
//     if(arr[mid] == key)
//         return true;

//     if(arr[mid] < key) {
//         return binarySearch(arr, mid+1, e, key);
//     }
//     else{
//         return binarySearch(arr, s, mid-1, key);
//     }
// }


bool binarySearch(int arr[], int size, int key ) {              //My style

    if(size==0)
        return false;

    int mid = (size)/2;

    //element found
    if(arr[mid] == key)
        return true;

    if(arr[mid] < key) {
        return binarySearch(arr + mid + 1, size-mid-1, key);
    }
    else{
             return binarySearch(arr, mid-1 , key);
    }
}



int main() {

    int arr[11] = {2,4,6,10,14,18,22,38,49,55,222};
    int size = 11;
    int key;
    cout<<"Enter element to find: ";
    cin>>key;
    // binarySearch(arr,0,size-1,key)
    
     if( binarySearch(arr,size,key) ){
          cout<<"Present";
     }
    
    else{
         cout<<"Not present";
        
    }
    return 0;
}