class MyCircularQueue {
public:

    int* arr;
    int front;
    int rear;
    int size;

    MyCircularQueue(int k) {
        size = k;
        arr = new int[size];
        front = rear = -1;
    }
    
    bool enQueue(int value) {
        if( (rear + 1) % size == front ) {
            //cout << "Queue is Full";
            return false;
        }
        else if(front == -1) //first element to push
        {
          front = rear = 0;
            
        }
        else if(rear == size-1 && front != 0) {
            rear = 0; //to maintain cyclic nature
        }
        else
        {//normal flow
            rear++;
        }
        //push inside the queue
        arr[rear] = value;
        
        return true;
    }
    
    bool deQueue() {
      if(front == -1) {
            //cout << "Queue is Empty";
            return false;
        }
        
        if(front == rear) { //only one element
            front = -1;
            rear = -1;
        }
        else if(front == size-1) { //circular nature
            front = 0;
        }
        else
        {
            front++;
        }
        
        return true;
    }
    
    int Front() {
        if(front == -1 ) {
            return -1;
        }
        else
        {
            return arr[front];
        } 
    }
    
    int Rear() {
        if(rear == -1) {
            return -1;
        }
        else
        {
            return arr[rear];
        }
    }
    
    bool isEmpty() {
      if(front == -1) {
        return true;
        }
      else{
        return false;
        }
    }
    
    bool isFull() {
      if( (rear + 1) % size == front ) {
            return true;
        }
        else{
            return false;
        }
    }
};