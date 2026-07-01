// LC: 2561 h Rearranging Fruits

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {

        // same, but used minHeap instead of extras

        long long cost = 0;
        unordered_map<int, int> count;

        // diff total of each fruits
        for(int fruit_price : basket1){
          count[fruit_price]++;
        }
        for(int fruit_price : basket2){
          count[fruit_price]--;
        }

        // kai side ketla fruits send karvana chhe e store karse
        priority_queue<int, vector<int>, greater<int>> pq;

        // vadharana fruits kya che ane ketla chhe e
        for(auto& [fruit, diff] : count) {

          if(diff % 2 != 0){         // jo koi fruit odd time hoi to can't be balanced
            return -1;               // bey baskets ma same fruits thaij no sake
          }

          for(int i=0; i < abs(diff)/2; i++){
            pq.push(fruit);
          }
        }

        int minFruit = min( *min_element(basket1.begin(), basket1.end()), *min_element(basket2.begin(), basket2.end()));

        int n = pq.size();
        int swaps = n/2;

        // logic: extras ma suppose 4 fruits chhe, to total 2 wap thase  [1,2,3,4] : (1<->3)  (4<->2)
        // cost always minimum mate ganse,
        // to pela n/2 minimum matej count karvana chhe

        for(int i=0; i<swaps; i++){
          
          int curr = pq.top();
          pq.pop();

          cost += min(curr, 2*minFruit);
        }
        
        // have minimum cost kidhu chhe, to badhai fruits direct swap karva karta min fruit sathe swap karie 
        // cost = 3 for (5<->3)   
        // cost = 2 for (5<->1)(1<->3)  or (1<->3)(5<->1)

        return cost;



        

        
        // long long cost = 0;
        // unordered_map<int, int> count;

        // // diff total of each fruits
        // for(int fruit_price : basket1){
        //   count[fruit_price]++;
        // }
        // for(int fruit_price : basket2){
        //   count[fruit_price]--;
        // }

        // // kai side ketla fruits send karvana chhe e store karse
        // vector<int> extras;

        // // vadharana fruits kya che ane ketla chhe e
        // for (auto& [fruit, diff] : count) {

        //     if (diff % 2 != 0){         // jo koi fruit odd time hoi to can't be balanced
        //       return -1;               // bey baskets ma same fruits thaij no sake
        //     }

        //     for (int i=0; i < abs(diff)/2; i++){
        //         extras.push_back(fruit);
        //     }
        // }

        // // cheapest first
        // sort(extras.begin(), extras.end());

        // int minFruit = min( *min_element(basket1.begin(), basket1.end()), *min_element(basket2.begin(), basket2.end()));

        // int n = extras.size();

        // // logic: extras ma suppose 4 fruits chhe, to total 2 wap thase  [1,2,3,4] : (1<->3)  (4<->2)
        // // cost always minimum mate ganse,
        // // to pela n/2 minimum matej count karvana chhe
        // for(int i=0; i<n/2; i++){
        //   cost += min(abs(extras[i]), 2*minFruit);
        // }
        
        // // have minimum cost kidhu chhe, to badhai fruits direct swap karva karta min fruit sathe swap karie 
        // // cost = 3 for (5<->3)   
        // // cost = 2 for (5<->1)(1<->3)  or (1<->3)(5<->1)

        // return cost;
    }
};