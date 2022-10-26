class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<2){
            return false;
        }
        unordered_map<int,int>mp;
        mp[0] = -1;
        long sum=0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
                if(k != 0)
                    sum = sum%k;
            
            if(mp.find(sum) != mp.end()){
                // current index - privous index greater than 1
                if(i-mp[sum]>1)
                    return true;
            }
            else{
                mp[sum] = i;
            } 
        }
        return false;
    }
};