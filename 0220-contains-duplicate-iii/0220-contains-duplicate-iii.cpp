class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        unordered_set<int>ss(nums.begin(),nums.end());
        if(valueDiff == 0 && ss.size() == nums.size() )
            return false;
        
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<i+1+indexDiff; j++){
                if(j>=nums.size())
                    break;
                if(abs((long long)nums[i]-nums[j]) <= valueDiff)
                    return true;
            }
        }
        return false;
    }
};