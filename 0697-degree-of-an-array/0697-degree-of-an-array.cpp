class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int>occur;
        unordered_map<int,int>first_seen;
        
        int max=0;
        int ans=0;
        
        for(int i=0; i<nums.size(); i++){
            first_seen.insert({nums[i],i});
            
            occur[nums[i]]++;
            
            if(occur[nums[i]]>max){
                max = occur[nums[i]];
                ans = i-first_seen[nums[i]]+1;
            }
            else if(occur[nums[i]]==max){
                ans = min(ans,i-first_seen[nums[i]]+1);
            }
        }
        return ans;
    }
};