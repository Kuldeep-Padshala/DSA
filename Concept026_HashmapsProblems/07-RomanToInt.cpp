// LC: 13 e

class Solution {
public:
    int romanToInt(string s) {

        // Map of Roman numerals to their integer values
        unordered_map<char, int> map = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int ans = 0;

        // Traverse each character in the string
        for (int i = 0; i < s.size(); i++) {

            // If the current numeral is greater than the previous one,
            // we subtract twice the previous because we already added it once
            // Example: "IV" = 1 (I) + 5 (V) → need to subtract 2 * I to get 4
            if (i > 0 && map[s[i]] > map[s[i - 1]]) {
                ans += map[s[i]] - 2 * map[s[i - 1]];
            } else {
                // Otherwise, just add the current numeral's value
                ans += map[s[i]];
            }
        }
        return ans;
    }
};
