// LC: 391 h

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        
        set<pair<int, int>> corners;            // to prevent overlap

        int minX = INT_MAX, minY = INT_MAX;
        int maxX = INT_MIN, maxY = INT_MIN;
        long totalArea = 0;

        for(auto& rect : rectangles){

          int x1=rect[0];     // bottom-left
          int y1=rect[1];

          int x2=rect[2];     // top-right
          int y2=rect[3];

          // boundry update
          minX = min(minX, x1);
          minY = min(minY, y1);
          maxX = max(maxX, x2);
          maxY = max(maxY, y2);

          // area of current rectangle
          totalArea += (long) (x2-x1)*(y2-y1);

          // current rectangle na 4 corners
          pair<int, int> p1 = {x1, y1}, p2 = {x1, y2};
          pair<int, int> p3 = {x2, y1}, p4 = {x2, y2};
          
          for(auto &p : {p1,p2,p3,p4}){

            // here,         corners.insert(p)     inserts p into corners
            // it returns    pair<iterator, bool> as answer
            // if p already present,   return false

            if(!corners.insert(p).second){    // false, already present
              corners.erase(p);
            }
          }
        }

        // Only 4 corners should remain
        if (corners.size() != 4 ||
            !corners.count({minX, minY}) ||
            !corners.count({minX, maxY}) ||
            !corners.count({maxX, minY}) ||
            !corners.count({maxX, maxY})) {
            return false;
        }

        long expectedArea = (long)(maxX - minX) * (maxY - minY);
        return totalArea == expectedArea;

    }
};