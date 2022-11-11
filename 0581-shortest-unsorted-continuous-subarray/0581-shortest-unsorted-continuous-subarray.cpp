class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        if(nums.size()==1){
            return 0;
        }
        for(int i=0; i<nums.size(); i++){
            if(i==0){
                if(nums[i]>nums[i+1]){
                    mini = min(mini,nums[i]);
                    maxi = max(maxi,nums[i]);
                }
            }
            else if(i==nums.size()-1){
                if(nums[i]<nums[i-1]){
                    mini = min(mini,nums[i]);
                    maxi = max(maxi,nums[i]);
                }
            }
            else{
                if(nums[i]>nums[i+1] || nums[i]<nums[i-1]){
                    mini = min(mini,nums[i]);
                    maxi = max(maxi,nums[i]);
                }
            }
        }
        if(mini == INT_MAX && maxi == INT_MIN)
            return 0;
        
        int i=0;
        int j=0;
        
        for(i=0; i<nums.size() && nums[i]<=mini; i++);
        for(j=nums.size()-1; j>=0 && nums[j]>=maxi; j--);
        
        return j-i+1;
    }
};