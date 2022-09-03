class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
    int solve(int n,vector<vector<int>>& envelopes){
        if(n==0){
            return 0;
        }
        vector<int>ans;

        ans.push_back(envelopes[0][1]);
        for(int i=1; i<envelopes.size(); i++){
            if(envelopes[i][1]>ans.back()){
                ans.push_back(envelopes[i][1]);
            }
            else{
                int index = lower_bound(ans.begin(),ans.end(),envelopes[i][1])-ans.begin();
                ans[index] = envelopes[i][1];
            }
        }
        return ans.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //  STEP:1 first sort evelopes by width if u found same width element then sort by dicressing height
        //  STEP:2 Now apply longest incressing subsequence method dp+binarySearch
        sort(envelopes.begin(),envelopes.end(),cmp);
        int n= envelopes.size();
        return solve(n,envelopes);
    }
};