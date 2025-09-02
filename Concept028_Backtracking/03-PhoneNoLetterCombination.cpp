// LC: 17 m

class Solution {
private:
    void solve(string digit, string output, int index, vector<string>& ans, string mapping[] ) {
        
        //base case
        if(index >= digit.length()) {           //when TRAVERSE conmplete
            ans.push_back(output);
            return;
        }
                                                 // for eg. digit  = "36"
        int number = digit[index] - '0';        //charactewr of string into numerical value ascii of 0 is 48
        string value = mapping[number];          //first we got 3 means def
        
        for(int i=0; i<value.length(); i++) {      //here value.length =3(for def) 0-d,1-e,2-f
          output.push_back(value[i]);
          solve(digit, output, index+1, ans, mapping);
          output.pop_back();
        }
        
    }
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        if(digits.length()==0)
            return ans;
        string output;
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl","mno","pqrs","tuv","wxyz"};
        solve(digits, output, index, ans, mapping);
        return ans;
    }
};