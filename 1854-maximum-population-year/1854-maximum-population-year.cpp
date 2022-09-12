class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int>v(2051,0);
        
        for(auto i:logs){
            v[i[0]]+=1;
            v[i[1]]-=1;
        }
        
        for(int i=1; i<2051;i++){
            v[i]+=v[i-1];
        }
        int maxi = INT_MIN;
        int ans = 0;
        
        for(int i=0; i<2051; i++){
            if(v[i]>maxi){
                maxi = v[i];
                ans = i;
            }
        }
        return ans;
    }
};