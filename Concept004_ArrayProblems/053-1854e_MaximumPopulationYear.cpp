// LC: 1854 e 

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        
        // prefix sum

        int n = size(logs);

        static const int MIN_YEAR = 1950;
        static const int MAX_YEAR = 2050;

        vector<int> years(MAX_YEAR - MIN_YEAR + 1);

        for(int i=0; i<n; i++){   

            int born = logs[i][0];
            int die = logs[i][1];

            years[born - MIN_YEAR]++;
            years[die - MIN_YEAR]--;
        }

        int ans = 0;
        for(int i=1; i<size(years); i++){

            years[i] += years[i-1];

            if(years[i] > years[ans]) {
              ans = i;
            }
        }
        return ans + MIN_YEAR;
    }
};