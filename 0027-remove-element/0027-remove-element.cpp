class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        int cnt=0;
        
        for(int j=0; j<nums.size(); j++){
            if(nums[j] != val){
                nums[i++] = nums[j];
                cnt++;
            }
        }
        return cnt;
    }
};