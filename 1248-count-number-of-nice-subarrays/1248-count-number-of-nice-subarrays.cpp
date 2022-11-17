class Solution {
public:
    int atMost(vector<int>& nums,int k){
        int i=0;
        int j=0;
        int ans=0;
        int sum=0;
        
        while(j<nums.size()){
            sum+=nums[j];
            
            while(sum>k){
                sum-=nums[i];
                i++;
            }
            ans += j-i+1;
            j++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(auto &num:nums){
            if(num%2)
                num = 1;
            else
                num = 0;
        }
        return atMost(nums,k)-atMost(nums,k-1);
    }
};