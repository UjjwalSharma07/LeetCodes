class Solution {
public:
    int MOD = 1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>>temp;
        for(int i=0; i<n; i++){
            temp.push_back({efficiency[i],speed[i]});
        }
        sort(temp.begin(),temp.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        long long sum = 0;
        long long ans = 0;
        for(int i=temp.size()-1; i>=0; i--){
            sum+= temp[i].second;
            pq.push(temp[i].second);
            if(k < pq.size()){
                sum-=pq.top();
                pq.pop();
            }
            ans = max(ans,sum*temp[i].first);
        }
    
        return ans%MOD;
    }
};