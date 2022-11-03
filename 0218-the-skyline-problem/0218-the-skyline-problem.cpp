class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>>temp;
        
        for(auto ele:buildings){
            temp.push_back({ele[0],-ele[2]});
            temp.push_back({ele[1],ele[2]});
        }
        sort(begin(temp),end(temp));
        int prev=0,curr=0;
        
        multiset<int>m;
        vector<vector<int>>ans;
        m.insert(0);
        
        for(auto i:temp){
            if(i.second<0){
                m.insert(-i.second);
            }
            else{
                m.erase(m.find(i.second));
            }
            
            curr = *m.rbegin();
            if(curr != prev){
                ans.push_back({i.first,curr});
                prev = curr;
            }
        }
        return ans;
    }
};