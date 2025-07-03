#include<iostream> 
using namespace std;

int fact(int n) {
    
    if(n==0)                 //base case, it must have return statement otherwise segmentation prob.
        return 1;

    return n*fact(n-1);      // Recursive relation
                             // RR last,tail recursion, 
                             // RR middle process last, head recursion 
}

int main() {

    int n;
    cin >> n;

    int ans = fact(n);

    cout << ans << endl;

    return 0;
}