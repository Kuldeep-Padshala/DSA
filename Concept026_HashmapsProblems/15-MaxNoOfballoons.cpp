// LC: 1189 e

class Solution {
public:
    int maxNumberOfBalloons(string text) {

        unordered_map<char, int> count;
        int ans;

        for(char &ch: text){
          count[ch]++;
        }
         
        return min(count['b'], min(count['a'], min(count['l']/2, min(count['o']/2, count['n']))));
    }
};