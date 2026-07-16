class MyCalendarTwo {
public:

    vector<pair<int,int>> booked;
    vector<pair<int,int>> overlaps;

    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        
        // Step 1: Check if causes triple booking
        for(auto &event : overlaps){
          if(max(startTime, event.first) < min(endTime, event.second)) {
            return false;  // triple booking
          }
        }

        // Step 2: Add new overlaps
        for(auto &event : booked) {
          if(max(startTime, event.first) < min(endTime, event.second)) {
            
            overlaps.push_back({
                max(startTime, event.first),
                min(endTime, event.second)
            });
          }
        }

        // Step 3: Add booking
        booked.push_back({startTime, endTime});

        return true;

    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */