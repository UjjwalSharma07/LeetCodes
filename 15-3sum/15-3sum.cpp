class Solution {
public:
    void ThreeSum(vector<int>&nums,vector<vector<int>>&ans){
        sort(nums.begin(),nums.end());
        set<vector<int>>hash;
        
        for(int i=0; i<nums.size()-2; i++){
            
            int s = i+1;
            int e = nums.size()-1;
            int target = -nums[i];
            while(s<e){
                if(nums[s]+nums[e] == target){
                    hash.insert({-target,nums[s],nums[e]});
                    s++;
                    e--;
                }
                else if(nums[s]+nums[e]<target){
                    s++;
                }
                else
                    e--;
            }
        }
        for(auto k:hash){
            ans.push_back(k);
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        ThreeSum(nums,ans);
        return ans;
    }
};