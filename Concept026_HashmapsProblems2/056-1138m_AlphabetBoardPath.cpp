// LC: 1138 m

class Solution {
public:
    string alphabetBoardPath(string target) {

        // int n = target.size();  
        // unordered_map<char, pair<int, int>> mp;

        // for(char ch='a'; ch<='z'; ch++){
        //   int i = ch - 'a';

        //   mp[ch] = {i/5, i%5};
        // }

        // int currX = 0;
        // int currY = 0;
        // string path = "";

        // for(char ch: target){

        //   int x = mp[ch].first;
        //   int y = mp[ch].second;

        //   if(currX == x && currY == y){
        //     path += "!";
        //     continue;
        //   }
        //   if(currY > y){
        //     path += string((currY - y), 'L');
        //   }
        //   if(currX < x){
        //     path += string((x - currX), 'D');
        //   }
        //   if(currX > x){
        //     path += string((currX - x), 'U');
        //   }
        //   if(currY < y){
        //     path += string((y - currY), 'R');
        //   }

        //   currX = x;
        //   currY = y;
        //   path += "!";
        // }

        // return path;
        
        string ans;
        int x = 0, y = 0;
        for (auto ch : target){
          
          int x1 = (ch - 'a') % 5 , y1 = (ch - 'a') / 5;
          ans +=string(max(0, y - y1), 'U') 
              + string(max(0, x - x1), 'L') 
              + string(max(0, y1 - y), 'D') 
              + string(max(0, x1 - x), 'R') 
              + "!";

          x = x1, y = y1;
        }
        return ans;
    }
};