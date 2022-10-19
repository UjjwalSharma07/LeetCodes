class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_set<int>st;
        
        for(int i=0; i<nums.size(); i++){
            if(st.count(nums[i])){
                st.erase(nums[i]);
                continue;
            }
            st.insert(nums[i]);
        }
        if(st.empty())
            return true;
        return false;
    }
};