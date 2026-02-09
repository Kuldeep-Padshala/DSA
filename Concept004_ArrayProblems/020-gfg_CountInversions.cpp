// gfg count inversions

class Solution {
    
    int merge(vector<int>&arr,int s,int mid,int e){
       
       int n1 = mid-s+1; 
       int n2 = e-mid; 
       int left[n1]; 
       int right[n2]; 
      
       for(int i=0;  i<n1; i++){
           left[i]=arr[s+i]; 
       }
       for(int i=0; i<n2; i++){
           right[i]=arr[mid+1+i]; 
       }
      
       int k=s; 
       int i=0; 
       int j=0; 
       int count=0; 
       
       while(i<n1 and j<n2){
           
           if(left[i]>right[j]){
               count+=(n1-i); 
               arr[k++]=right[j++]; 
           }
           else
           arr[k++]=left[i++]; 
       }
      
       while(i<n1){
           arr[k++]=left[i++]; 
       }
      
       while(j<n2){
           arr[k++]=right[j++]; 
       }
       return count; 
       
    }
    
    int mergeSort(vector<int>&arr,int s,int e){
           
           int count=0; 
           if(s<e){
               
               int mid=(s+e)/2; 
               count+=mergeSort(arr,s,mid); 
               count+=mergeSort(arr,mid+1,e); 
               count+=merge(arr,s,mid,e); 
           }
           return count; 
    }

  public:
    int inversionCount(vector<int> &arr) {
        
        // Code Here
        int n=arr.size();
        return mergeSort(arr,0,n-1);
        
        
    //     int n=arr.size(); 
    //     int count=0; 
    //     for(int i=0; i<n; i++){
    //         for(int j=i+1; j<n; j++){
    //           if(arr[i]>arr[j])
    //           count++; 
    //       }
    //   }
    //   return count; 
    }
}; 