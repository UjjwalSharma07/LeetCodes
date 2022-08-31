class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //max heap
        priority_queue<pair<int,pair<int,int>>>pq;
        
        for(int i=0; i<points.size(); i++){
            pq.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],{points[i][0],points[i][1]}});
            
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>>ans;
        vector<int>temp;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int x = top.second.first;
            int y = top.second.second;
            temp.push_back(x);
            temp.push_back(y);
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};