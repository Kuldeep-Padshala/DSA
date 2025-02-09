#include<iostream>
using namespace std;

class TwoStack {
    private:
        int* arr;
        int top1;
        int top2;
        int size;

    public:
        // Initialize TwoStack.
        TwoStack(int s) {
            size = s;
            arr = new int[s];
            top1 = -1;
            top2 = s;
        }

        // Push in stack 1.
        void push1(int num) {
            if (top2 - top1 > 1) {
                top1++;
                arr[top1] = num;
            } else {
                cout << "Stack Overflow" << endl;
            }
        }

        // Push in stack 2.
        void push2(int num) {
            if (top2 - top1 > 1) {
                top2--;
                arr[top2] = num;
            } else {
                cout << "Stack Overflow" << endl;
            }
        }

        // Pop from stack 1 and return popped element.
        int pop1() {
            if (top1 >= 0) {
                int ans = arr[top1];
                top1--;
                return ans;
            } else {
                cout << "Stack UnderFlow" << endl;
                return -1;
            }
        }

        // Pop from stack 2 and return popped element.
        int pop2() {
            if (top2 < size) {
                int ans = arr[top2];
                top2++;
                return ans;
            } else {
                cout << "Stack UnderFlow" << endl;
                return -1;
            }
        }

        void print() {
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main() {

    // object of TwoStack class
    TwoStack ts(10); // total size of the array is 10, and it contains both stacks

    ts.push1(1);
    ts.push1(2);
    ts.push1(3);
    ts.push1(4);
    ts.push1(5);
    ts.push1(6);

    ts.push2(101);
    ts.push2(102);
    ts.push2(103);
    ts.push2(104);
    ts.push2(105);      // STACK OverFlow
    ts.push2(106);      // STACK OverFlow

    cout << "Top of stack 1: " << ts.pop1() << endl;
    cout << "Top of stack 2: " << ts.pop2() << endl;

    ts.print();

    return 0;
}