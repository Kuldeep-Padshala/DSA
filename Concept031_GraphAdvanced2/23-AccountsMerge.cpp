// LC: 721 m 

class DisjointSet {
public:

    vector<int> parent, size;
    DisjointSet(int n) {               // Constructor

        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;  // initially, every node is its own parent
            size[i] = 1;
        }
    }

    int findUltParent(int node) {

        if(node == parent[node])   return node;

        // path compression
        return parent[node] = findUltParent(parent[node]);
    }

    void unionBySize(int u, int v) {

        int ulp_u = findUltParent(u);
        int ulp_v = findUltParent(v);
        if (ulp_u == ulp_v) return;                      // already in same set

        if(size[ulp_u] < size[ulp_v]){   // Updating parents depanding on size of its parents, smaller attached to larger
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n = accounts.size();
        DisjointSet ds(n);

        //            mail, index
        unordered_map<string,int> idxOfEmail;

        // Step 1: Union accounts by shared emails
        for(int i=0; i<n; i++){
          for(int j=1; j<accounts[i].size(); j++){
            
            string curr_email = accounts[i][j];

            if(idxOfEmail.find(curr_email) == idxOfEmail.end()) {      // if this email is already present with other idx
              idxOfEmail[curr_email] = i;                              // point it to the same idx
            } 
            else{
              ds.unionBySize(i, idxOfEmail[curr_email]);
            }            
          }
        }

        // Step 2: Collect emails for each ULTIMATE parent
        unordered_map<int, vector<string>> merged;

        for(auto &idx : idxOfEmail) {
          string curr_email = idx.first;
          int mail_at = idx.second;
          int parent = ds.findUltParent(mail_at);
          merged[parent].push_back(curr_email);
        }

        // Step 3: Prepare ans
        vector<vector<string>> ans;
        for(auto &p : merged) {

          int par_idx = p.first;
          vector<string> emails = p.second;
          sort(emails.begin(), emails.end());
          emails.insert(emails.begin(), accounts[par_idx][0]); // add name at front
          ans.push_back(emails);
        }

        return ans;
    }
};