class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int size = nums.size();
        
        if(size<5)
            return 0;
        
        int a = nums[size-4]-nums[0];
        int b = nums[size-3]-nums[1];
        int c = nums[size-2]-nums[2];
        int d = nums[size-1]-nums[3];
        
        return min({a,b,c,d});
    }
};