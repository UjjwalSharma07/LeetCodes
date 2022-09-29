class compare{
    public:
    bool operator()(pair<int,int>&a, pair<int,int>& b){
        if(a.second == b.second){
            return a.first>b.first;
        }
        return a.second>b.second;
    }
};
class Solution {
public:

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare>pq;
        for(auto i:arr){
            pq.push({i,abs(i-x)});
        }
        vector<int>ans;
        while(k--){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};