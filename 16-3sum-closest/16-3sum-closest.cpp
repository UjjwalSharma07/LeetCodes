class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        int ans =0;
        for(int i=0; i<nums.size()-2; i++){
            
            int s =i+1;
            int e=nums.size()-1;
            
            while(s<e){
                int sum = nums[i]+nums[s]+nums[e];
                
                if(sum == target){
                    return target;
                }
                else if(abs(sum-target)<diff){
                    diff = abs(sum-target);
                    ans = sum;
                }
                if(target<sum)
                    e--;
                else
                    s++;
            }
        }
        return ans;
    }
};