#include<iostream> 
using namespace std;

// int power(int a,int b) {                   Normal recur.
    
//     if(b==0)                
//         return 1;
    
//     if (b==1)
//         return a;

//     return x*power(x,n-1);      
// }

int power(int a, int b) {          //   optimized            lec 34 recursion tree
    //base case
    if( b == 0 )
        return 1;

    if(b == 1)
        return a;

    //RECURSIVE CALL
    int ans = power(a, b/2);

    
    if(b%2 == 0)                        //if b is even
        return ans * ans;
        
    else                                //if b is odd
        return a * ans * ans;
}

int main() {

    int a,b;
    cin >> a >> b;
    cout << endl;
    int ans = power(a,b);

    cout << "Answer is " << ans << endl;

    return 0;
}