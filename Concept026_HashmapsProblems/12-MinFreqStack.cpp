// LC: 895 h

class FreqStack {
public:

//                elem, freq
    unordered_map<int, int> freq;

//              freq,  same freq vadi values no stack
    unordered_map<int, stack<int>> group;
    int maxF = 0;

    FreqStack() {
    }
    
    void push(int val) {

        freq[val]++;
        int curr_freq = freq[val];

        group[curr_freq].push(val);

        if(curr_freq > maxF){
          maxF = curr_freq;
        }
        
    }
    
    int pop() {   // most frequent elem pop
        
        int val = group[maxF].top();    // maxFrequency na stack no top elem
        group[maxF].pop();

        freq[val]--;         // aa value mate ni frequency pan minus

        if(group[maxF].empty()){
          maxF--;               // jo maxFrequency no stack khali thai jai, to max freq minus karo.
        }

        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */